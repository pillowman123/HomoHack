#pragma once
#include <imgui.h>
#include <backend/includes.h>
#include <unity/empty/Behaviour.h>


namespace SDK::RR::Unity {
	struct Camera : Behaviour {
		static Camera* get_current();

		//get_worldToCameraMatrix_Injected
		void GetWorldToCameraMatrix(SDK::Structs::Unity::Matrix4x4& ret);
		void GetProjectionMatrix(SDK::Structs::Unity::Matrix4x4& ret);

		SDK::Structs::Unity::Vector3 WorldToScreenPoint(Structs::Unity::Vector3 position);
	};
}