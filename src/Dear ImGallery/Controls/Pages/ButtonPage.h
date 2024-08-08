#pragma once
#include <Controls/DisplayPage.h>
#include <Controls/DisplayBox.h>
#include <Controls/DropDown.h>

namespace Gallery {
	class ButtonPage : public DisplayPage {
	public:
		void Render() override {

			//
			// Button
			//
			ImGui::Text("Simple Clickable Button");

			ImGui::Button("Button");
			DisplayBox::BeginRender();

			//DisplayBox::EndRender();

			DropDown::BeginRender("Button Code", "if (ImGui::Button(\"Button\") {\n\t// button clicked code here\n}");
			ImGui::NewLine();

			//
			// Button with styling
			//

			ImGui::Text("Button with styling");

			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.f, 0.7f, 1.0f, 1.0f));				// Background color
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.5f, 0.6f, 0.5f, 0.5f));      // Hovered color
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.f, 1.f, 0.f, 1.0f));			// Active (pressed) color
			ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));             // Border color

			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10.0f, 5.0f));               // Padding inside the button
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 12.0f);                            // Rounded corners

			ImGui::Button("Button", ImVec2(200, 50));

			ImGui::PopStyleVar(2);
			ImGui::PopStyleColor(4);

			DisplayBox::BeginRender();

			//DisplayBox::EndRender();

			const char* styleCode = R"(
ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.f, 0.7f, 1.0f, 1.0f));					// Background color
ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.5f, 0.6f, 0.5f, 0.5f));			// Hovered color
ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.f, 1.f, 0.f, 1.0f));				// Active (pressed) color
ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));					// Border color

ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10.0f, 5.0f));					// Padding inside the button
ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 12.0f);								// Rounded corners

if (ImGui::Button("Button", ImVec2(200, 50))) {
	// button click code here
}

ImGui::PopStyleVar(2);
ImGui::PopStyleColor(4);)";

			DropDown::BeginRender("Button With Styling Code", styleCode);
			ImGui::NewLine();

			//
			// SmallButton
			//
			ImGui::Text("Small Button");

			ImGui::SmallButton("SmallButton");
			DisplayBox::BeginRender();

			//DisplayBox::EndRender();
			DropDown::BeginRender("Small Button Code", "if (ImGui::SmallButton(\"SmallButton\") {\n\t// button clicked code here\n}");
			
		}

	private:
		
	};
}