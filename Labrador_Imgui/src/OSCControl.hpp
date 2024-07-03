#include "ControlWidget.hpp"
#include "librador.h"

/// <summary>Oscilloscope Control Widget
/// </summary>
class OSCControl : public ControlWidget
{
public:
	
	OSCControl(const char* label, ImVec2 size, ImU32 borderColor)
	    : ControlWidget(label, size, borderColor)
	    , voltage(4.5f)
	{}

	/// <summary> 
	/// Render UI elements for oscilloscope control
	/// </summary>
	void renderControl() override
	{
		ImGui::SliderFloat("Voltage", &voltage, 4.5f, 6.0f, "%.1f V");	
	}

	/// <summary>
	/// Control sampling settings on labrador board
	/// </summary>
	void controlLab() override
	{
	}

private:
	float voltage;
};
