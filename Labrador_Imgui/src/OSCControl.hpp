#include "ControlWidget.hpp"
#include "librador.h"

/// <summary>Oscilloscope Control Widget
/// </summary>
class OSCControl : public ControlWidget
{
public:
	// ImGui State variables
	bool DisplayCheck = true;
	int KSComboCurrentItem = 0;
	int AttenComboCurrentItem = 0;
	float SliderVal = 0.0f;
	bool ACCoupledCheck = false;
	OSCControl(const char* label, ImVec2 size, ImU32 borderColor)
	    : ControlWidget(label, size, borderColor)
	{}

	/// <summary> 
	/// Render UI elements for oscilloscope control
	/// </summary>
	void renderControl() override
	{
		ImGui::Text("Display");
	}

	/// <summary>
	/// Control sampling settings on labrador board
	/// </summary>
	void controlLab() override
	{
	}

private:
	// ImGui const data
	// Drop down content
	const char* KSComboList[2] = { "375 KSPS", "750 KSPS" };
	const char* AttenComboList[3] = { "1x", "5x", "10x" };
};
