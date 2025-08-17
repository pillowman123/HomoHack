#include "RRPlayerNumbering.h"

namespace SDK::RR::Networking {
	Structs::Mono::Array<NetworkedPlayer*>* RRPlayerNumbering::SortedPlayers() {
		return (Structs::Mono::Array<NetworkedPlayer*>*)Pointers::Networking::RRPlayerNumbering.SortedPlayers.Get();
	}
}