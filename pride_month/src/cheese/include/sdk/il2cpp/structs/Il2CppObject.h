#pragma once
#include <include/sdk/backend/main/bExports.h>

namespace SDK::IL2CPP {
	struct Il2CppClass;

	struct Il2CppObject {
		Il2CppClass* GetClass();

		void* Unbox();
	};
}