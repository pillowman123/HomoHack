#include "Type.h"

namespace SDK::RR::System {
	Type* Type::GetType(const char* typeName) {
		auto typeNameString = IL2CPP::Il2CppString::New(typeName);
		void* args[1] = { typeNameString };
		return (Type*)Pointers::System::Type.GetType.Invoke(args).Get();
	}
}