#pragma once
#include <backend/includes.h>

namespace SDK::RR::Networking {
	struct NetworkedPlayer;

	struct RRPlayerNumbering {
		static Structs::Mono::Array<NetworkedPlayer*>* SortedPlayers();
	};
}