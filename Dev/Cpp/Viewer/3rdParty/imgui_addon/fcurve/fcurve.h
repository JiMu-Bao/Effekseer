
#pragma once

#include"imgui.h"

namespace ImGui
{
	enum class ImFCurveInterporationType
	{
		Cubic = 0,
		Linear,
	};

	enum class ImFCurveEdgeType
	{
		Constant = 0,
		Loop = 1,
		LoopInversely = 2,
	};

	bool BeginFCurve(int id, const ImVec2& size, float current, const ImVec2& scale = ImVec2(1,1), float min_value = 1.0f, float max_value = -1.0f);

	void EndFCurve();

	bool StartSelectingAreaFCurve();

	bool AddPointFCurve(ImVec2 v,
		float* keys, float* values,
		float* leftHandleKeys, float* leftHandleValues,
		float* rightHandleKeys, float* rightHandleValues,
		ImFCurveInterporationType* interporations,
		bool* kv_selected, int count, int* newCount);

	bool FCurve(
		int fcurve_id,
		float* keys, float* values,
		float* leftHandleKeys, float* leftHandleValues,
		float* rightHandleKeys, float* rightHandleValues,
		ImFCurveInterporationType* interporations,
		ImFCurveEdgeType startEdge,
		ImFCurveEdgeType endEdge,
		bool* kv_selected,
		int count,
		float defaultValue,
		bool isLocked,
		bool canControl,
		ImU32 col,
		bool selected,
		float v_min,
		float v_max,
		int* newCount,
		bool* newSelected,
		float* movedX,
		float* movedY,
		int* changedType);
}
