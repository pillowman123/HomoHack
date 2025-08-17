#include "Il2CppDomain.h"

namespace SDK::IL2CPP {
	Il2CppDomain* Il2CppDomain::Get() { 
		return (Il2CppDomain*)spoof_call(globals::runtime::unitySpoof, Pointers::Main::Exports.il2cpp_domain_get); 
	}

	Il2CppThread* Il2CppDomain::ThreadAttach() {
		return (Il2CppThread*)spoof_call(globals::runtime::unitySpoof, Pointers::Main::Exports.il2cpp_thread_attach, (void*)this);
	}

	Il2CppAssembly* Il2CppDomain::GetAssembly(const char* name) {
		return (Il2CppAssembly*)spoof_call(globals::runtime::unitySpoof, Pointers::Main::Exports.il2cpp_domain_assembly_open, (void*)this, name);
	}
}