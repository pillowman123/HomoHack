#pragma once
#include <include/sdk/backend/main/bExports.h>

namespace SDK::IL2CPP {
	struct Il2CppClass;

	struct Il2CppField {
		Il2CppClass* GetParent();
		size_t GetOffset();

		void GetValue(void* object, void* value);
		void SetValue(void* object, void* value);

		void GetStaticValue(void* value);
		void SetStaticValue(void* value);
	};
}