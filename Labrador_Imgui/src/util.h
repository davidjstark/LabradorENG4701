#ifndef UTIL_H
#define UTIL_H

#include "imgui.h"
#define _USE_MATH_DEFINES
#include "math.h"

namespace constants
{
	constexpr ImU32 PRIM_LIGHT = IM_COL32(255, 255, 255, 255); // primary light
	constexpr ImU32 SG1_ACCENT = IM_COL32(42, 39, 212, 255);
    constexpr ImU32 SG2_ACCENT = IM_COL32(203, 100, 4, 255);
    constexpr ImU32 PSU_ACCENT = IM_COL32(190, 54, 54, 255);

    constexpr char* wavetypes[3] = { "Sine", "Square", "Sawtooth" };
    constexpr int PREVIEW_RES = 128;
    extern float x_preview[PREVIEW_RES];
    extern float sine_preview[PREVIEW_RES];
    
    
}

void init_constants();
void PreviewStyle();

#endif