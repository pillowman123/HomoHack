#pragma once

namespace globals::toggles::movement {
	extern bool dynamicFly;
}

namespace globals::toggles::visuals {
	extern bool activateEsp;
	
	extern bool headLineEsp, lineEsp, topScreen, bottomScreen, overrideLineThickness;
	
	extern bool skeletonEsp, headCircles, overrideSkeletonThickness;

	extern bool boxEsp, dynamicBoxes, boxFilled, box3D, overrideBoxThickness;

	//I need to learn how to use unity raycast for visibility checks :3
	extern bool teamChecks, visibilityChecks;

	extern bool overrideLineColor, overrideSkeletonColor, overrideBoxColor;
	extern bool overrideEnemyTeamColors, overrideTeammateColors, overrideVisibilityColors;
}