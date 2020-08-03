#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//   fxc /Zpc /Tps_3_0 /Emain /Fh ShaderHeader/EffekseerRenderer.Standard_PS.h
//    Shader/standard_renderer_PS.fx
//
//
// Parameters:
//
//   sampler2D Sampler_g_alphaSampler;
//   sampler2D Sampler_g_blendAlphaSampler;
//   sampler2D Sampler_g_blendSampler;
//   sampler2D Sampler_g_blendUVDistortionSampler;
//   sampler2D Sampler_g_sampler;
//   sampler2D Sampler_g_uvDistortionSampler;
//   float4 _186_blendTextureParameter;
//   float4 _186_edgeColor;
//   float4 _186_edgeParameter;
//   float4 _186_emissiveScaling;
//   float4 _186_flipbookParameter;
//   float4 _186_uvDistortionParameter;
//
//
// Registers:
//
//   Name                               Reg   Size
//   ---------------------------------- ----- ----
//   _186_flipbookParameter             c0       1
//   _186_uvDistortionParameter         c1       1
//   _186_blendTextureParameter         c2       1
//   _186_emissiveScaling               c3       1
//   _186_edgeColor                     c4       1
//   _186_edgeParameter                 c5       1
//   Sampler_g_sampler                  s0       1
//   Sampler_g_alphaSampler             s1       1
//   Sampler_g_uvDistortionSampler      s2       1
//   Sampler_g_blendSampler             s3       1
//   Sampler_g_blendAlphaSampler        s4       1
//   Sampler_g_blendUVDistortionSampler s5       1
//

    ps_3_0
    def c6, -1, -2, -3, 0
    def c7, 2, -1, 0, -0
    dcl_texcoord v0
    dcl_texcoord1 v1.xy
    dcl_texcoord5 v2
    dcl_texcoord6 v3
    dcl_texcoord7 v4
    dcl_texcoord8 v5.xy
    dcl_2d s0
    dcl_2d s1
    dcl_2d s2
    dcl_2d s3
    dcl_2d s4
    dcl_2d s5
    texld r0, v2.zwzw, s2
    mad r0.xy, r0, c7.x, c7.y
    mad r0.zw, r0.xyxy, c1.x, v1.xyxy
    texld r1, r0.zwzw, s0
    mul r1, r1, v0
    mad r0.zw, r0.xyxy, c1.x, v4
    texld r2, r0.zwzw, s0
    mov r3.y, c7.y
    add r0.z, r3.y, c0.y
    mad r2, r2, v0, -r1
    mad r2, v5.x, r2, r1
    cmp r2, -r0_abs.z, r2, r1
    cmp r1, -c0.x, r1, r2
    mad r0.xy, r0, c1.x, v2
    texld r0, r0, s1
    mul r0.x, r0.w, r0.x
    mul r0.y, r0.x, r1.w
    max r0.z, v5.y, c7.z
    mad r0.z, r1.w, -r0.x, r0.z
    cmp r2, r0.z, c7.y, c7.w
    texkill r2
    texld r2, v3.zwzw, s5
    mad r0.zw, r2.xyxy, c7.x, c7.y
    mad r2.xy, r0.zwzw, c1.y, v4
    texld r2, r2, s3
    mad r0.zw, r0, c1.y, v3.xyxy
    texld r3, r0.zwzw, s4
    mul r0.z, r3.w, r3.x
    mul r0.z, r0.z, r2.w
    abs r0.w, c2.x
    mul r3.xyz, r0.z, r2
    lrp r4.xyz, r0.z, r2, r1
    mov r5.x, c2.x
    add r5.xyz, r5.x, c6
    mad r6.xyz, r2, r0.z, r1
    mad r2.xyz, r2, -r0.z, r1
    mul r3.xyz, r1, r3
    cmp r1.xyz, -r5_abs.z, r3, r1
    cmp r1.xyz, -r5_abs.y, r2, r1
    cmp r1.xyz, -r5_abs.x, r6, r1
    cmp r1.xyz, -r0.w, r4, r1
    mov r2.y, c5.y
    mul r2.xyz, r2.y, c4
    mad r0.x, r1.w, r0.x, -v5.y
    add r0.x, r0.x, -c5.x
    frc r0.z, -r0.x
    add r0.x, r0.z, r0.x
    mad r1.xyz, r1, c3.x, -r2
    mad oC0.xyz, r0.x, r1, r2
    mov oC0.w, r0.y

// approximately 50 instruction slots used (7 texture, 43 arithmetic)
#endif

