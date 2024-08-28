#pragma once
#include "ControlWidget.hpp"
#include "librador.h"
#include "UIComponents.hpp"
#include "OscData.h"
//class OscData;

/// <summary>Oscilloscope Control Widget
/// </summary>
class OSCControl : public ControlWidget
{
public:
	// ImGui State variables
	bool DisplayCheck = true;
	/*int KSComboCurrentItem = 0;
	int AttenComboCurrentItem = 0;*/
	float OffsetVal = 0.0f;
	bool ACCoupledCheck = false;
	bool Paused = false;
	bool AutofitNext = false;
	OscData Data;
	OSCControl(const char* label, ImVec2 size, ImU32 borderColor,int channel)
	    : ControlWidget(label, size, borderColor)
	    , channel(channel)   
		, Data(OscData(this,channel))
	{
	}
	/// <summary> 
	/// Render UI elements for oscilloscope control
	/// </summary>
	void renderControl() override
	{
		ImGui::Text("Display");
		ImGui::SameLine();
		ImGui::Text("   OFF");
		ImGui::SameLine();
		ToggleSwitch((label + "Display_toggle").c_str(), &DisplayCheck, accentColour);
		ImGui::SameLine();
		ImGui::Text("ON");
		if (ImGui::Button("Autofit"))
		{
			AutofitNext = true;
		}
		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::SetCursorPosX(ImGui::GetWindowWidth()/2);
		PauseButton("Pause", 15, &Paused, accentColour);
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

