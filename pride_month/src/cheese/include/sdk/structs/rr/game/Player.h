#pragma once
#include <backend/includes.h>
#include <networking/empty/RRNetworkBehavior.h>

namespace SDK::RR::Game {
	struct PlayerHead : Networking::RRNetworkBehavior {};
	struct PlayerBody : Unity::MonoBehaviour {};
	struct PlayerHand : Networking::RRNetworkBehavior {};

	struct Player : Networking::RRNetworkBehavior {
		static Player* get_LocalPlayer();
		static Player* GetFromActorNumber(int actorNumber);

		PlayerHead* get_Head();
		PlayerBody* get_Body();
		PlayerHand* get_LeftHand();
		PlayerHand* get_RightHand();

		bool get_UsesFullBodyAvatar();
		std::string get_PlayerName();
	};
}