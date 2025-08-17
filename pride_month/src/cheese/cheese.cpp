#include "cheese.h"
#include <dobby/dobby.h>


void cheese::setup() {
	globals::runtime::mainSpoof = memory::findPattern("GameAssembly.dll", "\xFF\x23", "xx");
	globals::runtime::unitySpoof = memory::findPattern("UnityPlayer.dll", "\xFF\x23", "xx"); 


	console::get().log(clr::yellow, "[ > ] Spoof Addr: G: [%p] | U: [%p]", globals::runtime::mainSpoof, globals::runtime::unitySpoof);

	Pointers::Main::Exports.Setup(GetModuleHandleA("GameAssembly.dll"));

	auto domain = SDK::IL2CPP::Il2CppDomain::Get();
	if (!domain) {
		console::get().log(clr::red, "[ ! ] null domain!");
		Sleep(2000);
		std::exit(69);
	}

	auto thread = domain->ThreadAttach();
	console::get().log(clr::green, "[ + ] IL2CPP Setup: Thread: [%p]", thread);

	sdk::backend::setup();
	console::get().log(clr::green, "[ + ] Setup Backends");

	Sleep(150);

	//cheats::movement::setup();
}