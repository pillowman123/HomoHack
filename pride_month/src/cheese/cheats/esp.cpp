#include "esp.h"

#undef max
#undef min

bool isCordsOnScreen(SDK::Structs::Unity::Vector3& screenPosition) {
	return (screenPosition.Z > 1.0f);
}

float fixedScaleFromDistance(float a, SDK::Structs::Unity::Vector3 basePosition, SDK::Structs::Unity::Vector3 targetPosition) {
	return (a / SDK::Structs::Unity::Vector3::Distance(basePosition, targetPosition));
}

const char* formattedText(const char* fmt, ...)
{
	char buffer[256];

	va_list args{};
	va_start(args, fmt);
	vsprintf_s(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	return buffer;
}

void cheats::esp::run(SDK::RR::Game::Player* player) {
	ImVec2 centerScreen = { ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2 };
	ImVec2 bottomScreen = { ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y };
	ImVec2 topScreen = { ImGui::GetIO().DisplaySize.x / 2, 0.f };

	if (!player)
		return;

	auto background = ImGui::GetBackgroundDrawList();
	if (!background)
		return;

	auto camera = SDK::RR::Unity::Camera::get_current();
	if (!camera)
		return;


	bool usesFullBodyAvatar = player->get_UsesFullBodyAvatar();

	auto head = player->get_Head();
	auto body = player->get_Body();

	if (!head || !body)
		return;

	auto leftHand = player->get_LeftHand();
	auto rightHand = player->get_RightHand();

	if (!leftHand || !rightHand)
		return;

	auto cameraTransform = camera->get_transform();

	auto headTransform = head->get_transform();
	auto bodyTransform = body->get_transform();
	auto leftHandTransform = leftHand->get_transform();
	auto rightHandTransform = rightHand->get_transform();

	if (cameraTransform && headTransform && bodyTransform && leftHandTransform && rightHandTransform) {
		SDK::Structs::Unity::Vector3 cameraPosition = cameraTransform->get_position();

		SDK::Structs::Unity::Vector3 headPosition = headTransform->get_position();
		SDK::Structs::Unity::Vector3 headScreenPosition = camera->WorldToScreenPoint(headPosition);

		SDK::Structs::Unity::Vector3 headLinePosition = headTransform->get_position() + headTransform->get_forward();
		SDK::Structs::Unity::Vector3 headLineScreenPosition = camera->WorldToScreenPoint(headLinePosition);

		SDK::Structs::Unity::Vector3 headSkeletonPosition = headPosition - SDK::Structs::Unity::Vector3(0, 0.15, 0);
		SDK::Structs::Unity::Vector3 headSkeletonScreenPosition = camera->WorldToScreenPoint(headSkeletonPosition);

		SDK::Structs::Unity::Vector3 headBoxPosition = headPosition + SDK::Structs::Unity::Vector3(0, 0.3, 0);
		SDK::Structs::Unity::Vector3 headScreenPositionBox = camera->WorldToScreenPoint(headBoxPosition);

		SDK::Structs::Unity::Vector3 bodyPosition = bodyTransform->get_position();
		SDK::Structs::Unity::Vector3 bodyScreenPosition = camera->WorldToScreenPoint(bodyPosition);

		SDK::Structs::Unity::Vector3 bodyBoxPosition = 
			(usesFullBodyAvatar)
			? bodyPosition - SDK::Structs::Unity::Vector3(0, 0.88, 0)
			: bodyPosition - SDK::Structs::Unity::Vector3(0.1, 0.430, 0);

		SDK::Structs::Unity::Vector3 bodyScreenPositionBox = camera->WorldToScreenPoint(bodyBoxPosition);

		SDK::Structs::Unity::Vector3 bodyBoxPosition3D =
			(usesFullBodyAvatar)
			? bodyPosition - SDK::Structs::Unity::Vector3(0, 0.88, 0)
			: bodyPosition - SDK::Structs::Unity::Vector3(0, 0.430, 0);

		SDK::Structs::Unity::Vector3 leftHandPosition = leftHandTransform->get_position();
		SDK::Structs::Unity::Vector3 leftHandScreenPosition = camera->WorldToScreenPoint(leftHandPosition);

		SDK::Structs::Unity::Vector3 rightHandPosition = rightHandTransform->get_position();
		SDK::Structs::Unity::Vector3 rightHandScreenPosition = camera->WorldToScreenPoint(rightHandPosition);

		background->ChannelsSplit(4);

		if (globals::toggles::visuals::headLineEsp && isCordsOnScreen(headScreenPosition) && isCordsOnScreen(headLineScreenPosition)) {
			background->ChannelsSetCurrent(2); //head lines get priority below skeletons

			render::draw::DrawLine({ headScreenPosition.X, headScreenPosition.Y }, { headLineScreenPosition.X, headLineScreenPosition.Y }, { 1.0f, 1.0f, 1.0f, 1.0f }, 1.0f);
		}

		if (globals::toggles::visuals::lineEsp && isCordsOnScreen(headScreenPosition)) {
			background->ChannelsSetCurrent(1); //lines get nearest to low priority

			ImVec2 usedDrawPoint{};
			float usedLineThickness = (globals::toggles::visuals::overrideLineThickness) ? globals::modifiers::visuals::lineThickness : 1.f;

			if (globals::toggles::visuals::topScreen)
				usedDrawPoint = topScreen;
			else if (globals::toggles::visuals::bottomScreen)
				usedDrawPoint = bottomScreen;
			else
				usedDrawPoint = centerScreen;

			render::draw::DrawLine(usedDrawPoint, { headScreenPosition.X, headScreenPosition.Y }, { 1.0f, 1.0f, 1.0f, 1.0f }, usedLineThickness);
		}

		if (globals::toggles::visuals::skeletonEsp && isCordsOnScreen(headScreenPosition) && isCordsOnScreen(headSkeletonScreenPosition)
			&& isCordsOnScreen(bodyScreenPosition) && isCordsOnScreen(leftHandScreenPosition)
			&& isCordsOnScreen(rightHandScreenPosition)) {

			background->ChannelsSetCurrent(3); //skeletons get highest priority

			float usedSkeletonThickness = (globals::toggles::visuals::overrideSkeletonThickness) ? globals::modifiers::visuals::skeletonThickness : 1.f;
			float usedCircleRadius = 145.0f;

			float fixedSkeletonThickness = fixedScaleFromDistance(usedSkeletonThickness, cameraPosition, headPosition);
			float fixedCircleRadius = fixedScaleFromDistance(usedCircleRadius, cameraPosition, headPosition);

			if (globals::toggles::visuals::headCircles)
				background->AddCircle(ImVec2(headScreenPosition.X, headScreenPosition.Y), fixedCircleRadius, ImColor(255, 255, 255, 255), 360, fixedSkeletonThickness);

			render::draw::DrawLine({ headSkeletonScreenPosition.X, headSkeletonScreenPosition.Y }, { bodyScreenPosition.X, bodyScreenPosition.Y }, { 1.0f, 1.0f, 1.0f, 5.0f }, fixedSkeletonThickness, background);
			render::draw::DrawLine({ bodyScreenPosition.X, bodyScreenPosition.Y }, { leftHandScreenPosition.X, leftHandScreenPosition.Y }, { 1.0f, 1.0f, 1.0f, 1.0f }, fixedSkeletonThickness, background);
			render::draw::DrawLine({ bodyScreenPosition.X, bodyScreenPosition.Y }, { rightHandScreenPosition.X, rightHandScreenPosition.Y }, { 1.0f, 1.0f, 1.0f, 1.0f }, fixedSkeletonThickness, background);
		}

		if (globals::toggles::visuals::boxEsp && isCordsOnScreen(headScreenPositionBox) && isCordsOnScreen(bodyScreenPositionBox)) {
			float usedBoxThickness = (globals::toggles::visuals::overrideBoxThickness) ? globals::modifiers::visuals::boxThickness : 1.0f;

			background->ChannelsSetCurrent(0); //boxes get lowest priority

			float boxHeight = std::abs(headScreenPositionBox.Y - bodyScreenPositionBox.Y);

			float desiredFullbodyHeight2D = 0.35f;
			float desiredBeanHeight2D = 0.50f;
			float staticBoxWidth = (usesFullBodyAvatar) ? boxHeight * desiredFullbodyHeight2D : boxHeight * desiredBeanHeight2D;

			float minScreenX = std::min({ leftHandScreenPosition.X, rightHandScreenPosition.X, headScreenPositionBox.X, bodyScreenPositionBox.X });
			float maxScreenX = std::max({ leftHandScreenPosition.X, rightHandScreenPosition.X, headScreenPositionBox.X, bodyScreenPositionBox.X });
			float dynamicBoxWidth = (maxScreenX - minScreenX);

			float usedBoxWidth =
				(globals::toggles::visuals::dynamicBoxes)
				? dynamicBoxWidth
				: staticBoxWidth;

			SDK::Structs::Unity::Vector2 usedBox =
				(globals::toggles::visuals::dynamicBoxes)
				? SDK::Structs::Unity::Vector2(minScreenX, headScreenPositionBox.Y)
				: SDK::Structs::Unity::Vector2(headScreenPositionBox.X - (staticBoxWidth / 2), headScreenPositionBox.Y);

			if (globals::toggles::visuals::boxFilled)
				render::draw::DrawFilledBox(usedBox.X, usedBox.Y, usedBoxWidth, boxHeight, ImVec4{ 1.0f, 1.0f, 1.0f, 1.0f }, ImVec4{ 0.0f, 0.0f, 0.0f, 0.0f }, usedBoxThickness, background);
			else if (globals::toggles::visuals::box3D) {
				
				float desiredFullBodyHeight3D = 1.58f;
				float desiredFullBodyWidth3D = 0.25f;

				float desiredBeanHeight3D = 1.2f;
				float desiredBeanWidth3D = 0.3f;

				float box3DHeight = (usesFullBodyAvatar) ? desiredFullBodyHeight3D : desiredBeanHeight3D;
				float box3DWidth = (usesFullBodyAvatar) ? desiredFullBodyWidth3D : desiredBeanWidth3D;

				render::draw::Draw3DBox(camera, bodyBoxPosition3D, box3DHeight, box3DWidth, usedBoxThickness, {1.0f, 1.0f, 1.0f, 1.0f});
			}
			else
				render::draw::DrawBox(usedBox.X, usedBox.Y, usedBoxWidth, boxHeight, ImVec4{ 1.0f, 1.0f, 1.0f, 1.0f }, usedBoxThickness);
		}

		background->ChannelsMerge();
	}
}