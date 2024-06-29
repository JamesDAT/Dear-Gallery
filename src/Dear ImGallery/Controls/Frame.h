#pragma once
#include "Control.h"

namespace Gallery {
	class Frame : public Control {
	public:

		void Render() override {
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			ImGuiIO& io = ImGui::GetIO();

			float stackPanelWidth = io.DisplaySize.x / 3; // a more responsive design could be used here, for instance setting a min
			// left panel
			{
				ImGui::SetNextWindowSize(io.DisplaySize);
				ImGui::SetNextWindowPos({ 0,0 });
				ImGui::Begin("Primary Panel", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

				ImGui::BeginChild("Navigation Panel", ImVec2(stackPanelWidth, 0), true);
				ImGui::Text("Navigation Panel");
				ImGui::EndChild();

				ImGui::SameLine();

				ImGui::BeginChild("Display Panel", ImVec2(0, 0), true);
				ImGui::Text("Display Panel");
				ImGui::EndChild();

				ImGui::End();
			}

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		}
	};
}
