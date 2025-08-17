#include "bComponent.h"

namespace Pointers::Unity {
	U_Component Component;

	void U_Component::Setup() {
		klass = { "UnityEngine.CoreModule", "UnityEngine", "Component" };

		get_transform = klass.GetMethod("get_transform", 0);
		get_gameObject = klass.GetMethod("get_gameObject", 0);
		GetComponent = klass.GetMethod("GetComponent", 1);
		GetComponentsInChildren = klass.GetMethod("GetComponentsInChildren", 1);
	}
}