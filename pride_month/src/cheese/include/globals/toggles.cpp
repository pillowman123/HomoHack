#include "toggles.h"

namespace globals::toggles::movement {
	bool dynamicFly;
}

namespace globals::toggles::visuals {
	bool activateEsp;

	bool headLineEsp, lineEsp, topScreen, bottomScreen, overrideLineThickness;

	bool skeletonEsp, headCircles, overrideSkeletonThickness;

	bool boxEsp, dynamicBoxes, boxFilled, box3D, overrideBoxThickness;

	//I need to learn how to use unity raycast for visibility checks :3
	bool teamChecks, visibilityChecks;

	bool overrideLineColor, overrideSkeletonColor, overrideBoxColor;
	bool overrideEnemyTeamColors, overrideTeammateColors, overrideVisibilityColors;
}