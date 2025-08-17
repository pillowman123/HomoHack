#include "movement.h"

//example:
void (*old_RandomUpdate)(void* instance);
void RandomUpdate(void* instance) {
	if (instance)
		cheats::movement::run();
	return old_RandomUpdate(instance);
}


bool (*old_IsFlyingEnabled)(void* instance);
bool IsFlyingEnabled(void* instance) {
	return true;
}


void cheats::movement::setup() {

	cheese::utils::hook(cheese::utils::getAbsoluteAddress(0x19DF7E0),
						(void*)IsFlyingEnabled, (void**)&old_IsFlyingEnabled);
}


void cheats::movement::run() {

}