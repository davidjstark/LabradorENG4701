#ifndef _UI_H_
#define _UI_H_


#include "imgui.h"
#include "util.h"
#include <iostream>


bool inline PauseButton(const char* id, float radius, bool* state)
{
	ImU32 accentColour = IM_COL32(240,240,240, 255);
	ImU32 pp_col = IM_COL32(0, 0, 0, 255);

	ImVec2 p = ImGui::GetCursorScreenPos();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	bool switched = false;
	ImGui::SetCursorPos(
	    ImVec2(ImGui::GetCursorPosX() - radius, ImGui::GetCursorPosY() - radius));
	if (ImGui::InvisibleButton(id, ImVec2(radius*2,radius*2)))
	{
		*state = !*state;
		switched = true;
	}
	ImColor im_col_bg = ImColor(accentColour);
	ImColor im_pp_col = ImColor(pp_col);
	float mul = 1.0;
	if (ImGui::IsItemActive())
	{
		mul = 4.0/5;
	}
	else if (ImGui::IsItemHovered())
	{
		mul = 5.0/4;
	}
	im_col_bg.Value.x = mul * im_col_bg.Value.x > 1 ? 1 : mul * im_col_bg.Value.x;
	im_col_bg.Value.y = mul * im_col_bg.Value.y > 1 ? 1 : mul * im_col_bg.Value.y;
	im_col_bg.Value.z = mul * im_col_bg.Value.z > 1 ? 1 : mul * im_col_bg.Value.z;
	/*im_pp_col.Value.x = mul * im_pp_col.Value.x > 1 ? 1 : mul * im_pp_col.Value.x;
	im_pp_col.Value.y = mul * im_pp_col.Value.y > 1 ? 1 : mul * im_pp_col.Value.y;
	im_pp_col.Value.z = mul * im_pp_col.Value.z > 1 ? 1 : mul * im_pp_col.Value.z;*/
	ImU32 col_bg = ImU32(im_col_bg);
	pp_col = ImU32(im_pp_col);

	draw_list->AddCircleFilled(ImVec2(p.x,p.y), radius, col_bg);

	if (*state)
	{
		float left_offset_x = 3;
		float right_offset_x = 7;
		float offset_y = 7;
		draw_list->AddTriangleFilled(ImVec2(p.x - left_offset_x, p.y - offset_y), ImVec2(p.x - left_offset_x, p.y + offset_y),
		    ImVec2(p.x + offset_y, p.y), pp_col);
	}
	else
	{
		float offset_x = 5;
		float twix_width = 4;
		float offset_y = 7;
		draw_list->AddRectFilled(ImVec2(p.x - offset_x, p.y - offset_y),
		    ImVec2(p.x - offset_x + twix_width, p.y + offset_y), pp_col);
		draw_list->AddRectFilled(ImVec2(p.x + offset_x-twix_width, p.y - offset_y),
		    ImVec2(p.x + offset_x, p.y + offset_y), pp_col);
	}

	return switched;
}

/// <summary>
/// Adapted from https://github.com/ocornut/imgui/issues/1537#issuecomment-355562097
/// </summary>
/// <param name="id"></param>
/// <param name="state"></param>
/// <param name="accentColour"></param>
bool inline ToggleSwitch(const char* id, bool* state, ImU32 accentColour)
	{
		ImVec2 p = ImGui::GetCursorScreenPos();
		ImDrawList* draw_list = ImGui::GetWindowDrawList();

		float height = ImGui::GetFrameHeight() * 0.8;
		float width = height * 1.8f;
		float switch_width = width * 0.30f;
	    float pad = 2.0f;
	    float rounding = 0.0f;
	    bool switched = false;
	    if (ImGui::InvisibleButton(id, ImVec2(width, height)))
	    {
		    *state = !*state;
		    switched = true;
		}
			

		ImU32 col_bg = *state ? accentColour : IM_COL32(150, 150, 150, 255);

		draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, rounding);

		draw_list->AddRectFilled(
			*state ?	ImVec2(p.x + width - pad - switch_width,	p.y + pad) : // ON top-left
						ImVec2(p.x + pad,							p.y + pad),  // OFF top-left
	        *state ?	ImVec2(p.x + width - pad,					p.y + height - pad) : // ON bottom-right
						ImVec2(p.x + pad + switch_width,			p.y + height - pad),  // OFF bottom-right
			constants::PRIM_LIGHT, 
			rounding);
		
		return switched;
	}


/// <summary>
/// Adapted from https://github.com/ocornut/imgui/issues/1537#issuecomment-355562097
/// </summary>
/// <param name="id"></param>
/// <param name="state"></param>
/// <param name="accentColour"></param>
bool inline ToggleButton(const char* id, ImVec2 size, bool* state, ImU32 trueColour, ImU32 falseColour)
{
	ImVec2 p = ImGui::GetCursorScreenPos();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	ImU32 ButtonColour = *state ? trueColour : falseColour;

	float height = 30;
	float width = 100;
	float rounding = 0.0f;
	bool switched = false;
	if (ImGui::InvisibleButton(id, ImVec2(width, height)))
	{
		*state = !*state;
		switched = true;
	}

	if (ImGui::IsItemActive())
	{
		MultiplyButtonColour(&ButtonColour, 0.8);
	}
	else if (ImGui::IsItemHovered())
	{
		MultiplyButtonColour(&ButtonColour, 1.25);
	}


	draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), ButtonColour, rounding);
	ImVec2 text_size = ImGui::CalcTextSize(id);
	ImVec2 text_p
	    = ImVec2(p.x + width/2 - text_size.x / 2, p.y + height/2 - text_size.y / 2);
	draw_list->AddText(text_p, IM_COL32(255, 255, 255, 255), id);


	return switched;
}

