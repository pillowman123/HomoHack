#pragma once
#include <il2cpp/helpers/helpers.h>
#include <structs/unity/unity_structs.h>

namespace Pointers::Unity {
	struct U_Camera {
		SDK::IL2CPP::Helpers::Class klass;

		SDK::IL2CPP::Helpers::Method<void> get_worldToCameraMatrix_Injected;
		SDK::IL2CPP::Helpers::Method<void> get_projectionMatrix_Injected;

		SDK::IL2CPP::Helpers::Method<SDK::Structs::Unity::Vector3> WorldToViewportPoint;
		SDK::IL2CPP::Helpers::Method<void*> get_current;

		void Setup();
	};
	extern U_Camera Camera;
}