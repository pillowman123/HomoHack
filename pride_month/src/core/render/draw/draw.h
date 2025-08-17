#pragma once
#include <cmath>
#include <imgui.h>
#include <rr.h>


namespace render::draw {
	extern void DrawLine(ImVec2 start, ImVec2 end, ImVec4 color, float thickness = 1.0f);
	extern void DrawLine(ImVec2 start, ImVec2 end, ImVec4 color, float thickness, ImDrawList* drawList);

	extern void DrawBox(float x, float y, float width, float height, ImVec4 color, float thickness = 1.0f);
	extern void DrawBox(float x, float y, float width, float height, ImVec4 color, float thickness, ImDrawList* drawList);

	extern void DrawFilledBox(float x, float y, float width, float height, ImVec4 boxColor, ImVec4 filledBoxColor, float thickness = 1.0f);
	extern void DrawFilledBox(float x, float y, float width, float height, ImVec4 boxColor, ImVec4 filledBoxColor, float thickness, ImDrawList* drawList);

	extern void Draw3DBox(SDK::RR::Unity::Camera* camera, SDK::Structs::Unity::Vector3 origin, float boxHeight, float boxWidth, float thickness, ImVec4 boxColor);
}