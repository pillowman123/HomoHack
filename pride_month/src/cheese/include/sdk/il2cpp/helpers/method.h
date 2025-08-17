#pragma once
#include <include/sdk/il2cpp/structs/il2cpp.h>

//replace with appropriate types soon
namespace SDK::IL2CPP::Helpers {
	template <typename T>
	class Method {
	private:
		void* object{};
		SDK::IL2CPP::Il2CppObject* result{};
		SDK::IL2CPP::Il2CppMethod* methodInfo{};
	public:
		Method() = default;

		Method(SDK::IL2CPP::Il2CppMethod* methodInfo) : methodInfo(methodInfo) {}

		Method(Method<T>& other) {
			object = other.object;
			result = other.result;
			methodInfo = other.methodInfo;
		}

		Method& operator[](void* instance) { object = instance; return *this; }
		
		Method& Invoke(void** args = nullptr) {
			result = methodInfo->Invoke(object, args);
			return *this;
		};

		T Get() { return (T)result; }
		T Unbox() { return *(T*)result->Unbox(); }
	};
}