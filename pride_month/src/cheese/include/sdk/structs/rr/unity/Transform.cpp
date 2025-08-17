#include "Transform.h"

namespace SDK::RR::Unity {
	Structs::Unity::Vector3 Transform::get_position() {
		return Pointers::Unity::Transform.get_position[this].Invoke().Unbox();
	}

	Structs::Unity::Vector3 Transform::get_forward() {
		return Pointers::Unity::Transform.get_forward[this].Invoke().Unbox();
	}
}