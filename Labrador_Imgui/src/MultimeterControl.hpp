#include "ControlWidget.hpp"
#include "librador.h"

/// <summary>Multimeter Widget
/// </summary>
class MultimeterControl : public ControlWidget
{
public:
	
	MultimeterControl(const char* label, ImVec2 size, ImU32 borderColor)
	    : ControlWidget(label, size, borderColor)
	    , voltage(4.5f)
	{}

	/// <summary> 
	/// Render UI elements for multimeter
	/// </summary>
	void renderControl() override
	{
		ImGui::SliderFloat("Voltage", &voltage, 4.5f, 6.0f, "%.1f V");	
	}

	/// <summary>
	/// Read multimeter from labrador board
	/// </summary>
	void controlLab() override
	{
		
	}

private:
	float voltage;
};
