#include "backend.h"

void sdk::backend::setup() {
	Pointers::Game::Player.Setup();
	
	Pointers::Unity::Component.Setup();
	Pointers::Unity::Object.Setup();
	Pointers::Unity::GameObject.Setup();
	Pointers::Unity::Transform.Setup();
	Pointers::Unity::Camera.Setup();
	Pointers::Unity::Animator.Setup();

	Pointers::System::Type.Setup();

	Pointers::Networking::RRPlayerNumbering.Setup();
}