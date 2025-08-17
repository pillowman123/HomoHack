#pragma once
#include <include/sdk/il2cpp/structs/il2cpp.h>

namespace SDK::IL2CPP::Utils {
	extern void* AttachThread();

	extern SDK::IL2CPP::Il2CppImage* GetImage(const char* imageName);
	extern SDK::IL2CPP::Il2CppClass* GetClass(const char* imageName, const char* namespaze, const char* klassName);

	extern SDK::IL2CPP::Il2CppMethod* GetMethod(const char* imageName, const char* namespaze, const char* klassName, const char* methodName, int argsCount);
	extern SDK::IL2CPP::Il2CppMethod* GetMethod(SDK::IL2CPP::Il2CppClass* klass, const char* methodName, int argsCount);
}