#include "bGameObject.h"

namespace Pointers::Unity {
	U_GameObject GameObject;

	void U_GameObject::Setup() {
		klass = { "UnityEngine.CoreModule", "UnityEngine", "GameObject" };

		GetComponent = klass.GetMethod("GetComponent", 1);
		GetComponentsInChildren = klass.GetMethod("GetComponentsInChildren", 1);
	}
}