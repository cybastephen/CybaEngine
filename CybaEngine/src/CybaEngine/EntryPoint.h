#pragma once

#ifdef CY_PLATFORM_WINDOWS

extern CybaEngine::Application* CybaEngine::CreateApplication();
int main(int argc, char** argv)
{
	printf("CybaEngine");
	auto app = CybaEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif