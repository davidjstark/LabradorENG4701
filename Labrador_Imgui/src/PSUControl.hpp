#include "ControlWidget.hpp"
#include "librador.h"

/// <summary>Power Suppy Unit Widget
/// </summary>
class PSUControl : public ControlWidget
{
public:
	
	PSUControl(const char* label, ImVec2 size, ImU32 borderColor)
	    : ControlWidget(label, size, borderColor)
	    , voltage(4.5f)
	{}

	/// <summary> 
	/// Render UI elements for power supply unit
	/// </summary>
	void renderControl() override
	{
		ImGui::SliderFloat("Voltage", &voltage, 4.5f, 6.0f, "%.1f V");	
	}

	/// <summary>
	/// Set the Power Supply Voltage on the labrador board.
	/// </summary>
	void controlLab() override
	{
		int error = librador_set_power_supply_voltage(voltage);
		if (error)
		{
			printf("librador_set_power_supply_voltage FAILED with error code "
				    "%d\tExiting...",
				error);
			std::exit(error);
		}
		printf("Successfully set power supply voltage to %.2fV\n", voltage);
	}

private:
	float voltage;
};
