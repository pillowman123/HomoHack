#include "Il2CppString.h"

namespace SDK::IL2CPP {
	Il2CppString* Il2CppString::New(const char* str) {
		return (Il2CppString*)spoof_call(globals::runtime::unitySpoof, Pointers::Main::Exports.il2cpp_string_new, str);
	}
}