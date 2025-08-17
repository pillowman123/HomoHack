#pragma once
#include <include/sdk/backend/main/bExports.h>

namespace SDK::IL2CPP {
	struct Il2CppObject;

	struct Il2CppMethod {
		uint64_t GetOffset();

		Il2CppObject* Invoke(void* object, void** args);
	};
}