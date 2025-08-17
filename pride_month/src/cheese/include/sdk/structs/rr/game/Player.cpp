#include "Player.h"

namespace SDK::RR::Game {
	Player* Player::get_LocalPlayer() {
		return (Player*)Pointers::Game::Player.get_LocalPlayer.Invoke().Get();
	}

	Player* Player::GetFromActorNumber(int actorNumber) {
		void* args[1] = { &actorNumber };
		return (Player*)Pointers::Game::Player.GetFromActorNumber.Invoke(args).Get();
	}

	bool Player::get_UsesFullBodyAvatar() {
		return Pointers::Game::Player.get_UsesFullBodyAvatar[this].Invoke().Unbox();
	}

	std::string Player::get_PlayerName() {
		return Pointers::Game::Player.get_PlayerName[this].Invoke().Get()->GetString();
	}

	PlayerHead* Player::get_Head() {
		return (PlayerHead*)Pointers::Game::Player.get_Head[this].Invoke().Get();
	}
	PlayerBody* Player::get_Body() {
		return (PlayerBody*)Pointers::Game::Player.get_Body[this].Invoke().Get();
	}
	PlayerHand* Player::get_LeftHand() {
		return (PlayerHand*)Pointers::Game::Player.get_LeftHand[this].Invoke().Get();
	}
	PlayerHand* Player::get_RightHand() {
		return (PlayerHand*)Pointers::Game::Player.get_RightHand[this].Invoke().Get();
	}
}