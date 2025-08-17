#include "Camera.h"

//credits: @euxx. I got this in priv ios modding server :3
void MultiplyMatrixVec(const SDK::Structs::Unity::Matrix4x4& m, const float in[4], float out[4]) {
	for (int i = 0; i < 4; ++i) {
		out[i] = m.m[0][i] * in[0] + m.m[1][i] * in[1] + m.m[2][i] * in[2] + m.m[3][i] * in[3];
	}
}


namespace SDK::RR::Unity {
	Camera* Camera::get_current() {
		return (Camera*)Pointers::Unity::Camera.get_current.Invoke().Get();
	}

	void Camera::GetWorldToCameraMatrix(SDK::Structs::Unity::Matrix4x4& ret) {
		void* args[1] = { &ret };
		Pointers::Unity::Camera.get_worldToCameraMatrix_Injected[this].Invoke(args);
	}

	void Camera::GetProjectionMatrix(SDK::Structs::Unity::Matrix4x4& ret) {
		void* args[1] = { &ret };
		Pointers::Unity::Camera.get_projectionMatrix_Injected[this].Invoke(args);
	}


	Structs::Unity::Vector3 Camera::WorldToScreenPoint(Structs::Unity::Vector3 position) {
		auto displaySize = ImGui::GetIO().DisplaySize;
		
		void* args[1] = { &position };
		auto screenPosition = Pointers::Unity::Camera.WorldToViewportPoint[this].Invoke(args).Unbox();

		//reference: https://iosgods.com/topic/168407-universal-esp-hack-for-all-fps-games-unity3d-h5gg-no-jb/
		if (screenPosition.Z > 1.f) {
			screenPosition.X *= displaySize.x;
			screenPosition.Y = displaySize.y * (1 - screenPosition.Y);
		}

		return screenPosition;
	}
}