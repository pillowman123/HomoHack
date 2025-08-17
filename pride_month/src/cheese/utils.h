#pragma once
#include <cstdint>
#include <vector>
#include <Windows.h>
#include <dobby/dobby.h>

namespace cheese::utils {
	extern void* getAbsoluteAddress(uint64_t addr);
	extern void* getAbsoluteAddressTargeted(const char* moduleName, uint64_t addr);


	extern inline int hook(void* target, void* replaceCall, void** origCall);
	extern void retPatch(void* target);
	extern void bytePatch(char bytes[], void* target);
}