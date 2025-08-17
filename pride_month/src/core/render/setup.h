#pragma once
//credits: https://github.com/rdbo/ImGui-DirectX-11-Kiero-Hook/tree/master
#include <d3d11.h>
#include <dxgi.h>
#include <kiero/kiero.h>
#include "gui/gui.h"


namespace render::setup {
	extern DWORD WINAPI createHook();
}