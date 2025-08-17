#include "core.h"


void core::setup() {
	console::get().init();

	//console::get().log(clr::magenta, "Dobby", "Version: %s", DobbyBuildVersion());

	//cheese::bypass::run();

	cheese::setup();
	console::get().log(clr::yellow, "[ + ] Bleh Bleh :3");

	std::thread(&render::setup::createHook).detach();
	console::get().log(clr::gray, "[ > ] Even More Bleh :3");
}

void core::destroy() {
	console::get().destroy();
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		cmd = new console("pride_month.cc (hookless) logs | @pillowguy._.");
		std::thread(&core::setup).detach();
		break;
	case DLL_PROCESS_DETACH:
		core::destroy();
		break;
	}
	return TRUE;
}