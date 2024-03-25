#pragma once

#ifdef CY_PLATFORM_WINDOWS

extern CybaEngine::Application* CybaEngine::CreateApplication();

int main(int argc, char** argv)
{
	CybaEngine::Log::Init();
	CY_CORE_WARN("Initialized Log!");
	int a = 5;
	CY_INFO("Hello! Var={0}", a);
	auto app = CybaEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif