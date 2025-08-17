#pragma once
#include <backend/includes.h>
#include <unity/empty/Behaviour.h>

namespace SDK::RR::Unity {
	struct Animator : Behaviour {
		Transform* GetBoneTransform(int humanBoneId);
		Transform* GetBoneTransformInternal(int humanBoneId);
	};
}