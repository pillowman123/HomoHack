#include "gui_base.h"

bool render::gui_base::isOpened{ false };

void render::gui_base::keyManager() {
	if (GetAsyncKeyState(VK_INSERT) & 1 || GetAsyncKeyState(VK_DELETE) & 1) {
		isOpened = !isOpened;
		ImGui::GetIO().MouseDrawCursor = isOpened;
	}
}


void render::gui_base::initImGui(HWND window, ID3D11Device* device, ID3D11DeviceContext* context) {
	ImGui::CreateContext();
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(device, context);
	
	themes::basic();
	ImGui::GetIO().Fonts->AddFontFromMemoryTTF((void*)Roboto_Regular, sizeof(Roboto_Regular), 18.0f);
}