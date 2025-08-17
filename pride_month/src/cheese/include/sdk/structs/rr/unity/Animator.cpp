#include "Animator.h"

namespace SDK::RR::Unity {
	Transform* Animator::GetBoneTransform(int humanBoneId) {
		void* args[1] = { &humanBoneId };
		return (Transform*)Pointers::Unity::Animator.GetBoneTransform[this].Invoke(args).Get();
	}

	Transform* Animator::GetBoneTransformInternal(int humanBoneId) {
		void* args[1] = { &humanBoneId };
		return (Transform*)Pointers::Unity::Animator.GetBoneTransformInternal[this].Invoke(args).Get();
	}
}