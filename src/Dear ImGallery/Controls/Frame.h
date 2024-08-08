#pragma once
#include "Control.h"
#include "DisplayPage.h"
#include "Pages/MainPage.h"
#include "Pages/ButtonPage.h"

// std
#include <string_view>
#include <memory>


namespace Gallery {
	class Frame : public Control {
	public:
		Frame() : m_DisplayPage(new MainPage) {}
		~Frame() {}


		void Render() override {
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			ImGuiIO& io = ImGui::GetIO();

			float stackPanelWidth = io.DisplaySize.x / 3; // a more responsive design could be used here, for instance setting a min
			// left panel
			{
				if (m_UseDarkMode) {
					ImGui::StyleColorsDark();
				}
				else {
					ImGui::StyleColorsLight();
				}
				ImGui::SetNextWindowSize(io.DisplaySize);
				ImGui::SetNextWindowPos({ 0,0 });
				ImGui::Begin("Primary Panel", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

				ImGui::BeginChild("Navigation Panel", ImVec2(stackPanelWidth, 0), true);
				ImGui::Checkbox("Use Darkmode", &m_UseDarkMode);
				m_MenuItemSize.x = stackPanelWidth;
				RenderTree();
				ImGui::EndChild();

				ImGui::SameLine();

				ImGui::BeginChild("Display Panel", ImVec2(0, 0), true);
				m_DisplayPage->Render();
				ImGui::EndChild();

				ImGui::End();
			}

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		}

	private:
		ImVec2 m_MenuItemSize{200.f,50.f};
		std::unique_ptr<DisplayPage> m_DisplayPage;
		bool m_UseDarkMode = false;

		void RenderTree() {
			if (RenderSelectable("Home")) {
				m_DisplayPage = std::make_unique<MainPage>();
			}

			if (ImGui::TreeNode("Basic Input")) {
				if (RenderSelectable("Button")) {
					m_DisplayPage = std::make_unique<ButtonPage>();
				}
				if (RenderSelectable("Checkbox")) {

				}

				ImGui::TreePop();
			}
		}

		bool RenderSelectable(const std::string& buttonText) {
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0, 0, 0, 0.1f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0, 0, 0, 0.2f));
			ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0, .25f));
			bool pressed = ImGui::Button(buttonText.data(), m_MenuItemSize);
			ImGui::PopStyleColor(3);
			ImGui::PopStyleVar();
			return pressed;
		}
	};
}
