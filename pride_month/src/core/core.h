#pragma once
//Standard C++ Libraries
#include <iostream>
#include <thread>
//Windows go brrr
#include <Windows.h>
//Project
#include <console/console.h>
#include <bypass/bypass.h>
#include <cheese.h>
#include <render/setup.h>

namespace core {
	void setup();
	void destroy();
}