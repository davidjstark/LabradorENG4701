#pragma once
#include "imgui.h"

/// <summary>
/// Abstract class that draws child that can be populated by a control widget
/// </summary>
class ControlWidget
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="label">Name of controller</param>
	/// <param name="size">Child window size</param>
	/// <param name="borderColor">Accent colour</param>
	ControlWidget(const char* label, ImVec2 size, ImU32 borderColor)
	    : label(label)
	    , size(size)
	    , borderColor(borderColor)
	{}

	/// <summary>
	/// Update size of child window
	/// </summary>
	/// <param name="new_size">New size</param>
	void setSize(ImVec2 new_size)
	{
		size = new_size;
	}

	/// <summary>
	/// Generic function to render control widget with correct style
	/// </summary>
	void Render()
	{
		ImGui::PushStyleColor(ImGuiCol_Border, borderColor);
		ImGui::BeginChild(label, size, true,
		    ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
		ImGui::Text(label);
		
		renderControl();

		ImGui::EndChild();
		ImGui::PopStyleColor();
	}

	// Customise for each widget, see PSUControl.hpp
	virtual void renderControl() = 0;
	virtual void controlLab() = 0;

protected:
	const char* label;
	ImVec2 size;
	ImU32 borderColor;
};