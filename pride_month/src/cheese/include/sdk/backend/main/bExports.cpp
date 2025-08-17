#include "bExports.h"

namespace Pointers::Main {
	U_Exports Exports;

	void U_Exports::Setup(HMODULE module) {
		il2cpp_domain_get = (void* (*)()) reinterpret_cast<void**>((uint64_t)module + 0x9DF320);
		il2cpp_thread_attach = (void* (*)(void*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_thread_attach");
		il2cpp_thread_detach = (void(*)(void*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_thread_detach");

		il2cpp_domain_assembly_open = (void* (*)(void*, const char*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_domain_assembly_open");
		il2cpp_class_from_name = (void* (*)(void*, const char*, const char*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_class_from_name");
		il2cpp_class_get_method_from_name = (void* (*)(void*, const char*, int)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_class_get_method_from_name");
		il2cpp_class_get_field_from_name = (void* (*)(void*, const char*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_class_get_field_from_name");

		il2cpp_field_get_parent = (void* (*)(void*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_field_get_parent");
		il2cpp_field_get_offset = (size_t(*)(void*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_field_get_offset");
		il2cpp_field_get_value = (void(*)(void*, void*, void*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_field_get_value");
		il2cpp_field_set_value = (void(*)(void*, void*, void*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_field_set_value");
		il2cpp_field_static_get_value = (void(*)(void*, void*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_field_static_get_value");
		il2cpp_field_static_set_value = (void(*)(void*, void*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_field_static_set_value");

		il2cpp_runtime_invoke = (void* (*)(void*, void*, void**, void**)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_runtime_invoke");
		il2cpp_object_get_class = (void* (*)(void*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_object_get_class");
		il2cpp_object_new = (void* (*)(void*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_object_new");
		il2cpp_object_unbox = (void* (*)(void*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_object_unbox");
		il2cpp_value_box = (void* (*)(void*, void*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_value_box");
	
		il2cpp_string_new = (void* (*)(const char*)) spoof_call(globals::runtime::unitySpoof, GetProcAddress, module, "il2cpp_string_new");
	}
}