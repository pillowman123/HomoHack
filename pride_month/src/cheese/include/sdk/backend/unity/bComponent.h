#pragma once
#include <il2cpp/helpers/helpers.h>
#include <structs/mono/mono_structs.h>

namespace Pointers::Unity {
	struct U_Component {
		SDK::IL2CPP::Helpers::Class klass;

		SDK::IL2CPP::Helpers::Method<void*> get_transform;
		SDK::IL2CPP::Helpers::Method<void*> get_gameObject;
		SDK::IL2CPP::Helpers::Method<void*> GetComponent;
		SDK::IL2CPP::Helpers::Method<SDK::Structs::Mono::Array<void*>*> GetComponentsInChildren;

		void Setup();
	};
	extern U_Component Component;
}