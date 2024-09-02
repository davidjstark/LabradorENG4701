#include <algorithm>
#include <string>
#include <vector>
#include "util.h"

void RenderSearchableTree(const char* label, std::vector<TreeNode>& nodes)
{
	static char searchBuffer[256] = "";
	ImGui::InputText("Search", searchBuffer, IM_ARRAYSIZE(searchBuffer));

	std::string searchStr = searchBuffer;
	std::transform(searchStr.begin(), searchStr.end(), searchStr.begin(), ::tolower);

	if (ImGui::BeginTable(label, 1, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_Resizable))
	{
		for (const auto& node : nodes)
		{
			bool nodeVisible = searchStr.empty();
			std::vector<bool> bulletVisible(node.bullets.size(), false);

			// Check if any bullet points match the search
			for (size_t i = 0; i < node.bullets.size(); ++i)
			{
				std::string lowerBullet = node.bullets[i];
				std::transform(lowerBullet.begin(), lowerBullet.end(),
				    lowerBullet.begin(), ::tolower);
				if (lowerBullet.find(searchStr) != std::string::npos)
				{
					nodeVisible = true;
					bulletVisible[i] = true;
				}
			}

			if (nodeVisible)
			{
				ImGui::TableNextRow();
				ImGui::TableSetColumnIndex(0);
				if (ImGui::TreeNode(node.name.c_str()))
				{
					for (size_t i = 0; i < node.bullets.size(); ++i)
					{
						if (bulletVisible[i])
						{
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 0, 255));
						}
						ImGui::BulletText("%s", node.bullets[i].c_str());
						if (bulletVisible[i])
						{
							ImGui::PopStyleColor();
						}
					}
					ImGui::TreePop();
				}
			}
		}
		ImGui::EndTable();
	}
}

// Example usage
void renderHelpWindow(bool* p_open)
{
	if (!ImGui::Begin("Labrador User Guide", p_open))
	{
		ImGui::End();
		return;
	}
	if (!ImGui::IsWindowFocused())
	{
		*p_open = false;
		ImGui::End();
		return;
	}
	std::vector<TreeNode> nodes;
	for (int i = 0; i < 10; ++i)
	{
		TreeNode node;
		node.name = "Node " + std::to_string(i + 1);
		for (int j = 0; j < 5; ++j)
		{
			node.bullets.push_back(
			    "Bullet " + std::to_string(j + 1) + " of Node " + std::to_string(i + 1));
		}
		nodes.push_back(node);
	}

	RenderSearchableTree("Searchable Tree", nodes);
	ImGui::End();
}