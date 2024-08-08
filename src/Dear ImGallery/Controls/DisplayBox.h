#pragma once
#include "Control.h"
#include <algorithm>

namespace Gallery {
	class DisplayBox {
	public:
		static inline void BeginRender() {
			constexpr ImVec2 padding = { 5.f, 5.f };
			ImVec2 min = { ImGui::GetItemRectMin().x - padding.x, ImGui::GetItemRectMin().y - padding.y };
			ImVec2 max = { ImGui::GetWindowWidth() * 1.51f, ImGui::GetItemRectMax().y + padding.y};

			ImDrawList* drawList = ImGui::GetWindowDrawList();
			drawList->AddRect(min, max, IM_COL32(130, 130, 130, 255));

			//ImGui::BeginChild(name, ImVec2(0, 0), ImGuiChildFlags_Border);
		}

		/*static inline void EndRender() {
			ImGui::EndChild();
		}*/
	};
}
