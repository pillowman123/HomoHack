#include "Object.h"

namespace SDK::RR::Unity {
	std::string Object::get_name() {
		return Pointers::Unity::Object.get_name[this].Invoke().Get()->GetString();
	}
}