﻿
#ifndef	__EFFEKSEERRENDERER_STANDARD_RENDERER_BASE_H__
#define	__EFFEKSEERRENDERER_STANDARD_RENDERER_BASE_H__

//----------------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------------
#include <Effekseer.h>
#include <vector>

#include "EffekseerRenderer.CommonUtils.h"
#include "EffekseerRenderer.VertexBufferBase.h"

//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
namespace EffekseerRenderer
{
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------

struct StandardRendererState
{
	bool								DepthTest;
	bool								DepthWrite;
	bool								Distortion;
	float								DistortionIntensity;
	bool								Wireframe;

	::Effekseer::AlphaBlendType			AlphaBlend;
	::Effekseer::CullingType			CullingType;
	::Effekseer::TextureFilterType		TextureFilterType;
	::Effekseer::TextureWrapType		TextureWrapType;
	::Effekseer::TextureData*			TexturePtr;

	StandardRendererState()
	{
		DepthTest = false;
		DepthWrite = false;
		Distortion = false;
		DistortionIntensity = 1.0f;
		Wireframe = true;

		AlphaBlend = ::Effekseer::AlphaBlendType::Blend;
		CullingType = ::Effekseer::CullingType::Front;
		TextureFilterType = ::Effekseer::TextureFilterType::Nearest;
		TextureWrapType = ::Effekseer::TextureWrapType::Repeat;
		TexturePtr = nullptr;
	}

	bool operator != (const StandardRendererState state)
	{
		if (DepthTest != state.DepthTest) return true;
		if (DepthWrite != state.DepthWrite) return true;
		if (Distortion != state.Distortion) return true;
		if (DistortionIntensity != state.DistortionIntensity) return true;
		if (AlphaBlend != state.AlphaBlend) return true;
		if (CullingType != state.CullingType) return true;
		if (TextureFilterType != state.TextureFilterType) return true;
		if (TextureWrapType != state.TextureWrapType) return true;
		if (TexturePtr != state.TexturePtr) return true;
		return false;
	}
};

template<typename RENDERER, typename SHADER, typename VERTEX, typename VERTEX_DISTORTION>
class StandardRenderer
{

private:
	RENDERER*	m_renderer;
	SHADER*		m_shader;
	SHADER*		m_shader_no_texture;

	SHADER*		m_shader_distortion;
	SHADER*		m_shader_no_texture_distortion;

	Effekseer::TextureData*		m_texture;

	StandardRendererState		m_state;

	std::vector<uint8_t>		vertexCaches;
	int32_t						vertexCacheMaxSize;

	std::vector<uint8_t>		indexCaches;
	int32_t						indexCacheMaxSize;

	bool						m_isDistortionMode;
public:

	StandardRenderer(RENDERER* renderer, SHADER* shader, SHADER* shader_no_texture, SHADER* shader_distortion, SHADER* shader_no_texture_distortion)
		: vertexCacheMaxSize(0)
		, m_isDistortionMode(false)
	{
		m_renderer = renderer;
		m_shader = shader;
		m_shader_no_texture = shader_no_texture;
		m_shader_distortion = shader_distortion;
		m_shader_no_texture_distortion = shader_no_texture_distortion;

		vertexCaches.reserve(m_renderer->GetVertexBuffer()->GetMaxSize());
		vertexCacheMaxSize = m_renderer->GetVertexBuffer()->GetMaxSize();

		indexCaches.reserve(m_renderer->GetIndexBuffer()->GetMaxCount() * sizeof(int16_t));
		indexCacheMaxSize = m_renderer->GetIndexBuffer()->GetMaxCount() * sizeof(int16_t);

	}

	void UpdateStateAndRenderingIfRequired(StandardRendererState state)
	{
		if(m_state != state)
		{
			Rendering();
		}

		m_state = state;

		m_isDistortionMode = m_state.Distortion;
	}

	void BeginRenderingAndRenderingIfRequired(int32_t count, int32_t& offset, void*& data, int32_t indexCount, int32_t& indexOffset, void*& indexData)
	{
		if (m_isDistortionMode)
		{
			if (count * sizeof(VERTEX_DISTORTION) + vertexCaches.size() > vertexCacheMaxSize ||
				indexCount * sizeof(uint16_t) + indexCaches.size() > indexCacheMaxSize)
			{
				Rendering();
			}

			auto old = vertexCaches.size();
			vertexCaches.resize(count * sizeof(VERTEX_DISTORTION) + vertexCaches.size());
			offset = old;
			data = (vertexCaches.data() + old);
		}
		else
		{
			if (count * sizeof(VERTEX) + vertexCaches.size() > vertexCacheMaxSize ||
				indexCount * sizeof(uint16_t) + indexCaches.size() > indexCacheMaxSize)
			{
				Rendering();
			}

			auto old = vertexCaches.size();
			vertexCaches.resize(count * sizeof(VERTEX) + vertexCaches.size());
			offset = old;
			data = (vertexCaches.data() + old);
		}

		{
			auto old = indexCaches.size();
			indexCaches.resize(indexCount * sizeof(uint16_t) + indexCaches.size());
			indexOffset = old;
			indexData = (indexCaches.data() + old);
		}
	}

	void ResetAndRenderingIfRequired()
	{
		Rendering();

		// It is always initialized with the next drawing.
		m_state.TexturePtr = (Effekseer::TextureData*)0x1;
	}

