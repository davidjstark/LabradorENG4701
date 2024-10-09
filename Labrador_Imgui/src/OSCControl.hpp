#pragma once
#include "ControlWidget.hpp"
#include "librador.h"
#include "UIComponents.hpp"
#include "util.h"
#include "nfd.h"
#include <cstring>
#include <cstddef>

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
	// Export stuff
	nfdchar_t* OSC1WritePath = NULL;
	nfdchar_t* OSC2WritePath = NULL;
	int OSC1WritePathComboCurrentItem = 0;
	int OSC2WritePathComboCurrentItem = 0;
	bool OSC1ClipboardCopyNext = false;
	bool OSC2ClipboardCopyNext = false;
	bool OSC1ClipboardCopied = false;
	bool OSC2ClipboardCopied = false;
	nfdchar_t* FileExtension = "csv";
	//
	float OffsetVal = 0.0f;
	bool ACCoupledCheck = false;
	bool Paused = false;
	bool AutofitY = false;
	bool AutofitX = false;
	int Trigger1TypeComboCurrentItem = 0;
	bool Trigger1 = true;
	SIValue Trigger1Level = SIValue("##trigger1_level", "Level", 3.3 / 2, -20.0, 20.0, "V", constants::volt_prefs, constants::volt_formats);
	bool AutoTrigger1Level = true;
	float Trigger1Hysteresis = 0.25;
	int Trigger2TypeComboCurrentItem = 0;
	bool Trigger2 = true;
	SIValue Trigger2Level = SIValue("##trigger2_level", "Level", 3.3 / 2, -20.0, 20.0, "V", constants::volt_prefs, constants::volt_formats);
	bool AutoTrigger2Level = true;
	float Trigger2Hysteresis = 0.25;
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
	bool SignalPropertiesToggle = false;
	bool AutoTrigger1HysteresisToggle = true;
	bool Hysteresis1DisplayOptionEnabled = false;
	bool AutoTrigger2HysteresisToggle = true;
	bool Hysteresis2DisplayOptionEnabled = false;

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
		if (ImGui::BeginTable("Buttons", 3))
		{
			float button_width = 100;
			ImGui::TableNextColumn();
			ToggleButton("Run/Stop", ImVec2(button_width,30), & Paused, Red, Green);
			ImGui::TableNextColumn();
			//// TODO: Implement Single Capture (Stop after one trigger event is found)
			//ImGui::Button("Single", ImVec2(120, 30));
			//ImGui::TableNextColumn();
			AutofitY = WhiteOutlineButton("Auto Fit  \u2195", ImVec2(button_width, 30));
			ImGui::TableNextColumn();
			AutofitX = WhiteOutlineButton("Auto Fit  \u2194", ImVec2(button_width, 30));
			ImGui::EndTable();
		}

		const float width = ImGui::GetContentRegionAvail().x * 0.95;
		float labWidth = 120.0f;
		float controlWidth = (width - 2*labWidth) / 2;

		ImGui::SeparatorText("Display");
		if (ImGui::BeginTable("ChannelsTable", 4))
		{
			ImGui::TableSetupColumn("One", ImGuiTableColumnFlags_WidthFixed, labWidth);
			ImGui::TableSetupColumn("Two", ImGuiTableColumnFlags_WidthFixed, controlWidth);
			ImGui::TableSetupColumn("Three", ImGuiTableColumnFlags_WidthFixed, labWidth);
			ImGui::TableSetupColumn("Four", ImGuiTableColumnFlags_WidthFixed, controlWidth);

			// Channel 1 Toggle
			ImGui::TableNextColumn();
			ImGui::Text("Channel 1 (OSC1)");
			ImGui::TableNextColumn();
			ToggleSwitch((label + "Display1_toggle").c_str(), &DisplayCheckOSC1,
				ImU32(OSC1Colour));

			// Channel 2 Toggle
			ImGui::TableNextColumn();
			ImGui::Text("Channel 2 (OSC2)");
			ImGui::TableNextColumn();
			ToggleSwitch((label + "Display2_toggle").c_str(), &DisplayCheckOSC2,
				ImU32(OSC2Colour));

			// Cursor 1 Toggle
			ImGui::TableNextColumn();
			ImGui::Text("Cursor 1");
			ImGui::TableNextColumn();
			ToggleSwitch((label + "Cursor1_toggle").c_str(), &Cursor1toggle, GenColour);

			// Cursor 2 Toggle
			ImGui::TableNextColumn();
			ImGui::Text("Cursor 2");
			ImGui::TableNextColumn();
			ToggleSwitch((label + "Cursor2_toggle").c_str(), &Cursor2toggle, GenColour);

			// Signal Properties Toggle
			ImGui::TableNextColumn();
			ImGui::Text("Signal Properties");
			ImGui::TableNextColumn();
			ToggleSwitch(
			    (label + "sig_prop_toggle").c_str(), &SignalPropertiesToggle, GenColour);

			ImGui::EndTable();
		}

		labWidth = 100.0f;
		float labWidth2 = 70.0f;
		controlWidth = (width - labWidth - labWidth2) / 2;

		// Vertical space
		ImGui::Dummy(ImVec2(0, 10.0f));
		ImGui::SeparatorText("General");
		if (ImGui::BeginTable("GeneralTable", 4))
		{
			ImGui::TableSetupColumn("One", ImGuiTableColumnFlags_WidthFixed, labWidth);
			ImGui::TableSetupColumn("Two", ImGuiTableColumnFlags_WidthFixed, controlWidth);
			ImGui::TableSetupColumn("Three", ImGuiTableColumnFlags_WidthFixed, labWidth2);
			ImGui::TableSetupColumn("Four", ImGuiTableColumnFlags_WidthFixed, controlWidth);

			// Trigger 1 Properties
			ImGui::TableNextColumn();
			ImGui::Text("Trigger (OSC1)");
			ImGui::TableNextColumn();
			ToggleSwitch((label + "Trigger1_toggle").c_str(), &Trigger1, GenColour);
			ImGui::TableNextColumn();
			ImGui::Text("Type");
			ImGui::TableNextColumn();
			ImGui::SetNextItemWidth(controlWidth);

			ImGui::Combo("##Trigger Type OSC1", &Trigger1TypeComboCurrentItem,
				TriggerTypeComboList, IM_ARRAYSIZE(TriggerTypeComboList));

			if (!AutoTrigger1Level) Trigger1Level.renderInTable(100.0f);
			else
			{
				ImGui::TableNextColumn();
				ImGui::Text("Level");
				ImGui::TableNextColumn();
				// TODO: Write display function that formats text in the appropriate unit
				ImGui::Text("%.2f V", Trigger1Level.getValue());
			}
			ImGui::TableNextColumn();
			ImGui::Text("Auto Level");
			ImGui::TableNextColumn();
			ToggleSwitch("##Auto1", &AutoTrigger1Level, GenColour);

			if (Hysteresis1DisplayOptionEnabled)
			{
				ImGui::Text("Hysteresis Level");
				ImGui::TableNextColumn();
			//	renderSliderwUnits(label + "_trigger_hysteresis", &TriggerHysteresis, 0, 2, "%.2f",
			//	    constants::volt_units, &tl_unit_idx);
				ImGui::Text("Auto");
				ImGui::SameLine();
				ImGui::Text("ON");
				ImGui::SameLine();
				ToggleSwitch((label + "Auto_trigger1_hysteresis_toggle").c_str(),
					&AutoTrigger1HysteresisToggle, GenColour);
				ImGui::SameLine();
				ImGui::Text("OFF");
			}

			// Trigger 2 Properties
			ImGui::TableNextColumn();
			ImGui::Text("Trigger (OSC2)");
			ImGui::TableNextColumn();
			ToggleSwitch((label + "Trigger2_toggle").c_str(), &Trigger2, GenColour);
			ImGui::TableNextColumn();
			ImGui::Text("Type");
			ImGui::TableNextColumn();
			ImGui::SetNextItemWidth(controlWidth);

			ImGui::Combo("##Trigger Type OSC2", &Trigger2TypeComboCurrentItem,
			    TriggerTypeComboList, IM_ARRAYSIZE(TriggerTypeComboList));

			if (!AutoTrigger2Level) Trigger2Level.renderInTable(100.0f);
			else
			{
				ImGui::TableNextColumn();
				ImGui::Text("Level");
				ImGui::TableNextColumn();
				// TODO: Write display function that formats text in the appropriate unit
				ImGui::Text("%.2f V", Trigger2Level.getValue());
			}
			ImGui::TableNextColumn();
			ImGui::Text("Auto Level");
			ImGui::TableNextColumn();
			ToggleSwitch("##Auto2", &AutoTrigger2Level, GenColour);

			if (Hysteresis2DisplayOptionEnabled)
			{
				ImGui::Text("Hysteresis Level");
				ImGui::TableNextColumn();
				//	renderSliderwUnits(label + "_trigger_hysteresis", &TriggerHysteresis,
				//0, 2, "%.2f", 	    constants::volt_units, &tl_unit_idx);
				ImGui::Text("Auto");
				ImGui::SameLine();
				ImGui::Text("ON");
				ImGui::SameLine();
				ToggleSwitch((label + "Auto_trigger2_hysteresis_toggle").c_str(),
				    &AutoTrigger2HysteresisToggle, GenColour);
				ImGui::SameLine();
				ImGui::Text("OFF");
			}

			ImGui::EndTable();
		}

		// Handle Clipboard Copied Feedback
		std::string OSC1ExportButtonText = "Export OSC1";
		if (OSC1ClipboardCopied == true)
		{
			OSC1ClipboardCopiedFrame = ImGui::GetFrameCount();
			OSC1ClipboardCopied = false;
		}
		if ((ImGui::GetFrameCount() - OSC1ClipboardCopiedFrame) < OSCClipboardCopiedLinger)
		{
			OSC1ExportButtonText = "Copied!";
		}

		if (WhiteOutlineButton((OSC1ExportButtonText+ "##OSC1ExportButton").c_str(),ImVec2(100,30)))
		{
			if (OSC1WritePathComboCurrentItem == 0) // Copy to Clipboard
			{
				OSC1ClipboardCopyNext = true; // state variable to tell PlotWidget to Copy
				                              // to clipboard on the next render
			}
			if (OSC1WritePathComboCurrentItem == 1) // Write to csv
			{
				nfdresult_t result = NFD_SaveDialog(FileExtension, NULL, &OSC2WritePath);
				if (result == NFD_OKAY)
				{
					puts("Success!");
					puts(OSC2WritePath);
				}
				else if (result == NFD_CANCEL)
				{
					puts("User pressed cancel.");
				}
				else
				{
					printf("Error: %s\n", NFD_GetError());
				}
			}
		}
		ImGui::SameLine();
		ImGui::Text("to");
		ImGui::SameLine();
		ImGui::SetNextItemWidth(OSCWritePathComboWidth);
		ImGui::Combo("##OSC1WritePathCombo",&OSC1WritePathComboCurrentItem,OSCWritePathComboList,IM_ARRAYSIZE(OSCWritePathComboList));


		std::string OSC2ExportButtonText = "Export OSC2";
		if (OSC2ClipboardCopied == true)
		{
			OSC2ClipboardCopiedFrame = ImGui::GetFrameCount();
			OSC2ClipboardCopied = false;
		}
		if ((ImGui::GetFrameCount() - OSC2ClipboardCopiedFrame) < OSCClipboardCopiedLinger)
		{
			OSC2ExportButtonText = "Copied!";
		}
		if (WhiteOutlineButton((OSC2ExportButtonText + "##OSC2ExportButton").c_str(),ImVec2(100,30)))
		{
			if (OSC2WritePathComboCurrentItem == 0) // Copy to Clipboard
			{
				OSC2ClipboardCopyNext = true; // state variable to tell PlotWidget to Copy to clipboard on the next render
			}
			if (OSC2WritePathComboCurrentItem == 1) // Write to csv
			{
				nfdresult_t result = NFD_SaveDialog(FileExtension, NULL, &OSC2WritePath);
				if (result == NFD_OKAY)
				{
					puts("Success!");
					puts(OSC2WritePath);
				}
				else if (result == NFD_CANCEL)
				{
					puts("User pressed cancel.");
				}
				else
				{
					printf("Error: %s\n", NFD_GetError());
				}
			}
		}
		ImGui::SameLine();
		ImGui::Text("to");
		ImGui::SameLine();
		ImGui::SetNextItemWidth(OSCWritePathComboWidth);
		ImGui::Combo("##OSC2WritePathCombo",&OSC2WritePathComboCurrentItem,OSCWritePathComboList,IM_ARRAYSIZE(OSCWritePathComboList));
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
	const char* TriggerTypeComboList[2]
	    = { "Rising Edge", "Falling Edge"};
	// Export stuff
	float OSCWritePathComboWidth = 100;
	const char* OSCWritePathComboList[2] = { "clipboard", "csv" };
	int OSC1ClipboardCopiedFrame = -1000;
	int OSC2ClipboardCopiedFrame = -1000;
	int OSCClipboardCopiedLinger = 50;
	float OSCExportButtonWidth = 150;
	/*const char* KSComboList[2] = { "375 KSPS", "750 KSPS" };
	const char* AttenComboList[3] = { "1x", "5x", "10x" };*/
};
