#include "Il2CppImage.h"

namespace SDK::IL2CPP {
	Il2CppClass* Il2CppImage::GetClass(const char* namespaze, const char* name) {
		return (Il2CppClass*)spoof_call(globals::runtime::unitySpoof, Pointers::Main::Exports.il2cpp_class_from_name, (void*)this, namespaze, name);
	}
}