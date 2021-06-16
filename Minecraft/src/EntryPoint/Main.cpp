#include <MC.h>

#include "Application/Application.h"
#include "Application/GameLayer.h"

int main() {

	using namespace Minecraft;

	Application::CreateApplication()->Init("Minecraft");

	Application::GetApplication()->PushLayer(new GameLayer());
	Application::GetApplication()->Run();

	Application::GetApplication()->Shutdown();

	return 0;
}