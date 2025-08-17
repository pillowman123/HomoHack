#pragma once
#include <il2cpp/helpers/helpers.h>
#include <structs/mono/mono_structs.h>

namespace Pointers::Networking {
	struct U_RRPlayerNumbering {
		SDK::IL2CPP::Helpers::Class klass;

		SDK::IL2CPP::Helpers::Field<SDK::Structs::Mono::Array<void**>*> SortedPlayers;

		void Setup();
	};

	extern U_RRPlayerNumbering RRPlayerNumbering;
}

