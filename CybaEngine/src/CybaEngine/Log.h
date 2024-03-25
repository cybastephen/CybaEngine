#pragma once

#include <memory>

#include "Core.h"
#include <spdlog/spdlog.h>


namespace CybaEngine {
	class CYBA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macro
#define CY_CORE_TRACE(...)  ::CybaEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CY_CORE_INFO(...)   ::CybaEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CY_CORE_WARN(...)   ::CybaEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CY_CORE_ERROR(...)  ::CybaEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CY_CORE_FATAL(...)  ::CybaEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macro
#define CY_TRACE(...) ::CybaEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CY_INFO(...)  ::CybaEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CY_WARN(...)  ::CybaEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CY_ERROR(...) ::CybaEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CY_FATAL(...) ::CybaEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)