/// <summary>
/// Generic dropdown menu for list of objects
/// </summary>
/// <typeparam name="T">Has getLabel() method</typeparam>
/// <param name="id"></param>
/// <param name="options">Dropdown options</param>
/// <param name="active">Active index</param>
/// <param name="size">Length of options</param>
/// <returns></returns>
template <typename T>
    bool inline ObjectDropDown(const char* id, T const options[], int* active, int size)
    {
	bool changed = false;
	std::string preview = options[*active]->getLabel();
	// std::cout << "size: " << size;
	if (ImGui::BeginCombo(id, preview.c_str(), 0))
	{
		for (int n = 0; n < size; n++)
		{
			const bool is_selected = (*active == n);
			if (ImGui::Selectable((options[n]->getLabel()).c_str(), is_selected))
			{
				*active = n;
				changed = true;
			}
			
			// Set the initial focus when opening the combo (scrolling + keyboard
			// navigation focus)
			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
	return changed;
}

/// <summary>
/// Generic dropdown for list of strings
/// </summary>
/// <param name="id"></param>
/// <param name="options"></param>
/// <param name="active"></param>
/// <param name="size"></param>
/// <returns></returns>
int inline DropDown(const char* id, std::vector<std::string> options, int* active)
{
	int changed = 0;
	const char* preview = options[*active].c_str();
	if (ImGui::BeginCombo(id, preview, ImGuiComboFlags_NoArrowButton))
	{
		for (int n = 0; n < options.size(); n++)
		{
			const bool is_selected = (*active == n);
			if (ImGui::Selectable(options[n].c_str(), is_selected))
			{
				*active = n;
				changed = 1;
			}

			// Set the initial focus when opening the combo (scrolling + keyboard
			// navigation focus)
			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
	return changed;
}

void inline TextRight(std::string text)
{
	auto windowWidth = ImGui::GetWindowSize().x;
	auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

	ImGui::SetCursorPosX(windowWidth - textWidth - 10);
	ImGui::Text(text.c_str());
}

class SIValue
{
public:
	SIValue(std::string id, std::string label, float default_val, float min_val, float max_val, std::string symbol, std::vector<std::string> prefixs,
	    std::vector<std::string> format)
	    : id(id)
		, label(label)
	    , value(default_val)
	    , min_val(min_val)
	    , max_val(max_val)
	    , symbol(symbol)
	    , prefixs(prefixs)
	    , formats(format)
	{
		updateDisplayValue();
		for (int i = 0; i < prefixs.size(); i++)
		{
			options.push_back(prefixs[i] + symbol);
		}
	}

	bool renderInTable(float inpWidth)
	{
		bool changed = false;
		ImGui::TableNextColumn();
		ImGui::Text(label.c_str());
		ImGui::TableNextColumn();
		ImGui::SetNextItemWidth(inpWidth);
		changed |= ImGui::DragFloat(
			id.c_str(), 
			&display_value, 
			std::abs(display_value) < 0.01 ? 0.01 : 0.01f * std::abs(display_value), // variable speed slider 
			display_min_val, 
			display_max_val, 
			getFormat(), 
			ImGuiSliderFlags_AlwaysClamp // clamp even with manual input
		);

		ImGui::SameLine();
		if (options.size() > 1 && DropDown(("##" + id + "dd").c_str(), options, &prefix_idx))
		{
			updateDisplayValue();
		}
		else if (options.size() == 1) ImGui::Text(options[0].c_str());
		// ImGui::TableNextColumn();
		if (changed) updateValue();
		return changed;
	}

	float getValue()
	{
		return value;
	}

	void setLevel(float newValue)
	{
		value = newValue;
		updateDisplayValue();
	}

private:
	const std::string label;
	const std::string id;
	float value; // SI value (always in standard unit, eg volts)
	float display_value; // Value to display with unit conversion
	float display_max_val;
	float display_min_val;
	float min_val;
	float max_val;
	std::string symbol;
	std::vector<std::string> formats;
	int prefix_idx = 0;
	std::vector<std::string> prefixs;
	std::vector<std::string> options;
	int n_prefix;

	/// <summary>
	/// Multiplier to convert prefixed SI unit to standard SI unit, eg mV -> V
	/// </summary>
	/// <returns></returns>
	float getMutliplier()
	{
		std::string prefix = prefixs[prefix_idx];
		if (prefix.empty()) return 1;
		else if (!prefix.compare("m")) return 1e-3;
		else if (!prefix.compare("k")) return 1e3;
		else return 1;
	}

	const char* getFormat()
	{
		return (formats[prefix_idx]).c_str();
	}

	void updateDisplayValue()
	{
		const float m = getMutliplier();
		display_value = value / m;
		display_min_val = min_val / m;
		display_max_val = max_val / m;
	}
	void updateValue()
	{
		value = display_value * getMutliplier();
	}

};

bool inline WhiteOutlineButton(const char* id, ImVec2 size=ImVec2(0, 0))
{
	ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1, 1, 1, 0.5)); // White border for buttons
	ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1);
	bool result = ImGui::Button(id, size);
	ImGui::PopStyleVar();
	ImGui::PopStyleColor();
	return result;
}

#endif