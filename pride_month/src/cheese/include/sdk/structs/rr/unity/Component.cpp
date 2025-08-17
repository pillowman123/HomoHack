#include "Component.h"

namespace SDK::RR::Unity {
	Transform* Component::get_transform() {
		return (Transform*)Pointers::Unity::Component.get_transform[this].Invoke().Get();
	}

	GameObject* Component::get_gameObject() {
		return (GameObject*)Pointers::Unity::Component.get_gameObject[this].Invoke().Get();
	}
}