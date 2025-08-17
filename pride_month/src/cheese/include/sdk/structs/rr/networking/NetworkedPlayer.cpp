#include "NetworkedPlayer.h"

namespace SDK::RR::Networking {
	int NetworkedPlayer::get_ActorNumber() {
		return Pointers::Networking::NetworkedPlayer.get_ActorNumber[this].Invoke().Unbox();
	}
}