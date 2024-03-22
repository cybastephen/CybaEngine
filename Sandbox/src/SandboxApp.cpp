#include <CybaEngine.h>

class Sandbox : public CybaEngine::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

CybaEngine::Application* CybaEngine::CreateApplication()
{
	return new Sandbox();
}