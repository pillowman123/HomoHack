#pragma once
#include <il2cpp/helpers/helpers.h>
#include <structs/unity/unity_structs.h>

namespace Pointers::Unity {
	struct U_Transform {
		SDK::IL2CPP::Helpers::Class klass;

		SDK::IL2CPP::Helpers::Method<SDK::Structs::Unity::Vector3> get_position;
		SDK::IL2CPP::Helpers::Method<SDK::Structs::Unity::Vector3> get_forward;

		void Setup();
	};
	extern U_Transform Transform;
}