#pragma once
#include <backend/includes.h>
#include "Object.h"
#include "system/Type.h"

namespace SDK::RR::Unity {
	struct GameObject : Object {
		template <typename T>
		T GetComponent(const char* typeName) {
			auto componentType = System::Type::GetType(typeName);
			void* args[1] = { componentType };
			return (T)Pointers::Unity::GameObject.GetComponent[this].Invoke(args).Get();
		}

		template <typename T>
		Structs::Mono::Array<T>* GetComponentsInChildren(const char* typeName) {
			auto childComponentType = System::Type::GetType(typeName);
			void* args[1] = { childComponentType };
			return (Structs::Mono::Array<T>*)Pointers::Unity::GameObject.GetComponentsInChildren[this].Invoke(args).Get();
		}
	};
}