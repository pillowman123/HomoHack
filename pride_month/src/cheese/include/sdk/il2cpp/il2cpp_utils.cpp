#include "il2cpp_utils.h"

namespace SDK::IL2CPP {
	void* Utils::AttachThread() {
		auto pDomain = SDK::IL2CPP::Il2CppDomain::Get();
		if (pDomain) {
			auto pThread = pDomain->ThreadAttach();
			return (pThread) ? pThread : nullptr;
		}
		return nullptr;
	}

	SDK::IL2CPP::Il2CppImage* Utils::GetImage(const char* name) {
		auto pDomain = SDK::IL2CPP::Il2CppDomain::Get();
		if (pDomain) {
			auto pAssembly = pDomain->GetAssembly(name);
			return (pAssembly && pAssembly->GetImage()) ? pAssembly->GetImage() : nullptr;
		}
		return nullptr;
	}

	SDK::IL2CPP::Il2CppClass* Utils::GetClass(const char* imageName, const char* namespaze, const char* klassName) {
		auto pImage = GetImage(imageName);
		if (pImage) {
			auto pKlass = pImage->GetClass(namespaze, klassName);
			return (pKlass) ? pKlass : nullptr;
		}
		return nullptr;
	}

	SDK::IL2CPP::Il2CppMethod* Utils::GetMethod(const char* imageName, const char* namespaze, const char* klassName, const char* methodName, int argsCount) {
		auto pKlass = GetClass(imageName, namespaze, klassName);
		if (pKlass) {
			auto pMethod = pKlass->GetMethod(methodName, argsCount);
			return (pMethod) ? pMethod : nullptr;
		}
		return nullptr;
	}

	SDK::IL2CPP::Il2CppMethod* Utils::GetMethod(SDK::IL2CPP::Il2CppClass* klass, const char* methodName, int argsCount) {
		if (klass) {
			auto pMethod = klass->GetMethod(methodName, argsCount);
			return (pMethod) ? pMethod : nullptr;
		}
		return nullptr;
	}
}