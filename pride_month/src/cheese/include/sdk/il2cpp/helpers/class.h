#pragma once
#include <include/sdk/il2cpp/il2cpp_utils.h>

namespace SDK::IL2CPP::Helpers {
	struct Class {
	private:
		SDK::IL2CPP::Il2CppClass* m_class{};
	public:
		Class() = default;

		Class(SDK::IL2CPP::Il2CppClass* klass) : m_class(klass) {}

		Class(const char* imageName, const char* namespaze, const char* name) {
			m_class = SDK::IL2CPP::Utils::GetClass(imageName, namespaze, name);
		}

		bool IsValid() { return (m_class != nullptr); }

		SDK::IL2CPP::Il2CppClass* Get() { return m_class; }

		SDK::IL2CPP::Il2CppObject* CreateNewObject() { return IsValid() ? m_class->CreateNewObject() : nullptr; }
		SDK::IL2CPP::Il2CppObject* BoxValue(void* data) { return IsValid() ? m_class->BoxValue(data) : nullptr; }

		SDK::IL2CPP::Il2CppMethod* GetMethod(const char* methodName, int argsCount) {
			return IsValid() ? m_class->GetMethod(methodName, argsCount) : nullptr;
		}

		SDK::IL2CPP::Il2CppField* GetField(const char* fieldName) {
			return IsValid() ? m_class->GetField(fieldName) : nullptr;
		}
	};
}