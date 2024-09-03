#pragma once
#include "ControlWidget.hpp"
#include "librador.h"
#include "UIComponents.hpp"
#include "util.h"

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

	int TriggerTypeComboCurrentItem = 0;
	float OffsetVal = 0.0f;
	bool ACCoupledCheck = false;
	bool Paused = false;
	bool AutofitNext = false;
	bool Trigger = false;
	float TriggerLevel = 1.5;
	double TriggerHysteresis = 0.25;
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
		ImGui::SameLine();
		ImGui::SetCursorPos(ImVec2(ImGui::GetWindowWidth()-right_column_width,ImGui::GetCursorPosY()));
		ImGui::Text("Trigger");
		ImGui::SameLine();
		ToggleSwitch((label + "Trigger_toggle").c_str(), &Trigger, constants::PRIM_LIGHT);
		ImGui::SameLine(); 
		ImGui::SetNextItemWidth(TriggerTypeComboWidth); ImGui::Combo("##Trigger Type", &TriggerTypeComboCurrentItem, TriggerTypeComboList,
		    IM_ARRAYSIZE(TriggerTypeComboList));
		ImGui::SameLine();
		ImGui::SetNextItemWidth(TriggerLevelSliderWidth);
		ImGui::SliderFloat("##TriggerLevel", &TriggerLevel, -1, 4, "%.2f");
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
		ImGui::Checkbox("Trigger", &Trigger);
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
	int right_column_width = 350;
	float TriggerTypeComboWidth = 100.0;
	float TriggerLevelSliderWidth = 100.0;
	// Drop down content
	const char* TriggerTypeComboList[4]
	    = { "OSC1 Rising Edge", "OSC1 Falling Edge", "OSC2 Rising Edge", "OSC2 Falling Edge" };
	/*const char* KSComboList[2] = { "375 KSPS", "750 KSPS" };
	const char* AttenComboList[3] = { "1x", "5x", "10x" };*/
};

