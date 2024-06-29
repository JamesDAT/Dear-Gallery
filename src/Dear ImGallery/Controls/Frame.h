#pragma once
#include "Control.h"

namespace Gallery {
	class Frame : public Control {
	public:

		void Render() override {
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			// left panel
			{
				ImGui::Begin("Test");

				ImGui::End();
			}

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		}
	};
}
