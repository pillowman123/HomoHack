#include "gui.h"


void render::gui::draw() {
	if (!gui_base::isOpened)
		return;

	ImGui::Begin("HomoHack Beta | @PotatoIsCool & @pillowguy._.");
	{
		ImGui::Text("Turn off the cheats man!");

		if (ImGui::BeginTabBar("##tabs"))
		{
			if (ImGui::BeginTabItem("Visuals"))
			{
				ImGui::Checkbox("Activate ESP", &globals::toggles::visuals::activateEsp);
				if (globals::toggles::visuals::activateEsp) {
					ImGui::Indent(5);
					{
						ImGui::Checkbox("Head Lines", &globals::toggles::visuals::headLineEsp);
						ImGui::Checkbox("Lines", &globals::toggles::visuals::lineEsp);
						if (globals::toggles::visuals::lineEsp) {
							ImGui::Indent(10);
							{
								if (ImGui::Checkbox("Top Screen", &globals::toggles::visuals::topScreen))
									if (globals::toggles::visuals::bottomScreen)
										globals::toggles::visuals::bottomScreen = false;

								if (ImGui::Checkbox("Bottom Screen", &globals::toggles::visuals::bottomScreen))
									if (globals::toggles::visuals::topScreen)
										globals::toggles::visuals::topScreen = false;

								ImGui::Checkbox("Override Thickness ##Lines", &globals::toggles::visuals::overrideLineThickness);

								if (globals::toggles::visuals::overrideLineThickness) {
									ImGui::Indent(14);
									{
										ImGui::PushItemWidth(145.0f);
										ImGui::SliderFloat("Thickness ##Lines", &globals::modifiers::visuals::lineThickness, 1.0f, 3.0f);
										ImGui::PopItemWidth();
									}
									ImGui::Unindent(14);
								}
							}
							ImGui::Unindent(10);
						}
						ImGui::Checkbox("Skeletons", &globals::toggles::visuals::skeletonEsp);

						if (globals::toggles::visuals::skeletonEsp) {
							ImGui::Indent(10);
							{
								ImGui::Checkbox("Head Circles", &globals::toggles::visuals::headCircles);
								ImGui::Checkbox("Override Thickness ##Skeletons", &globals::toggles::visuals::overrideSkeletonThickness);
								if (globals::toggles::visuals::overrideSkeletonThickness) {
									ImGui::Indent(14);
									{
										ImGui::PushItemWidth(145.0f);
										ImGui::SliderFloat("Thickness ##Skeletons", &globals::modifiers::visuals::skeletonThickness, 1.0f, 25.0f);
										ImGui::PopItemWidth();
									}
									ImGui::Unindent(14);
								}
							}
							ImGui::Unindent(10);
						}

						ImGui::Checkbox("Boxes", &globals::toggles::visuals::boxEsp);
						if (globals::toggles::visuals::boxEsp) {
							ImGui::Indent(10);
							{
								ImGui::Checkbox("Dynamic Box (Beta)", &globals::toggles::visuals::dynamicBoxes);

								ImGui::SeparatorText("Modes");

								if (ImGui::Checkbox("Filled ##boxes", &globals::toggles::visuals::boxFilled))
									if (globals::toggles::visuals::box3D)
										globals::toggles::visuals::box3D = false;

								if (ImGui::Checkbox("3D Boxes (Beta)", &globals::toggles::visuals::box3D))
									if (globals::toggles::visuals::boxFilled)
										globals::toggles::visuals::boxFilled = false;


								ImGui::Checkbox("Override Thickness ##Boxes", &globals::toggles::visuals::overrideBoxThickness);
								if (globals::toggles::visuals::overrideBoxThickness) {
									ImGui::Indent(14);
									{
										ImGui::SliderFloat("Thickness ##Boxes", &globals::modifiers::visuals::boxThickness, 1.0f, 3.0f);
									}
									ImGui::Unindent(14);
								}
							}
							ImGui::Unindent(10);
						}
					}
					ImGui::Unindent(5);
				}
				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}
	}
	ImGui::End();
}