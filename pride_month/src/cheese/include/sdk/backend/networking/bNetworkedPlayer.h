#pragma once
#include <il2cpp/helpers/helpers.h>
#include <include/globals/obfnames.h>

namespace Pointers::Networking {
	struct U_NetworkedPlayer {
		SDK::IL2CPP::Helpers::Class klass;

		SDK::IL2CPP::Helpers::Method<int> get_ActorNumber;

		void Setup(SDK::IL2CPP::Il2CppObject* object);
	};
	extern U_NetworkedPlayer NetworkedPlayer;
}