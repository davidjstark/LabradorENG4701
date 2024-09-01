#pragma once
#include "imgui.h"
#include <string>
#include <sstream>

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
			renderHelpText();
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

	std::string getLabel()
	{
		return label;
	}

	void setHelpText(std::string text)
	{
		help_text = text;
	}

	void renderHelpText()
	{
		std::stringstream ss(help_text);
		std::string line;
		std::string next_header = "";
		std::string to_write = "";
		while (std::getline(ss, line))
		{
			if (line.compare(0, 5, "#### ") == 0 || (next_header != "" && next_header != "End"))
			{
				if (next_header != "")
				{
					to_write = line;
					line = next_header;
					next_header = "";
				}
				else
				{
					line.erase(0, 5);
				}

				ImGui::SetNextItemOpen(true, ImGuiCond_Once);
				
				if (ImGui::TreeNode(line.c_str()))
				{
					if (to_write != "")
					{
						if (to_write.compare(0, 2, "- ") == 0)
						{
							to_write.erase(0, 2);
							ImGui::BulletText(to_write.c_str());
						}
						else
						{
							ImGui::Text(to_write.c_str());
						}
					}
					while (std::getline(ss, line))
					{
						if (line.compare(0, 5, "#### ") == 0)
						{
							line.erase(0, 5);
							next_header = line;
							break;
						}
						else
						{
							if (line.compare(0, 2, "- ") == 0)
							{
								line.erase(0, 2);
								ImGui::BulletText(line.c_str());
							}
							else
							{
								ImGui::Text(line.c_str());
							}
						}
					}
					ImGui::TreePop();
				}
			}
		}
	}

	// Customise for each widget, see PSUControl.hpp for example
	virtual void renderControl() = 0;
	virtual void renderHelp() = 0;
	virtual bool controlLab() = 0;
	

protected:
	const std::string label;
	ImVec2 size;
	const ImU32 accentColour;
	std::string help_text;

private:
	const std::string help_popup_id;
	float WidgetHeight = 0;
	
};