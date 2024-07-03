#include "ControlWidget.hpp"
#include "librador.h"

/// <summary>Signal Generator Widget
/// </summary>
class SGControl : public ControlWidget
{
public:
	
	SGControl(const char* label, ImVec2 size, ImU32 borderColor)
	    : ControlWidget(label, size, borderColor)
	    , voltage(4.5f)
	{}

	/// <summary> 
	/// Render UI elements for Signal Generator
	/// </summary>
	void renderControl() override
	{
		ImGui::SliderFloat("Voltage", &voltage, 4.5f, 6.0f, "%.1f V");	
	}

	/// <summary>
	/// Set the Signal Generator on the labrador board.
	/// </summary>
	void controlLab() override
	{

	}

private:
	float voltage;
};
