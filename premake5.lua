workspace "CybaEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CybaEngine"
	location "CybaEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CY_PLATFORM_WINDOWS",
			"CY_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../Sandbox")
		}

	filter "configurations:Debug"
		defines "CY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CY_DIST"
		optimize "On"


project "Sandbox"
location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"CybaEngine/vendor/spdlog/include",
		"CybaEngine/src"
	}

	links
	{
		"CybaEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CY_DIST"
		optimize "On"