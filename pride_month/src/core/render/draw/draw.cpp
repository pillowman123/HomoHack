#include "draw.h"

#define TORAD(deg) ((deg) * (M_PI / 180.0))

void render::draw::DrawLine(ImVec2 start, ImVec2 end, ImVec4 color, float thickness) {
	auto background = ImGui::GetBackgroundDrawList();
	if (background) {
		background->AddLine(start, end, ImColor(color.x, color.y, color.z, color.w), thickness);
	}
}

void render::draw::DrawLine(ImVec2 start, ImVec2 end, ImVec4 color, float thickness, ImDrawList* drawList) {
	if (drawList) {
		drawList->AddLine(start, end, ImColor(color.x, color.y, color.z, color.w), thickness);
	}
}

void render::draw::DrawBox(float x, float y, float width, float height, ImVec4 color, float thickness) {
	auto background = ImGui::GetBackgroundDrawList();
	if (background) {
		background->AddRect(ImVec2(x, y), ImVec2(x + width, y + height), ImColor(color.x, color.y, color.z, color.w), 0.0f, 0, thickness);
	}
}

void render::draw::DrawBox(float x, float y, float width, float height, ImVec4 color, float thickness, ImDrawList* drawList) {
	if (drawList) {
		drawList->AddRect(ImVec2(x, y), ImVec2(x + width, y + height), ImColor(color.x, color.y, color.z, color.w), 0.0f, 0, thickness);
	}
}

void render::draw::DrawFilledBox(float x, float y, float width, float height, ImVec4 boxColor, ImVec4 filledBoxColor, float thickness) {
	auto background = ImGui::GetBackgroundDrawList();
	if (background) {
		background->AddRectFilled(ImVec2(x, y - 1), ImVec2(x + width, y + height), ImColor(filledBoxColor.x, filledBoxColor.y, filledBoxColor.z, 0.07), 0, 0);
		background->AddRectFilled(ImVec2(x, y + 1), ImVec2(x + width, y + height), ImColor(filledBoxColor.x, filledBoxColor.y, filledBoxColor.z, 0.07), 0, 0);
		background->AddRectFilled(ImVec2(x - 1, y), ImVec2(x + width, y + height), ImColor(filledBoxColor.x, filledBoxColor.y, filledBoxColor.z, 0.07), 0, 0);
		background->AddRectFilled(ImVec2(x + 1, y), ImVec2(x + width, y + height), ImColor(filledBoxColor.x, filledBoxColor.y, filledBoxColor.z, 0.07), 0, 0);
		background->AddRectFilled(ImVec2(x, y), ImVec2(x + width, y + height), ImColor(filledBoxColor.x, filledBoxColor.y, filledBoxColor.z, 0.07), 0, 0);

		background->AddRect(ImVec2(x, y), ImVec2(x + width, y + height), ImColor(boxColor.x, boxColor.y, boxColor.z, 1.0), 0, 0);
	}
}

void render::draw::DrawFilledBox(float x, float y, float width, float height, ImVec4 boxColor, ImVec4 filledBoxColor, float thickness, ImDrawList* drawList) {
	if (drawList) {
		drawList->AddRectFilled(ImVec2(x, y - 1), ImVec2(x + width, y + height), ImColor(filledBoxColor.x, filledBoxColor.y, filledBoxColor.z, 0.07), 0, 0);
		drawList->AddRectFilled(ImVec2(x, y + 1), ImVec2(x + width, y + height), ImColor(filledBoxColor.x, filledBoxColor.y, filledBoxColor.z, 0.07), 0, 0);
		drawList->AddRectFilled(ImVec2(x - 1, y), ImVec2(x + width, y + height), ImColor(filledBoxColor.x, filledBoxColor.y, filledBoxColor.z, 0.07), 0, 0);
		drawList->AddRectFilled(ImVec2(x + 1, y), ImVec2(x + width, y + height), ImColor(filledBoxColor.x, filledBoxColor.y, filledBoxColor.z, 0.07), 0, 0);
		drawList->AddRectFilled(ImVec2(x, y), ImVec2(x + width, y + height), ImColor(filledBoxColor.x, filledBoxColor.y, filledBoxColor.z, 0.07), 0, 0);

		drawList->AddRect(ImVec2(x, y), ImVec2(x + width, y + height), ImColor(boxColor.x, boxColor.y, boxColor.z, 1.0), 0, 0, thickness);
	}
}

