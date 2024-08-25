#include "ControlWidget.hpp"
#include "librador.h"
#include "util.h"

/// <summary>Power Suppy Unit Widget
/// </summary>
class PSUControl : public ControlWidget
{
public:
	
	PSUControl(std::string label, ImVec2 size, ImU32 borderColor)
	    : ControlWidget(label, size, borderColor)
	    , voltage(4.5f)
	{}

	/// <summary> 
	/// Render UI elements for power supply unit
	/// </summary>
	void renderControl() override
	{
		ImGui::Dummy(ImVec2(0.0f, 5.0f));
		ImGui::Text("Voltage");
		ImGui::SameLine();
		ImGui::SliderFloat("##voltage", &voltage, 4.5f, 6.0f, "%.1f V");	
	}

	/// <summary>
	/// Render help message in popup window
	/// </summary>
	void renderHelp() override
	{
		ImGui::Text("HELP HERE");
		// Pinout image
		ImGui::Image((void*)constants::psu_pinout_texture,
		    ImVec2(constants::pinout_width, constants::pinout_height));
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
		// printf("Successfully set power supply voltage to %.2fV\n", voltage);
	}

private:
	float voltage;
};
