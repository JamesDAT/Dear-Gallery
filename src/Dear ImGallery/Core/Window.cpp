#include "Window.h"

namespace Gallery {
	Window::Window() :
		m_Window(nullptr),
		m_ShouldClose(false),
		m_Renderer(new Renderer())
	{
		if (glfwInit() == GLFW_FALSE) {
			throw std::exception("Failed to initialize GLFW");
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

		m_Window = glfwCreateWindow(960, 540, "Dear ImGallery", nullptr, nullptr);
		if (m_Window == nullptr) {
			glfwTerminate();
			throw std::exception("Failed to initialize GLFW");
		}

		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(1); // v-sync

		glfwSetWindowUserPointer(m_Window, reinterpret_cast<void*>(this));

		m_Renderer->Init(m_Window);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) 
			{
				assert(window != nullptr);
				auto pWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
				assert(pWindow != nullptr); 
				pWindow->Close();
			}
		);
	}

	void Window::Run() {
		while (!m_ShouldClose) {
			glfwWaitEvents();
			m_Renderer->Render();

			glfwSwapBuffers(m_Window);
		}
	}

	Window::~Window() {
		glfwTerminate();
	}
}
