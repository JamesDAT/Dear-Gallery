#include "Renderer.h"
#include "glad/glad.h"

namespace Gallery {
	Renderer::Renderer() {

	}

	void Renderer::Init(GLFWwindow* window) {
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			throw std::exception("Failed to load Glad");
		}

		Control::SetupControls(window);
	}

	void Renderer::Render() {
		glClearColor(1.f, 1.f, 1.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		m_Frame.Render();
	}

	Renderer::~Renderer() {

	}
}
