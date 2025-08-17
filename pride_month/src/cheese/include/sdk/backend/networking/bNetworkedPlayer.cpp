#include "bNetworkedPlayer.h"

namespace Pointers::Networking {
	U_NetworkedPlayer NetworkedPlayer;

	void U_NetworkedPlayer::Setup(SDK::IL2CPP::Il2CppObject* object) {
		klass = object->GetClass();

		get_ActorNumber = klass.GetMethod(globals::obfuscated::method::networkedPlayerActorNumber.c_str(), 0);
	}
}