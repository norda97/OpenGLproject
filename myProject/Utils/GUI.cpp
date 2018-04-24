#include "GUI.h"
#include "imgui\imgui_impl_glfw_gl3.h"
#include "..\Core\Display.h"
#include "..\Core\Entity\EntityManager.h"
#include <string>

GUI::GUI(Display * display, EntityManager * entities)
{
	this->mEntities = entities;

	this->clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	this->show_demo_window = true;
	this->show_another_window = false;

	//############## IMGUI setup ###################
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;   // Enable Gamepad Controls
	ImGui_ImplGlfwGL3_Init(display->getWindow(), true);
	ImGui::StyleColorsDark();
	//###############################################
}

GUI::~GUI()
{
	// IMGUI cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
}

void GUI::render()
{
	// IMGUI new frame
	ImGui_ImplGlfwGL3_NewFrame();

	// ############# Test Window #################
	static float f = 0.0f;
	static int counter = 0;

	ImGui::Text("Console:");
	ImGui::Text("FPS: %.1f application average %.3f", ImGui::GetIO().Framerate);
	ImGui::Text("App average %.3f ms/frame", 1000.0f / ImGui::GetIO().Framerate);

	if (ImGui::CollapsingHeader("Entities"))
	{
		std::vector<std::string> entityNames = this->mEntities->getAllEntityNames();

		if (ImGui::TreeNode("Selection State: Single Selection"))
		{
			static int selected = -1;
			for (int n = 0; n < entityNames.size(); n++)
			{
				char buf[32];
				sprintf(buf, "%03d: %s", n, entityNames[n].c_str());
				if (ImGui::Selectable(buf, selected == n))
				{
					selected = n;
					ImGui::PushID("foo");
					this->ShowEntityMenuFile();
					ImGui::PopID();
				}
			}
			ImGui::TreePop();
		}
	
		/*for (int i = 0; i < entityNames.size(); i++)
		{
			ImGui::Text("%03d: %s", i, entityNames[i].c_str());
			ImGui::InputFloat3(entityNames[i].c_str(), &this->mEntities->getEntity(entityNames[i])->getPosition()[0], 1);
		}*/
		
		// ##########################################
		
	}

	ImGui::ShowDemoWindow();


	// IMGUI render
	ImGui::Render();
	ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
}


void GUI::ShowEntityMenuFile()
{
	ImGui::MenuItem("(dummy menu)", NULL, true, false);
	if (ImGui::MenuItem("New")) {}
	ImGui::Separator();
	if (ImGui::BeginMenu("Options"))
	{
		static bool enabled = true;
		ImGui::MenuItem("Enabled", "", &enabled);
		ImGui::BeginChild("child", ImVec2(0, 60), true);
		for (int i = 0; i < 10; i++)
			ImGui::Text("Scrolling Text %d", i);
		ImGui::EndChild();
		static float f = 0.5f;
		static int n = 0;
		static bool b = true;
		ImGui::SliderFloat("Value", &f, 0.0f, 1.0f);
		ImGui::InputFloat("Input", &f, 0.1f);
		ImGui::Combo("Combo", &n, "Yes\0No\0Maybe\0\0");
		ImGui::Checkbox("Check", &b);
		ImGui::EndMenu();
	}
	if (ImGui::BeginMenu("Colors"))
	{
		float sz = ImGui::GetTextLineHeight();
		for (int i = 0; i < ImGuiCol_COUNT; i++)
		{
			const char* name = ImGui::GetStyleColorName((ImGuiCol)i);
			ImVec2 p = ImGui::GetCursorScreenPos();
			ImGui::GetWindowDrawList()->AddRectFilled(p, ImVec2(p.x + sz, p.y + sz), ImGui::GetColorU32((ImGuiCol)i));
			ImGui::Dummy(ImVec2(sz, sz));
			ImGui::SameLine();
			ImGui::MenuItem(name);
		}
		ImGui::EndMenu();
	}
	if (ImGui::BeginMenu("Disabled", false)) // Disabled
	{
		IM_ASSERT(0);
	}
	if (ImGui::MenuItem("Checked", NULL, true)) {}
	if (ImGui::MenuItem("Quit", "Alt+F4")) {}
}