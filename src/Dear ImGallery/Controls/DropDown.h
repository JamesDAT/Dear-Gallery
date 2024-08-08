#pragma once
#include "Control.h"
#include <format>

namespace Gallery {
	class DropDown {
	public:
		static inline void BeginRender(const char* name, const char* codeText) {

			if (ImGui::TreeNode(name)) {
				ImGui::InputTextMultiline(std::format("##{}", name).c_str(), const_cast<char*>(codeText), strlen(codeText) + 1, ImVec2(0.f,0.f), ImGuiInputTextFlags_ReadOnly);

				ImGui::TreePop();
			}
		}

	private:
	};
}