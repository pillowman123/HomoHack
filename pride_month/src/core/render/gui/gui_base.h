#pragma once
#include <iostream>
#include <Windows.h>
#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>
#include <render/styling/themes.h>
#include <render/styling/Roboto_Regular.h>

namespace render::gui_base {
	extern bool isOpened;

	extern void keyManager();

	extern void initImGui(HWND window, ID3D11Device* device, ID3D11DeviceContext* context);
}