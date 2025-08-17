#include "bypass.h"

void cheese::bypass::run() {
	utils::retPatch(utils::getAbsoluteAddressTargeted("Referee.dll", globals::offsets::referee::checkOne));
	utils::retPatch(utils::getAbsoluteAddressTargeted("Referee.dll", globals::offsets::referee::checkTwo));
	utils::retPatch(utils::getAbsoluteAddressTargeted("Referee.dll", globals::offsets::referee::checkThree));
}