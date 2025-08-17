#pragma once
#include <backend/main/bExports.h>

namespace SDK::IL2CPP {
	struct Il2CppString {
		static Il2CppString* New(const char* str);
	};
}