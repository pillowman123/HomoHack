#include "bTransform.h"

namespace Pointers::Unity {
	U_Transform Transform;

	void U_Transform::Setup() {
		klass = { "UnityEngine.CoreModule", "UnityEngine", "Transform" };

		get_position = klass.GetMethod("get_position", 0);
		get_forward = klass.GetMethod("get_forward", 0);
	}
}