#pragma once
#include <GLFW/glfw3.h>

#include "Renderer.h"

// std
#include <memory>
#include <cassert>
#include <exception>

namespace Gallery {
	class Window
	{
	public:
		Window();
		~Window();

		//Window(const Window&) = default;
		//Window& operator=(const Window&) = default;

		void Run();
		void Close() { m_ShouldClose = true; }

	private:
		GLFWwindow* m_Window; // I don't like the use of raw pointer here, but it should be fine as it follows RAII
		std::unique_ptr<Renderer> m_Renderer;
		bool m_ShouldClose;
	};
}

