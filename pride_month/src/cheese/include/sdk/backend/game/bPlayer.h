#pragma once
#include <il2cpp/helpers/helpers.h>
#include <structs/mono/mono_structs.h>

namespace Pointers::Game {
	struct U_Player {
		SDK::IL2CPP::Helpers::Class klass;
		
		SDK::IL2CPP::Helpers::Method<void*> get_LocalPlayer;

		SDK::IL2CPP::Helpers::Method<void*> get_Head;
		SDK::IL2CPP::Helpers::Method<void*> get_Body;
		SDK::IL2CPP::Helpers::Method<void*> get_LeftHand;
		SDK::IL2CPP::Helpers::Method<void*> get_RightHand;

		SDK::IL2CPP::Helpers::Method<bool> get_UsesFullBodyAvatar;
		SDK::IL2CPP::Helpers::Method<SDK::Structs::Mono::String*> get_PlayerName;

		SDK::IL2CPP::Helpers::Method<void*> GetFromActorNumber;
		SDK::IL2CPP::Helpers::Method<void*> GetFromViewId;

		void Setup();
	};
	extern U_Player Player;
}