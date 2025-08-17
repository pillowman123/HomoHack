#pragma once
#include "Component.h"

namespace SDK::RR::Unity {
	struct Transform : Component {
		Structs::Unity::Vector3 get_position();
		Structs::Unity::Vector3 get_forward();
	};
}