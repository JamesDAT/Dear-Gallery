#pragma once
#include <Controls/DisplayPage.h>

namespace Gallery {
	class MainPage : public DisplayPage {
	public:
		void Render() override {
			ImGui::Text("Welcome to Dear-ImGallery! Find controls on the left, explore their styling and implementation");
		}

	private:
		
	};
}
