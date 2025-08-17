#pragma once
#include <iostream>
#include <Windows.h>
#include "include/colored_cout.h"

class console {
private:
	std::string title{};
public:
	console(std::string title) : title(title) {}

	static console get();

	void log(clr color, const char* fmt, ...);
	void log(clr color, const char* tag, const char* fmt, ...); //optional overload for seperating tag.

	void clear();
public:
	void init();
	void destroy();
};

extern console* cmd;