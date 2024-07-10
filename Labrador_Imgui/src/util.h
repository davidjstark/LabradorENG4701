#ifndef UTIL_H
#define UTIL_H

#include "imgui.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include <string>
#include "implot.h"

class Unit
{
public:
	Unit(const std::string& label, float multiplier)
	    : label(label)
	    , multiplier(multiplier) {}

	std::string getLabel() const
	{
		return label;
	}
	float toSI(float value) const
	{
		return value / multiplier;
	}
	float fromSI(float value) const
	{
		return value * multiplier;
	}

private:
	std::string label;
	float multiplier;
};

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

static Unit Hz_unit("Hz", 1);
static Unit kHz_unit("kHz", 1e3);
static Unit MHz_unit("MHz", 1e6);
constexpr Unit* const freq_units[3] = { &Hz_unit, &kHz_unit, &MHz_unit };

static Unit uV_unit("uV", 1e-6);
static Unit mV_unit("mV", 1e-3);
static Unit V_unit("V", 1);
constexpr Unit* const volt_units[3] = { &uV_unit, &mV_unit, &V_unit };
}

void init_constants();
void PreviewStyle();


#endif