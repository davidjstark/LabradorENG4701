#pragma once
#include "imgui.h"
#include <string>
#include <sstream>
#include "util.h"


/// <summary>
/// Abstract class that draws control widget such as PSU Control
/// </summary>
class ControlWidget
{
public:
	bool show_help = false;

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="label">Name of controller</param>
	/// <param name="size">Child window size</param>
	/// <param name="borderColor">Accent colour</param>
	ControlWidget(std::string label, ImVec2 size, const float* accentColour)
	    : label(label)
	    , size(size)
	    , accentColour(accentColour)
	    , help_popup_id(label + " Help")
	    , pinout_height(0)
	    , pinout_width(0)
	    , pinout_texture((intptr_t)0)
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
		SetControlWidgetStyle(accentColour);

		ImU32 acol = ImGui::ColorConvertFloat4ToU32(
		    ImVec4(accentColour[0], accentColour[1], accentColour[2], 1));

		float height = ImGui::GetFrameHeight();
		ImVec2 p1 = ImGui::GetCursorScreenPos();
		ImDrawList* draw = ImGui::GetWindowDrawList();
		static float border_radius = 8.0f;
		
		// Title bar background
		draw->AddRectFilled(p1,
		    ImVec2(p1.x + ImGui::GetContentRegionAvail().x, p1.y + height), acol,
		    border_radius, ImDrawFlags_RoundCornersTop);

		ImGui::AlignTextToFramePadding();
		bool treeopen = ImGui::TreeNodeEx(label.c_str(),
		    ImGuiTreeNodeFlags_AllowItemOverlap | ImGuiTreeNodeFlags_DefaultOpen);
		ImGui::SameLine(ImGui::GetContentRegionAvail().x - 45);
		
		// Help button
		if (ImGui::Button("           ?"))
		{
			show_help = true;
		}

		// Widget Body
		if (treeopen)
		{
			renderControl();
			ImGui::TreePop();
		}
		
		// Widget border
		ImVec2 p2 = ImGui::GetCursorScreenPos();
		draw->AddRect(p1, ImVec2(p2.x + ImGui::GetContentRegionAvail().x, p2.y), acol,
		    border_radius, ImDrawFlags_RoundCornersAll, 1.0f);
		// Empty Space
		ImGui::Dummy(ImVec2(0, 6.0f));

		// ImGui::PopStyleColor();

		WidgetHeight = p2.y - p1.y;
	}

	float GetHeight()
	{
		return WidgetHeight;
	}

	ImU32 GetAccentColour()
	{
		return colourConvert(accentColour);
	}

	std::string getLabel()
	{
		return label;
	}

	void setHelpText(std::string text)
	{
		std::stringstream ss(text);
		std::string line;
		while (std::getline(ss, line))
		{
			// Top-level heading
			if (line.compare(0, 5, "#### ") == 0)
			{
				line.erase(0, 5);
				TreeNode new_header;
				new_header.name = line;
				help_trees.push_back(new_header);
				help_trees.back().expanded = false;
			}
			else help_trees.back().bullets.push_back(line);
			
		}
	}

	void setPinoutImg(intptr_t texture, int w, int h)
	{
		pinout_texture = texture;
		pinout_width = w;
		pinout_height = h;
	}

	void renderHelpText(bool expandAll = false, bool collapseAll = false, std::string search = "")
	{
		if (search.length() ==  0) for (TreeNode& t : help_trees)
		{
			if (expandAll) ImGui::SetNextItemOpen(true);
			else if (collapseAll) ImGui::SetNextItemOpen(false);
			else ImGui::SetNextItemOpen(t.expanded);

			if (ImGui::TreeNode((t.name + "##" + label).c_str()))
			{
				t.expanded = true;
				for (const std::string& l : t.bullets)
				{
					MarkdownToImGUIBullet(l);
				}
				ImGui::TreePop();
			}
			else
				t.expanded = false;
		}
		// Filtered help list
		else for (TreeNode& t : help_trees)
		{
			// Always expand when search string is long enough
			ImGui::SetNextItemOpen(true);
			
			if (t.isFound(search) && ImGui::TreeNode((t.name + "##" + label).c_str()))
			{
				for (const std::string& l : t.bullets)
				{
					if (l.find(search) != std::string::npos)
						MarkdownToImGUIBullet(l);
				}
				ImGui::TreePop();
			}
		}

		if (expandAll)
			ImGui::SetNextItemOpen(true);
		else if (collapseAll)
			ImGui::SetNextItemOpen(false);
		if (ImGui::TreeNode(("Pinout##" + label).c_str()))
		{
			ImGui::Image((void*) pinout_texture, ImVec2(pinout_width, pinout_height));
			ImGui::TreePop();
		}
	}

	void MarkdownToImGUIBullet(std::string md_text)
	{
		if (md_text.compare(0, 2, "- ") == 0)
		{
			md_text.erase(0, 2);
			ImGui::BulletText(md_text.c_str());
		}
		else if (md_text.compare(0, 4, "  - ") == 0)
		{
			md_text.erase(0, 4);
			ImGui::Dummy(ImVec2(10, 0));
			ImGui::SameLine();
			ImGui::BulletText(md_text.c_str());
		}
		else
		{
			ImGui::Text(md_text.c_str());
		}
	}

	void renderHelp()
	{
		// Render Help Text from markdown format 
		// Edit README.md to change help popup content

		// Center window
		ImGuiIO& io = ImGui::GetIO();
		// TODO: dynamically size based on size of window
		ImVec2 pos(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f);
		ImGui::SetNextWindowPos(pos, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
		ImGui::SetNextWindowSize(pos, ImGuiCond_Always);

		if (!ImGui::Begin((help_popup_id).c_str(), &show_help))
		{
			ImGui::End();
			return;
		}
		if (!ImGui::IsWindowFocused())
		{
			show_help = false;
			ImGui::End();
			return;
		}

		renderHelpText();

		ImGui::End();
		
	}

	bool BeginHelpPopup(const char* str_id, ImGuiWindowFlags flags)
	{
		
		ImGuiContext& g = *GImGui;
		if (g.OpenPopupStack.Size <= g.BeginPopupStack.Size) // Early out for performance
		{
			g.NextWindowData.ClearFlags(); // We behave like Begin() and need to consume
			                               // those values
			return false;
		}
		flags |= ImGuiWindowFlags_NoTitleBar;
		return ImGui::BeginPopupEx(g.CurrentWindow->GetID(str_id), flags);
	}

	// Customise for each widget, see PSUControl.hpp for example
	virtual void renderControl() = 0;
	virtual bool controlLab() = 0;
	

protected:
	const std::string label;
	ImVec2 size;
	const float* accentColour;
	
private:
	const std::string help_popup_id;
	float WidgetHeight = 0;
	std::vector<TreeNode> help_trees;
	intptr_t pinout_texture;
	int pinout_width, pinout_height;
};