#include "bPlayer.h"

namespace Pointers::Game {
	U_Player Player;

	void U_Player::Setup() {
		klass = { "Assembly-CSharp", "", "Player" };

		get_LocalPlayer = klass.GetMethod("get_LocalPlayer", 0);
		
		get_Head = klass.GetMethod("get_Head", 0);
		get_Body = klass.GetMethod("get_Body", 0);
		get_LeftHand = klass.GetMethod("get_LeftHand", 0);
		get_RightHand = klass.GetMethod("get_RightHand", 0);

		get_UsesFullBodyAvatar = klass.GetMethod("get_UsesFullBodyAvatar", 0);
		get_PlayerName = klass.GetMethod("get_PlayerName", 0);

		GetFromActorNumber = klass.GetMethod("GetFromActorNumber", 1);
		GetFromViewId = klass.GetMethod("GetFromViewId", 1);
	}
}