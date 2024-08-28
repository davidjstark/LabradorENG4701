#pragma once
#include "imgui.h"
#include <string>

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
	ControlWidget(std::string label, ImVec2 size, const ImU32 accentColour)
	    : label(label)
	    , size(size)
	    , accentColour(accentColour)
	    , help_popup_id(label + " Help")
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
		ImGui::PushStyleColor(ImGuiCol_Border, accentColour);

		float height = ImGui::GetFrameHeight();
		ImVec2 p1 = ImGui::GetCursorScreenPos();
		ImDrawList* draw = ImGui::GetWindowDrawList();
		static float border_radius = 8.0f;
		
		// Title bar background
		draw->AddRectFilled(p1,
		    ImVec2(p1.x + ImGui::GetContentRegionAvail().x, p1.y + height), accentColour,
		    border_radius, ImDrawFlags_RoundCornersTop);

		ImGui::AlignTextToFramePadding();
		bool treeopen = ImGui::TreeNodeEx(label.c_str(),
		    ImGuiTreeNodeFlags_AllowItemOverlap | ImGuiTreeNodeFlags_DefaultOpen);
		ImGui::SameLine(ImGui::GetContentRegionAvail().x);
		
		if (ImGui::Button("?"))
			ImGui::OpenPopup(help_popup_id.c_str());

		if (ImGui::BeginPopup(help_popup_id.c_str(), ImGuiWindowFlags_NoResize))
		{
			renderHelp();
			
			if (ImGui::Button("Close"))
				ImGui::CloseCurrentPopup();
			ImGui::EndPopup();
		}
		// Widget Body
		if (treeopen)
		{
			renderControl();
			ImGui::TreePop();
		}
		
		// Widget border
		ImVec2 p2 = ImGui::GetCursorScreenPos();
		draw->AddRect(p1, ImVec2(p2.x + ImGui::GetContentRegionAvail().x, p2.y),
		    accentColour, border_radius, ImDrawFlags_RoundCornersAll, 1.0f);
		// Empty Space
		ImGui::Dummy(ImVec2(0, 6.0f));

		ImGui::PopStyleColor();

		WidgetHeight = p2.y - p1.y;
	}

	float GetHeight()
	{
		return WidgetHeight;
	}

	ImU32 GetAccentColour()
	{
		return accentColour;
	}

	// Customise for each widget, see PSUControl.hpp for example
	virtual void renderControl() = 0;
	virtual void renderHelp() = 0;
	virtual bool controlLab() = 0;
	

protected:
	const std::string label;
	ImVec2 size;
	const ImU32 accentColour;

private:
	const std::string help_popup_id;
	float WidgetHeight = 0;
};