void render::draw::Draw3DBox(SDK::RR::Unity::Camera* camera, SDK::Structs::Unity::Vector3 origin, float boxHeight, float boxWidth, float thickness, ImVec4 boxColor) {
    //Reference: https://github.com/springmusk026/ImGui-Esp-3DBox/blob/main/Box.c

    // Define the 8 corners of the box in 3D space (relative to origin)
    float widthFix = 0.0f; //0.1f;

    SDK::Structs::Unity::Vector3 topFrontRight = origin + SDK::Structs::Unity::Vector3(boxWidth, boxHeight, boxWidth);
    SDK::Structs::Unity::Vector3 bottomFrontRight = origin + SDK::Structs::Unity::Vector3(boxWidth, 0.0f, boxWidth);
    SDK::Structs::Unity::Vector3 bottomFrontLeft = origin + SDK::Structs::Unity::Vector3(-(boxWidth - widthFix), 0.0f, boxWidth);
    SDK::Structs::Unity::Vector3 topFrontLeft = origin + SDK::Structs::Unity::Vector3(-(boxWidth - widthFix), boxHeight, boxWidth);

    SDK::Structs::Unity::Vector3 topBackRight = origin + SDK::Structs::Unity::Vector3(boxWidth, boxHeight, -0.0f) + SDK::Structs::Unity::Vector3(0.0f, 0.0f, -boxWidth);
    SDK::Structs::Unity::Vector3 bottomBackRight = origin + SDK::Structs::Unity::Vector3(boxWidth, 0.0f, -0.0f) + SDK::Structs::Unity::Vector3(0.0f, 0.0f, -boxWidth);
    SDK::Structs::Unity::Vector3 bottomBackLeft = origin + SDK::Structs::Unity::Vector3(-(boxWidth - widthFix), 0.0f, -0.0f) + SDK::Structs::Unity::Vector3(0.0f, 0.0f, -boxWidth);
    SDK::Structs::Unity::Vector3 topBackLeft = origin + SDK::Structs::Unity::Vector3(-(boxWidth - widthFix), boxHeight, -0.0f) + SDK::Structs::Unity::Vector3(0.0f, 0.0f, -boxWidth);

    //convert each box point to screen pos
    SDK::Structs::Unity::Vector3 screenPoints[8] = {
        camera->WorldToScreenPoint(topFrontRight),
        camera->WorldToScreenPoint(bottomFrontRight),
        camera->WorldToScreenPoint(bottomFrontLeft),
        camera->WorldToScreenPoint(topFrontLeft),
        camera->WorldToScreenPoint(topBackRight),
        camera->WorldToScreenPoint(bottomBackRight),
        camera->WorldToScreenPoint(bottomBackLeft),
        camera->WorldToScreenPoint(topBackLeft)
    };

    //verify if each point is on screen
    for (const auto& p : screenPoints)
        if (p.Z <= 1.0f)
            return;

    auto toVector = [&](const SDK::Structs::Unity::Vector3& point) -> ImVec2 {
        return ImVec2(point.X, point.Y);
    };

    ImColor color = { boxColor.x, boxColor.y, boxColor.z, boxColor.w };

	auto background = ImGui::GetBackgroundDrawList();
	if (background) {
        // Front face
        background->AddLine(toVector(screenPoints[0]), toVector(screenPoints[1]), color, thickness); // TopRight - BottomRight
        background->AddLine(toVector(screenPoints[1]), toVector(screenPoints[2]), color, thickness); // BottomRight - BottomLeft
        background->AddLine(toVector(screenPoints[2]), toVector(screenPoints[3]), color, thickness); // BottomLeft - TopLeft
        background->AddLine(toVector(screenPoints[3]), toVector(screenPoints[0]), color, thickness); // TopLeft - TopRight

        // Back face
        background->AddLine(toVector(screenPoints[4]), toVector(screenPoints[5]), color, thickness); // TopRight - BottomRight
        background->AddLine(toVector(screenPoints[5]), toVector(screenPoints[6]), color, thickness); // BottomRight - BottomLeft
        background->AddLine(toVector(screenPoints[6]), toVector(screenPoints[7]), color, thickness); // BottomLeft - TopLeft
        background->AddLine(toVector(screenPoints[7]), toVector(screenPoints[4]), color, thickness); // TopLeft - TopRight

        // Connect front and back faces
        background->AddLine(toVector(screenPoints[0]), toVector(screenPoints[4]), color, thickness); // TopFrontRight - TopBackRight
        background->AddLine(toVector(screenPoints[1]), toVector(screenPoints[5]), color, thickness); // BottomFrontRight - BottomBackRight
        background->AddLine(toVector(screenPoints[2]), toVector(screenPoints[6]), color, thickness); // BottomFrontLeft - BottomBackLeft
        background->AddLine(toVector(screenPoints[3]), toVector(screenPoints[7]), color, thickness); // TopFrontLeft - TopBackLeft
	}
}