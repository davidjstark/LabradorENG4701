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
int inline DropDown(const char* id, char* const *options, int* active, int size)
{
	int changed = 0;
	const char* preview = options[*active];
	if (ImGui::BeginCombo(id, preview, 0))
	{
		for (int n = 0; n < size; n++)
		{
			const bool is_selected = (*active == n);
			if (ImGui::Selectable(options[n], is_selected))
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

/// <summary>
/// Generic Slider with Units
/// </summary>
/// <param name="type">Type of slider</param>
/// <param name="result">Resulting float</param>
/// <param name="min">Lower bound</param>
/// <param name="max">Upper bound</param>
/// <param name="prompt">Prompt/format over slider</param>
/// <param name="units">List of unit objects</param>
/// <param name="unit_idx">Index of selected unit</param>
bool inline renderSliderwUnits(const std::string& label, float* result, float min, float max,
    const char* prompt, Unit* const units[], int* unit_idx)
{
	bool changed = false;
	changed |= ImGui::DragFloat(("##" + label).c_str(), result, *result/300, min, max, prompt, ImGuiSliderFlags_AlwaysClamp);
	ImGui::SameLine();
	changed |= ObjectDropDown(("##" + label + "_unit").c_str(), units, unit_idx, 3);
	return changed;
}

void inline TextRight(std::string text)
{
	auto windowWidth = ImGui::GetWindowSize().x;
	auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

	ImGui::SetCursorPosX(windowWidth - textWidth - 10);
	ImGui::Text(text.c_str());
}

#endif