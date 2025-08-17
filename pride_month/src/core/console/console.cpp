#include "console.h"


console* cmd = nullptr;

console console::get() { return *cmd; };

void console::clear() { system("cls"); }


void console::log(clr color, const char* fmt, ...) {
	char* buffer = new char[1024];
	va_list args;

	//reference: https://stackoverflow.com/questions/7031116/how-to-create-function-like-printf-variable-argument
	va_start(args, fmt);
	vsprintf(buffer, fmt, args);
	va_end(args);

	std::cout << color << buffer << clr::reset << std::endl;

	delete[] buffer;
}

void console::log(clr color, const char* tag, const char* fmt, ...) {
	char* buffer = new char[1024];
	va_list args;


	va_start(args, fmt);
	vsprintf(buffer, fmt, args);
	va_end(args);

	std::cout << color << "[" + std::string(tag) + "] " << buffer << clr::reset << std::endl;

	delete[] buffer;
}

void console::init() {
	AllocConsole();
	SetConsoleTitleA(title.c_str());

	FILE* f{};
	freopen_s(&f, "CONOUT$", "w", stdout);

	console::get().log(clr::green, "[ + ] Logging Console Initialized");
	Sleep(1500);
	console::get().clear();
}


void console::destroy() { FreeConsole(); }