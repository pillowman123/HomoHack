#pragma once
#include <il2cpp/helpers/helpers.h>

namespace Pointers::System {
	struct U_Type {
		SDK::IL2CPP::Helpers::Class klass;

		SDK::IL2CPP::Helpers::Method<void*> GetType;

		void Setup();
	};
	extern U_Type Type;
}