	void Rendering(const Effekseer::Matrix44& mCamera, const Effekseer::Matrix44& mProj)
	{
		if (vertexCaches.size() == 0) return;

		if (m_state.Distortion)
		{
			auto callback = m_renderer->GetDistortingCallback();
			if (callback != nullptr)
			{
				if (!callback->OnDistorting())
				{
					vertexCaches.clear();
					return;
				}
			}
		}

		if (m_state.Distortion && m_renderer->GetBackground() == 0)
		{
			vertexCaches.clear();
			return;
		}

		// Send vertex
		int32_t vertexSize = vertexCaches.size();
		int32_t vertexOffsetSize = 0;
		{
			VertexBufferBase* vb = m_renderer->GetVertexBuffer();

			void* data = nullptr;

			if (m_state.Distortion)
			{
				// For OpenGL ES(Because OpenGL ES 3.2 and later can only realize a vertex layout variable ring buffer)
				vb->Lock();
				data = vb->GetBufferDirect(vertexCaches.size());
				if (data == nullptr)
				{
					vertexCaches.clear();
					return;
				}
				memcpy(data, vertexCaches.data(), vertexCaches.size());
				vb->Unlock();
			}
			else if (vb->RingBufferLock(vertexCaches.size(), vertexOffsetSize, data))
			{
				assert(data != nullptr);
				memcpy(data, vertexCaches.data(), vertexCaches.size());
				vb->Unlock();
			}
			else
			{
				vertexCaches.clear();
				indexCaches.clear();
				return;
			}

			vertexCaches.clear();
		}

		// Send index
		int32_t indexSize = indexCaches.size();
		int32_t indexOffsetSize = 0;
		{
			IndexBufferBase* ib = m_renderer->GetIndexBuffer();

			void* data = nullptr;

			if (ib->RingBufferLock(indexCaches.size(), indexOffsetSize, data))
			{
				assert(data != nullptr);

				// shift
				int32_t indexOffset = 0;
				if (m_state.Distortion)
				{
					indexOffset = vertexOffsetSize / sizeof(VERTEX_DISTORTION);
				}
				else
				{
					indexOffset = vertexOffsetSize / sizeof(VERTEX);
				}
				
				for (int32_t i = 0; i < indexCaches.size() / 2; i++)
				{
					((uint16_t*)indexCaches.data())[i] += indexOffset;
				}

				memcpy(data, indexCaches.data(), indexCaches.size());
				ib->Unlock();
			}
			else
			{
				vertexCaches.clear();
				indexCaches.clear();
				return;
			}

			indexCaches.clear();
		}

		RenderStateBase::State& state = m_renderer->GetRenderState()->Push();
		state.DepthTest = m_state.DepthTest;
		state.DepthWrite = m_state.DepthWrite;
		state.CullingType = m_state.CullingType;
		state.AlphaBlend = m_state.AlphaBlend;

		SHADER* shader_ = nullptr;

		bool distortion = m_state.Distortion;

		shader_ = m_renderer->GetShader(m_state.TexturePtr != nullptr, distortion);

		m_renderer->BeginShader(shader_);

		Effekseer::TextureData* textures[2];

		if (m_state.TexturePtr != nullptr && m_state.TexturePtr != (Effekseer::TextureData*)0x01)
		{
			textures[0] = m_state.TexturePtr;
		}
		else
		{
			textures[0] = nullptr;
		}

		if (distortion)
		{
			textures[1] = m_renderer->GetBackground();
			m_renderer->SetTextures(shader_, textures, 2);
		}
		else
		{
			m_renderer->SetTextures(shader_, textures, 1);
		}

		Effekseer::Matrix44 constantVSBuffer[2];
		constantVSBuffer[0] = mCamera;
		constantVSBuffer[1] = mProj;
		m_renderer->SetVertexBufferToShader(constantVSBuffer, sizeof(Effekseer::Matrix44) * 2);

		if (distortion)
		{
			float constantPSBuffer[1];
			constantPSBuffer[0] = m_state.DistortionIntensity;

			m_renderer->SetPixelBufferToShader(constantPSBuffer, sizeof(float));
		}

		shader_->SetConstantBuffer();

		state.TextureFilterTypes[0] = m_state.TextureFilterType;
		state.TextureWrapTypes[0] = m_state.TextureWrapType;

		m_renderer->GetRenderState()->Update(distortion);

		if (distortion)
		{
			m_renderer->SetVertexBuffer(m_renderer->GetVertexBuffer(), sizeof(VERTEX_DISTORTION));
			m_renderer->SetIndexBuffer(m_renderer->GetIndexBuffer());
			m_renderer->SetLayout(shader_);
			m_renderer->DrawSprites(vertexSize / sizeof(VERTEX_DISTORTION) / 4, vertexOffsetSize / sizeof(VERTEX_DISTORTION));
		}
		else
		{
			int32_t spriteCount = indexSize / 6 / 2;
			m_renderer->SetVertexBuffer(m_renderer->GetVertexBuffer(), sizeof(VERTEX));
			m_renderer->SetIndexBuffer(m_renderer->GetIndexBuffer());
			m_renderer->SetLayout(shader_);
			m_renderer->DrawSprites(spriteCount, indexOffsetSize);
		}

		m_renderer->EndShader(shader_);

		m_renderer->GetRenderState()->Pop();
	}

	void Rendering()
	{
		Rendering(m_renderer->GetCameraMatrix(), m_renderer->GetProjectionMatrix());
	}
};

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
}
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
#endif	// __EFFEKSEERRENDERER_STANDARD_RENDERER_H__