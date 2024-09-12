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
	float TriggerHysteresis = 0.25;
	float osc1_time_scale = 5;
	float osc1_voltage_scale = 1;
	float osc1_offset = 0;
	float osc2_time_scale = 5;
	float osc2_voltage_scale = 1;
	float osc2_offset = 0;
	int osc1_ts_unit_idx = 1;
	int osc1_vs_unit_idx = 2;
	int osc1_os_unit_idx = 1;
	int osc2_ts_unit_idx = 1;
	int osc2_vs_unit_idx = 2;
	int osc2_os_unit_idx = 1;
	int tl_unit_idx = 1;
	int th_unit_idx = 1;
	bool ts_equalise = false;
	bool vs_equalise = false;
	bool os_equalise = false;
	bool Cursor1toggle = false;
	bool Cursor2toggle = false;
	bool AutoTriggerLevelToggle = true;
	bool AutoTriggerHysteresisToggle = true;
	bool HysteresisDisplayOptionEnabled = false;

	// Public consts
	ImColor OSC1Colour = colourConvert(constants::OSC1_ACCENT);
	ImColor OSC2Colour = colourConvert(constants::OSC2_ACCENT);
	ImColor GenColour = colourConvert(constants::GEN_ACCENT);
	ImColor Green = ImColor(float(20./255), float(143./255), float(0), float(1));
	ImColor Red = ImColor(float(143./255), float(0. / 255), float(0), float(1));

	OSCControl(const char* label, ImVec2 size, const float* borderColor)
	    : ControlWidget(label, size, borderColor)
	{
	}
	/// <summary> 
	/// Render UI elements for oscilloscope control
	/// </summary>
	void renderControl() override
	{
		if (ImGui::BeginTable("Buttons", 4))
		{
			ImGui::TableNextColumn();
			ToggleButton("Run/Stop", ImVec2(100,30), & Paused, Red, Green);
			ImGui::TableNextColumn();
			ImGui::Button("Auto", ImVec2(100, 30));
			ImGui::TableNextColumn();
			ImGui::Button("Normal", ImVec2(100, 30));
			ImGui::TableNextColumn();
			ImGui::Button("Single", ImVec2(100, 30));
			ImGui::EndTable();
		}
		if (ImGui::CollapsingHeader("Channels", ImGuiTreeNodeFlags_DefaultOpen))
		{
			if (ImGui::BeginTable("ChannelsTable", 4))
			{
				ImGui::TableNextColumn();
				ImGui::TableNextColumn();
				ImGui::Text("Channel 1 (OSC1)");
				ImGui::TableNextColumn();
				ImGui::Text("Channel 2 (OSC2)");
				ImGui::TableNextColumn();
				ImGui::Text("Equalise");
				ImGui::TableNextColumn();
				ImGui::Text("Display");
				ImGui::TableNextColumn();
				ImGui::Text("   OFF");
				ImGui::SameLine();
				ToggleSwitch((label + "Display1_toggle").c_str(), &DisplayCheckOSC1,
				    ImU32(OSC1Colour));
				ImGui::SameLine();
				ImGui::Text("ON");
				ImGui::TableNextColumn();
				ImGui::Text("   OFF");
				ImGui::SameLine();
				ToggleSwitch((label + "Display2_toggle").c_str(), &DisplayCheckOSC2,
				    ImU32(OSC2Colour));
				ImGui::SameLine();
				ImGui::Text("ON");
				ImGui::TableNextColumn();
				ImGui::TableNextColumn();
				ImGui::Text("Time Scale");
				ImGui::TableNextColumn();
				renderSliderwUnits(label+"_ts1",&osc1_time_scale,1,1000,"%.2f",constants::time_units,&osc1_ts_unit_idx);
				ImGui::TableNextColumn();
				renderSliderwUnits(label + "_ts2", &osc2_time_scale, 1, 1000, "%.2f",
				    constants::time_units, &osc2_ts_unit_idx);
				ImGui::TableNextColumn();
				ImGui::Checkbox("##Equalise", &ts_equalise);
				ImGui::TableNextColumn();
				ImGui::Text("Voltage Scale");
				ImGui::TableNextColumn();
				renderSliderwUnits(label + "_vs1", &osc1_voltage_scale, 1, 1000, "%.2f",
				    constants::volt_units, &osc1_vs_unit_idx);
				ImGui::TableNextColumn();
				renderSliderwUnits(label + "_vs2", &osc2_voltage_scale, 1, 1000, "%.2f",
				    constants::volt_units, &osc2_vs_unit_idx);
				ImGui::TableNextColumn();
				ImGui::Checkbox("##Equalise", &vs_equalise);
				ImGui::TableNextColumn();
				ImGui::Text("Offset");
				ImGui::TableNextColumn();
				renderSliderwUnits(label + "_os1", &osc1_offset, 1, 1000, "%.2f",
				    constants::time_units, &osc1_os_unit_idx);
				ImGui::TableNextColumn();
				renderSliderwUnits(label + "_os2", &osc2_offset, 1, 1000, "%.2f",
				    constants::time_units, &osc2_os_unit_idx);
				ImGui::TableNextColumn();
				ImGui::Checkbox("##Equalise", &os_equalise);
				ImGui::EndTable();
			}	
		}
		if (ImGui::CollapsingHeader("General", ImGuiTreeNodeFlags_DefaultOpen))
		{
			if (ImGui::BeginTable("GeneralTable", 4))
			{
				ImGui::TableNextColumn();
				ImGui::Text("Cursor 1");
				ImGui::TableNextColumn();
				ImGui::Text("OFF");
				ImGui::SameLine();
				ToggleSwitch((label + "Cursor1_toggle").c_str(), &Cursor1toggle, GenColour);
				ImGui::SameLine();
				ImGui::Text("ON");
				ImGui::TableNextColumn();
				ImGui::Text("Cursor 2");
				ImGui::TableNextColumn();
				ImGui::Text("OFF");
				ImGui::SameLine();
				ToggleSwitch((label + "Cursor2_toggle").c_str(), &Cursor2toggle, GenColour);
				ImGui::SameLine();
				ImGui::Text("ON");
				ImGui::TableNextColumn();
				ImGui::Text("Trigger");
				ImGui::SameLine();
				ToggleSwitch((label + "Trigger_toggle").c_str(), &Trigger, GenColour);
				ImGui::TableNextColumn();
				ImGui::SetNextItemWidth(TriggerTypeComboWidth);
				ImGui::Combo("##Trigger Type", &TriggerTypeComboCurrentItem,
				    TriggerTypeComboList, IM_ARRAYSIZE(TriggerTypeComboList));
				ImGui::TableNextColumn();
				ImGui::Text("Level");
				ImGui::SameLine();
				renderSliderwUnits(label + "_trigger_level", &TriggerLevel, 0, 3, "%.0f",
				    constants::volt_units, &tl_unit_idx);
				ImGui::TableNextColumn();
				ImGui::Text("Auto");
				ImGui::SameLine();
				ImGui::Text("ON");
				ImGui::SameLine();
				ToggleSwitch((label + "Auto_trigger_level_toggle").c_str(),
				    &AutoTriggerLevelToggle, GenColour);
				ImGui::SameLine();
				ImGui::Text("OFF");
				if (HysteresisDisplayOptionEnabled)
				{
					ImGui::Text("Hysteresis Level");
					ImGui::TableNextColumn();
					renderSliderwUnits(label + "_trigger_hysteresis", &TriggerHysteresis, 0, 2, "%.0f",
					    constants::volt_units, &tl_unit_idx);
					ImGui::Text("Auto");
					ImGui::SameLine();
					ImGui::Text("ON");
					ImGui::SameLine();
					ToggleSwitch((label + "Auto_trigger_hysteresis_toggle").c_str(),
					    &AutoTriggerHysteresisToggle, GenColour);
					ImGui::SameLine();
					ImGui::Text("OFF");
				}
				ImGui::EndTable();
			}
		}




		if (ImGui::Button("Autofit"))
		{
			AutofitNext = true;
		}
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

