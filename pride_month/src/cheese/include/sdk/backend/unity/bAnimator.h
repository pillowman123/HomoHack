#pragma once
#include <il2cpp/helpers/helpers.h>

namespace Pointers::Unity {
	struct U_Animator {
		SDK::IL2CPP::Helpers::Class klass;

		SDK::IL2CPP::Helpers::Method<void*> GetBoneTransform;
		SDK::IL2CPP::Helpers::Method<void*> GetBoneTransformInternal;

		void Setup();
	};
	extern U_Animator Animator;
}