#pragma once
#include <Controls/DisplayPage.h>

namespace Gallery {
	class MainPage : public DisplayPage {
	public:
		void Render() override {
			ImGui::Text("This display page");
		}

	private:

	};
}
