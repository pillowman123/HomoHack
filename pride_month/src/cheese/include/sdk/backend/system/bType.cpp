#include "bType.h"

namespace Pointers::System {
	U_Type Type;

	void U_Type::Setup() {
		klass = { "mscorlib", "System", "Type" };

		GetType = klass.GetMethod("GetType", 1);
	}
}