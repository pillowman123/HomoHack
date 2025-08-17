#pragma once
#include <backend/includes.h>

namespace SDK::RR::System {
	struct Type {
		static Type* GetType(const char* typeName);
	};
}