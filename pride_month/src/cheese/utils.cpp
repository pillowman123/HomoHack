#include "utils.h"


void* cheese::utils::getAbsoluteAddress(uint64_t addr) {
	auto gameAssembly = GetModuleHandleA("GameAssembly.dll");
	if (gameAssembly)
		return (void**)((uint64_t)gameAssembly + addr);
	return 0x0;
}


void* cheese::utils::getAbsoluteAddressTargeted(const char* moduleName, uint64_t addr) {
	auto module = GetModuleHandleA(moduleName);
	if (module)
		return (void**)((uint64_t)module + addr);
	return nullptr;
}

inline int cheese::utils::hook(void* target, void* replaceCall, void** origCall) {
	return DobbyHook(target, replaceCall, origCall);
}

void cheese::utils::retPatch(void* target) {
	//https://www.unknowncheats.me/wiki/C%2B%2B:How_to_patch_Bytes_using_PatternScan_(AOB)_%2B_Explanation_/_Snippet
	DWORD oldProt{};

	VirtualProtect(target, 1, PAGE_EXECUTE_READWRITE, &oldProt);

	char ret[] = "\xC3"; //ret - 0xc3

	memcpy(target, ret, 1);
	
	VirtualProtect(target, 1, oldProt, nullptr);
}

void cheese::utils::bytePatch(char bytes[], void* target) {
	DWORD oldP{};

	VirtualProtect(target, sizeof(bytes), PAGE_EXECUTE_READWRITE, &oldP);
	memcpy(target, bytes, sizeof(bytes));
	VirtualProtect(target, sizeof(bytes), oldP, nullptr);
}