#pragma once
#include <GLFW/glfw3.h>

#include "Controls/Frame.h"
#include "Controls/Control.h"

// std
#include <exception>

namespace Gallery {

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void Init(GLFWwindow* window);
		void Render();

	private:
		Frame m_Frame{};
	};
}

