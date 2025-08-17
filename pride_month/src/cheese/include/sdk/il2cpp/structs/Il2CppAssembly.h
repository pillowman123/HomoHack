#pragma once
#include <cstdint>

namespace SDK::IL2CPP {
	struct Il2CppImage;

	struct Il2CppAssembly {
		Il2CppImage* GetImage();
	};
}