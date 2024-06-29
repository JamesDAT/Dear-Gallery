#pragma once
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include <GLFW/glfw3.h>

namespace Gallery {
	class Control {
	public:
		virtual void Render() = 0;

		static void SetupControls(GLFWwindow* window) {
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();

			ImGui_ImplGlfw_InitForOpenGL(window, true);
			ImGui_ImplOpenGL3_Init("#version 460");
		}
	};

	
}
