#pragma once
#include "ControlWidget.hpp"
#include "librador.h"
#include "UIComponents.hpp"
//class OscData;

/// <summary>Oscilloscope Control Widget
/// </summary>
class OSCControl : public ControlWidget
{
public:
	// ImGui State variables
	bool DisplayCheckOSC1 = true;
	bool DisplayCheckOSC2 = true;
	/*int KSComboCurrentItem = 0;
	int AttenComboCurrentItem = 0;*/
	float OffsetVal = 0.0f;
	bool ACCoupledCheck = false;
	bool Paused = false;
	bool AutofitNext = false;
	// Public consts
	ImColor OSC1Colour = ImColor(constants::OSC1_ACCENT);
	ImColor OSC2Colour = ImColor(constants::OSC2_ACCENT);
	OSCControl(const char* label, ImVec2 size, ImU32 borderColor)
	    : ControlWidget(label, size, borderColor)
	{
	}
	/// <summary> 
	/// Render UI elements for oscilloscope control
	/// </summary>
	void renderControl() override
	{
		ImGui::Text("Oscilloscope 1 (OSC1)");
		ImGui::SameLine();
		ImGui::Text("   OFF");
		ImGui::SameLine();
		ToggleSwitch((label + "Display1_toggle").c_str(), &DisplayCheckOSC1, ImU32(OSC1Colour));
		ImGui::SameLine();
		ImGui::Text("ON");
		ImGui::Text("Oscilloscope 2 (OSC2)");
		ImGui::SameLine();
		ImGui::Text("   OFF");
		ImGui::SameLine();
		ToggleSwitch((label + "Display2_toggle").c_str(), &DisplayCheckOSC2, ImU32(OSC2Colour));
		ImGui::SameLine();
		ImGui::Text("ON");
		if (ImGui::Button("Autofit"))
		{
			AutofitNext = true;
		}
		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::SetCursorPosX(ImGui::GetWindowWidth()/2);
		PauseButton("Pause", 15, &Paused);
	}

	/// <summary>
	/// Render help message in popup window
	/// </summary>
	void renderHelp() override
	{
		ImGui::Text("HELP HERE");
		// Pinout image
		ImGui::Image((void*)constants::osc_pinout_texture,
		    ImVec2(constants::pinout_width, constants::pinout_height));
	}


	/// <summary>
	/// Control sampling settings on labrador board
	/// </summary>
	bool controlLab() override
	{
		return false;
	}


private:
	// ImGui const data
	const std::string label;
	int channel;
	// Drop down content
	/*const char* KSComboList[2] = { "375 KSPS", "750 KSPS" };
	const char* AttenComboList[3] = { "1x", "5x", "10x" };*/
};

