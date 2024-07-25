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
	ControlWidget(const char* label, ImVec2 size, const ImU32 accentColour)
	    : label(label)
	    , size(size)
	    , accentColour(accentColour)
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

		// Commented out this 'child' approach because of padding issues
		// ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.1f, 0.1f, 0.1f, 1.0f));
		
		//ImGui::BeginChild(label, size, ImGuiChildFlags_Border, 
		//ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
		
		// Hacky rectangle for heading (can not fill entire width of child)
		//ImDrawList* draw = ImGui::GetWindowDrawList();
		//ImVec2 p = ImGui::GetCursorScreenPos();
		float height = ImGui::GetFrameHeight();
		//draw->AddRectFilled(ImVec2(p.x - 5, p.y - 5),
		//    ImVec2(p.x + ImGui::GetContentRegionAvail().x + 5, p.y + height),
		//    accentColour, 0.0f);

		// ImGui::Text(label);

		// ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10.0f, 10.0f));
		
		// Plain tree approach works well, no indentation from 'CollapsingHeader' so have used this instead. Have not tried to style this yet
		
		ImVec2 p1 = ImGui::GetCursorScreenPos();
		ImDrawList* draw = ImGui::GetWindowDrawList();
		static float border_radius = 8.0f;

		// ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 10.0f);
		draw->AddRectFilled(p1,
		    ImVec2(p1.x + ImGui::GetContentRegionAvail().x, p1.y + height), accentColour,
		    border_radius, ImDrawFlags_RoundCornersTop);
		

		if (ImGui::TreeNodeEx(label, ImGuiTreeNodeFlags_DefaultOpen))
		{
			renderControl();
			
			ImGui::TreePop();
		}
		// ImGui::PopStyleVar();
		ImVec2 p2 = ImGui::GetCursorScreenPos();
		
		// ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 10.0f);
		draw->AddRect(p1, ImVec2(p2.x + ImGui::GetContentRegionAvail().x, p2.y),
		    accentColour, border_radius, ImDrawFlags_RoundCornersAll, 1.0f);
		// ImGui::PopStyleVar();

		ImGui::Dummy(ImVec2(0, 6.0f));
		// ImGui::EndChild();
		ImGui::PopStyleColor();
		// ImGui::PopStyleColor();
	}

	// Customise for each widget, see PSUControl.hpp for example
	virtual void renderControl() = 0;
	virtual void controlLab() = 0;

protected:
	const char* label;
	ImVec2 size;
	const ImU32 accentColour;
};