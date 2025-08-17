#include "bObject.h"

namespace Pointers::Unity {
	U_Object Object;

	void U_Object::Setup() {
		klass = { "UnityEngine.CoreModule", "UnityEngine", "Object" };

		get_name = klass.GetMethod("get_name", 0);
	}
}