#pragma once
#include <backend/includes.h>
#include <structs/mono/mono_structs.h>

namespace Pointers::Unity {
	struct U_Object {
		SDK::IL2CPP::Helpers::Class klass;

		SDK::IL2CPP::Helpers::Method<SDK::Structs::Mono::String*> get_name;

		void Setup();
	};
	extern U_Object Object;
}