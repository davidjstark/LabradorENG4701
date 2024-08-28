#include "ControlWidget.hpp"
#include "librador.h"

/// <summary>Oscilloscope Control Widget
/// </summary>
class PlotControl : public ControlWidget
{
public:
	PlotControl(const char* label, ImVec2 size, ImU32 borderColor)
	    : ControlWidget(label, size, borderColor)
	{
	}

	/// <summary>
	/// Render UI elements for oscilloscope control
	/// </summary>
	void renderControl() override
	{
	}

	/// <summary>
	/// Control sampling settings on labrador board
	/// </summary>
	bool controlLab() override
	{
		return false;
	}

	void renderHelp() override
	{
		ImGui::Text("HELP HERE");
		// Pinout image
		ImGui::Image((void*)constants::osc_pinout_texture,
		    ImVec2(constants::pinout_width, constants::pinout_height));
	}

private:
};