const BYTE g_ps30_main[] =
{
      0,   3, 255, 255, 254, 255, 
    185,   0,  67,  84,  65,  66, 
     28,   0,   0,   0, 172,   2, 
      0,   0,   0,   3, 255, 255, 
     12,   0,   0,   0,  28,   0, 
      0,   0,  16,   1,   0,   0, 
    165,   2,   0,   0,  12,   1, 
      0,   0,   3,   0,   1,   0, 
      1,   0,   6,   0,  36,   1, 
      0,   0,   0,   0,   0,   0, 
     52,   1,   0,   0,   3,   0, 
      4,   0,   1,   0,  18,   0, 
     80,   1,   0,   0,   0,   0, 
      0,   0,  96,   1,   0,   0, 
      3,   0,   3,   0,   1,   0, 
     14,   0, 120,   1,   0,   0, 
      0,   0,   0,   0, 136,   1, 
      0,   0,   3,   0,   5,   0, 
      1,   0,  22,   0, 172,   1, 
      0,   0,   0,   0,   0,   0, 
    188,   1,   0,   0,   3,   0, 
      0,   0,   1,   0,   2,   0, 
    208,   1,   0,   0,   0,   0, 
      0,   0, 224,   1,   0,   0, 
      3,   0,   2,   0,   1,   0, 
     10,   0,   0,   2,   0,   0, 
      0,   0,   0,   0,  16,   2, 
      0,   0,   2,   0,   2,   0, 
      1,   0,  10,   0,  44,   2, 
      0,   0,   0,   0,   0,   0, 
     60,   2,   0,   0,   2,   0, 
      4,   0,   1,   0,  18,   0, 
     44,   2,   0,   0,   0,   0, 
      0,   0,  75,   2,   0,   0, 
      2,   0,   5,   0,   1,   0, 
     22,   0,  44,   2,   0,   0, 
      0,   0,   0,   0,  94,   2, 
      0,   0,   2,   0,   3,   0, 
      1,   0,  14,   0,  44,   2, 
      0,   0,   0,   0,   0,   0, 
    115,   2,   0,   0,   2,   0, 
      0,   0,   1,   0,   2,   0, 
     44,   2,   0,   0,   0,   0, 
      0,   0, 138,   2,   0,   0, 
      2,   0,   1,   0,   1,   0, 
      6,   0,  44,   2,   0,   0, 
      0,   0,   0,   0,  83,  97, 
    109, 112, 108, 101, 114,  95, 
    103,  95,  97, 108, 112, 104, 
     97,  83,  97, 109, 112, 108, 
    101, 114,   0, 171,   4,   0, 
     12,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  83,  97, 109, 112, 
    108, 101, 114,  95, 103,  95, 
     98, 108, 101, 110, 100,  65, 
    108, 112, 104,  97,  83,  97, 
    109, 112, 108, 101, 114,   0, 
      4,   0,  12,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  83,  97, 
    109, 112, 108, 101, 114,  95, 
    103,  95,  98, 108, 101, 110, 
    100,  83,  97, 109, 112, 108, 
    101, 114,   0, 171,   4,   0, 
     12,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  83,  97, 109, 112, 
    108, 101, 114,  95, 103,  95, 
     98, 108, 101, 110, 100,  85, 
     86,  68, 105, 115, 116, 111, 
    114, 116, 105, 111, 110,  83, 
     97, 109, 112, 108, 101, 114, 
      0, 171,   4,   0,  12,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     83,  97, 109, 112, 108, 101, 
    114,  95, 103,  95, 115,  97, 
    109, 112, 108, 101, 114,   0, 
    171, 171,   4,   0,  12,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     83,  97, 109, 112, 108, 101, 
    114,  95, 103,  95, 117, 118, 
     68, 105, 115, 116, 111, 114, 
    116, 105, 111, 110,  83,  97, 
    109, 112, 108, 101, 114,   0, 
    171, 171,   4,   0,  12,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     95,  49,  56,  54,  95,  98, 
    108, 101, 110, 100,  84, 101, 
    120, 116, 117, 114, 101,  80, 
     97, 114,  97, 109, 101, 116, 
    101, 114,   0, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  95,  49,  56,  54, 
     95, 101, 100, 103, 101,  67, 
    111, 108, 111, 114,   0,  95, 
     49,  56,  54,  95, 101, 100, 
    103, 101,  80,  97, 114,  97, 
    109, 101, 116, 101, 114,   0, 
     95,  49,  56,  54,  95, 101, 
    109, 105, 115, 115, 105, 118, 
    101,  83,  99,  97, 108, 105, 
    110, 103,   0,  95,  49,  56, 
     54,  95, 102, 108, 105, 112, 
     98, 111, 111, 107,  80,  97, 
    114,  97, 109, 101, 116, 101, 
    114,   0,  95,  49,  56,  54, 
     95, 117, 118,  68, 105, 115, 
    116, 111, 114, 116, 105, 111, 
    110,  80,  97, 114,  97, 109, 
    101, 116, 101, 114,   0, 112, 
    115,  95,  51,  95,  48,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  57, 
     46,  50,  57,  46,  57,  53, 
     50,  46,  51,  49,  49,  49, 
      0, 171, 171, 171,  81,   0, 
      0,   5,   6,   0,  15, 160, 
      0,   0, 128, 191,   0,   0, 
      0, 192,   0,   0,  64, 192, 
      0,   0,   0,   0,  81,   0, 
      0,   5,   7,   0,  15, 160, 
      0,   0,   0,  64,   0,   0, 
    128, 191,   0,   0,   0,   0, 
      0,   0,   0, 128,  31,   0, 
      0,   2,   5,   0,   0, 128, 
      0,   0,  15, 144,  31,   0, 
      0,   2,   5,   0,   1, 128, 
      1,   0,   3, 144,  31,   0, 
      0,   2,   5,   0,   5, 128, 
      2,   0,  15, 144,  31,   0, 
      0,   2,   5,   0,   6, 128, 
      3,   0,  15, 144,  31,   0, 
      0,   2,   5,   0,   7, 128, 
      4,   0,  15, 144,  31,   0, 
      0,   2,   5,   0,   8, 128, 
      5,   0,   3, 144,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      0,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      1,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      2,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      3,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      4,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      5,   8,  15, 160,  66,   0, 
      0,   3,   0,   0,  15, 128, 
      2,   0, 238, 144,   2,   8, 
    228, 160,   4,   0,   0,   4, 
      0,   0,   3, 128,   0,   0, 
    228, 128,   7,   0,   0, 160, 
      7,   0,  85, 160,   4,   0, 
      0,   4,   0,   0,  12, 128, 
      0,   0,  68, 128,   1,   0, 
      0, 160,   1,   0,  68, 144, 
     66,   0,   0,   3,   1,   0, 
     15, 128,   0,   0, 238, 128, 
      0,   8, 228, 160,   5,   0, 
      0,   3,   1,   0,  15, 128, 
      1,   0, 228, 128,   0,   0, 
    228, 144,   4,   0,   0,   4, 
      0,   0,  12, 128,   0,   0, 
     68, 128,   1,   0,   0, 160, 
      4,   0, 228, 144,  66,   0, 
      0,   3,   2,   0,  15, 128, 
      0,   0, 238, 128,   0,   8, 
    228, 160,   1,   0,   0,   2, 
      3,   0,   2, 128,   7,   0, 
     85, 160,   2,   0,   0,   3, 
      0,   0,   4, 128,   3,   0, 
     85, 128,   0,   0,  85, 160, 
      4,   0,   0,   4,   2,   0, 
     15, 128,   2,   0, 228, 128, 
      0,   0, 228, 144,   1,   0, 
    228, 129,   4,   0,   0,   4, 
      2,   0,  15, 128,   5,   0, 
      0, 144,   2,   0, 228, 128, 
      1,   0, 228, 128,  88,   0, 
      0,   4,   2,   0,  15, 128, 
      0,   0, 170, 140,   2,   0, 
    228, 128,   1,   0, 228, 128, 
     88,   0,   0,   4,   1,   0, 
     15, 128,   0,   0,   0, 161, 
      1,   0, 228, 128,   2,   0, 
    228, 128,   4,   0,   0,   4, 
      0,   0,   3, 128,   0,   0, 
    228, 128,   1,   0,   0, 160, 
      2,   0, 228, 144,  66,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 128,   1,   8, 
    228, 160,   5,   0,   0,   3, 
      0,   0,   1, 128,   0,   0, 
    255, 128,   0,   0,   0, 128, 
      5,   0,   0,   3,   0,   0, 
      2, 128,   0,   0,   0, 128, 
      1,   0, 255, 128,  11,   0, 
      0,   3,   0,   0,   4, 128, 
      5,   0,  85, 144,   7,   0, 
    170, 160,   4,   0,   0,   4, 
      0,   0,   4, 128,   1,   0, 
    255, 128,   0,   0,   0, 129, 
      0,   0, 170, 128,  88,   0, 
      0,   4,   2,   0,  15, 128, 
      0,   0, 170, 128,   7,   0, 
     85, 160,   7,   0, 255, 160, 
     65,   0,   0,   1,   2,   0, 
     15, 128,  66,   0,   0,   3, 
      2,   0,  15, 128,   3,   0, 
    238, 144,   5,   8, 228, 160, 
      4,   0,   0,   4,   0,   0, 
     12, 128,   2,   0,  68, 128, 
      7,   0,   0, 160,   7,   0, 
     85, 160,   4,   0,   0,   4, 
      2,   0,   3, 128,   0,   0, 
    238, 128,   1,   0,  85, 160, 
      4,   0, 228, 144,  66,   0, 
      0,   3,   2,   0,  15, 128, 
      2,   0, 228, 128,   3,   8, 
    228, 160,   4,   0,   0,   4, 
      0,   0,  12, 128,   0,   0, 
    228, 128,   1,   0,  85, 160, 
      3,   0,  68, 144,  66,   0, 
      0,   3,   3,   0,  15, 128, 
      0,   0, 238, 128,   4,   8, 
    228, 160,   5,   0,   0,   3, 
      0,   0,   4, 128,   3,   0, 
    255, 128,   3,   0,   0, 128, 
      5,   0,   0,   3,   0,   0, 
      4, 128,   0,   0, 170, 128, 
      2,   0, 255, 128,  35,   0, 
      0,   2,   0,   0,   8, 128, 
      2,   0,   0, 160,   5,   0, 
      0,   3,   3,   0,   7, 128, 
      0,   0, 170, 128,   2,   0, 
    228, 128,  18,   0,   0,   4, 
      4,   0,   7, 128,   0,   0, 
    170, 128,   2,   0, 228, 128, 
      1,   0, 228, 128,   1,   0, 
      0,   2,   5,   0,   1, 128, 
      2,   0,   0, 160,   2,   0, 
      0,   3,   5,   0,   7, 128, 
      5,   0,   0, 128,   6,   0, 
    228, 160,   4,   0,   0,   4, 
      6,   0,   7, 128,   2,   0, 
    228, 128,   0,   0, 170, 128, 
      1,   0, 228, 128,   4,   0, 
      0,   4,   2,   0,   7, 128, 
      2,   0, 228, 128,   0,   0, 
    170, 129,   1,   0, 228, 128, 
      5,   0,   0,   3,   3,   0, 
      7, 128,   1,   0, 228, 128, 
      3,   0, 228, 128,  88,   0, 
      0,   4,   1,   0,   7, 128, 
      5,   0, 170, 140,   3,   0, 
    228, 128,   1,   0, 228, 128, 
     88,   0,   0,   4,   1,   0, 
      7, 128,   5,   0,  85, 140, 
      2,   0, 228, 128,   1,   0, 
    228, 128,  88,   0,   0,   4, 
      1,   0,   7, 128,   5,   0, 
      0, 140,   6,   0, 228, 128, 
      1,   0, 228, 128,  88,   0, 
      0,   4,   1,   0,   7, 128, 
      0,   0, 255, 129,   4,   0, 
    228, 128,   1,   0, 228, 128, 
      1,   0,   0,   2,   2,   0, 
      2, 128,   5,   0,  85, 160, 
      5,   0,   0,   3,   2,   0, 
      7, 128,   2,   0,  85, 128, 
      4,   0, 228, 160,   4,   0, 
      0,   4,   0,   0,   1, 128, 
      1,   0, 255, 128,   0,   0, 
      0, 128,   5,   0,  85, 145, 
      2,   0,   0,   3,   0,   0, 
      1, 128,   0,   0,   0, 128, 
      5,   0,   0, 161,  19,   0, 
      0,   2,   0,   0,   4, 128, 
      0,   0,   0, 129,   2,   0, 
      0,   3,   0,   0,   1, 128, 
      0,   0, 170, 128,   0,   0, 
      0, 128,   4,   0,   0,   4, 
      1,   0,   7, 128,   1,   0, 
    228, 128,   3,   0,   0, 160, 
      2,   0, 228, 129,   4,   0, 
      0,   4,   0,   8,   7, 128, 
      0,   0,   0, 128,   1,   0, 
    228, 128,   2,   0, 228, 128, 
      1,   0,   0,   2,   0,   8, 
      8, 128,   0,   0,  85, 128, 
    255, 255,   0,   0
};
