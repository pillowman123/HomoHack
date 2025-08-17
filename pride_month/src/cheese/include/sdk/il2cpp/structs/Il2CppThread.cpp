#include "Il2CppThread.h"

namespace SDK::IL2CPP {
	void Il2CppThread::Detach() {
		spoof_call(globals::runtime::unitySpoof, Pointers::Main::Exports.il2cpp_thread_detach, (void*)this);
	}
}