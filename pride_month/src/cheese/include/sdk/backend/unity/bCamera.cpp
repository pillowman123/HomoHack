#include "bCamera.h"

namespace Pointers::Unity {
	U_Camera Camera;

	void U_Camera::Setup() {
		klass = { "UnityEngine.CoreModule", "UnityEngine", "Camera" };

		get_worldToCameraMatrix_Injected = klass.GetMethod("get_worldToCameraMatrix_Injected", 1);
		get_projectionMatrix_Injected = klass.GetMethod("get_projectionMatrix_Injected", 1);

		WorldToViewportPoint = klass.GetMethod("WorldToViewportPoint", 1);
		get_current = klass.GetMethod("get_current", 0);
	}
}