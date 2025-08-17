#include "bAnimator.h"

namespace Pointers::Unity {
	U_Animator Animator;

	void U_Animator::Setup() {
		klass = { "UnityEngine.AnimationModule", "UnityEngine", "Animator" };

		GetBoneTransform = klass.GetMethod("GetBoneTransform", 1);
		GetBoneTransformInternal = klass.GetMethod("GetBoneTransformInternal", 1);
	}
}