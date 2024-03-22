#pragma once 

#include "Core.h"

namespace  CybaEngine {

	class CYBA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}