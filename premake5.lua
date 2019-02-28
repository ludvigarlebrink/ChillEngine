function winSDKVersion()
    local reg_arch = iif( os.is64bit(), "\\Wow6432Node\\", "\\" )
    local sdk_version = os.getWindowsRegistry( "HKLM:SOFTWARE" .. reg_arch .."Microsoft\\Microsoft SDKs\\Windows\\v10.0\\ProductVersion" )
    if sdk_version ~= nil then return sdk_version end
end

function includeSDL()
    includedirs "ThirdParty/SDL/Include"
end

function linkSDL()
    libdirs "ThirdParty/SDL/Lib/Win64/"
    filter "kind:not StaticLib"
        links { "SDL2", "SDL2main" }
    filter {}
end

function includeFreeType()
    includedirs "ThirdParty/freetype/Include"
end

function linkFreeType()
    libdirs "ThirdParty/freetype/Lib/Win64/"
    filter "kind:not StaticLib"
        links "freetype"
    filter {}
end

function includeSTB()
    includedirs "ThirdParty/STB/Include"
end

function includeGTest()
    files {
        "ThirdParty/googletest-release-1.8.1/googletest/src/gtest-all.cc",
        "ThirdParty/googletest-release-1.8.1/googlemock/src/gmock_main.cc",
        "ThirdParty/googletest-release-1.8.1/googlemock/src/gmock-all.cc"
    }

    includedirs {
        "ThirdParty/googletest-release-1.8.1/googletest/include",
        "ThirdParty/googletest-release-1.8.1/googletest/src",
        "ThirdParty/googletest-release-1.8.1/googlemock/include",
        "ThirdParty/googletest-release-1.8.1/googletest/src"
    }
end

function useUtils()
    includedirs "Source/Runtime/Utils"
    filter { "kind:not StaticLib" }
        links { "Utils" }
    filter {}
end

function usePlatform()
    includedirs "Source/Runtime/Platform"
    filter { "kind:not StaticLib" }
        links { "Platform" }
    filter {}
    includeSDL()
    linkSDL()
    useUtils()
end

function useRenderCore()
    includedirs "Source/Runtime/RenderCore"
    filter { "kind:not StaticLib" }
        links { "RenderCore" }
    filter {}
    includeFreeType()
    linkFreeType()
    usePlatform()
    includeSTB()
end

function useECS()
    includedirs "Source/Runtime/ECS"
    filter { "kind:not StaticLib" }
        links { "ECS" }
    filter {}
    useECS()
end

workspace "ChillEngine"
    location "Solution"
    language "C++"
    cppdialect "C++17"
    architecture "x86_64"
    configurations { "Debug", "Release" }

    filter { "configurations:Debug", "system:windows", "action:vs*"}
        symbols "On"
        targetdir "Builds/Debug"
        systemversion(winSDKVersion() .. ".0")
        objdir "Builds/Debug/obj/%{prj.name}/%{cfg.longname}"

    filter { "configurations:Release", "system:windows", "action:vs*"}
        optimize "On"
        targetdir "Builds/Release"
        systemversion(winSDKVersion() .. ".0")
        objdir "builds/Debug/obj/%{prj.name}/%{cfg.longname}"
    filter {}

    -- Copy files.
    filter { "system:windows" }
        -- SDL
        os.copyfile("ThirdParty/SDL/Lib/Win64/SDL2.dll", "Builds/Debug/SDL2.dll")
        os.copyfile("ThirdParty/SDL/Lib/Win64/SDL2.dll", "Builds/Release/SDL2.dll")
        -- FreeType
        os.copyfile("ThirdParty/freetype/Lib/Win64/freetype.dll", "Builds/Debug/freetype.dll")
        os.copyfile("ThirdParty/freetype/Lib/Win64/freetype.dll", "Builds/Release/freetype.dll")
    filter {}

group "Runtime"
project "Utils"
    kind "SharedLib"
    location "Source/Runtime/Utils"
    files {
        "Source/Runtime/Utils/**.hpp",
        "Source/Runtime/Utils/**.cpp",
    }
    defines "UTILS_API_DLL_EXPORT"

group "Dev"
project "Utils_TEST"
    kind "ConsoleApp"
    location "Source/Dev/UnitTests/Utils_TEST"
    files {
        "Source/Dev/UnitTests/Utils_TEST/**.hpp",
        "Source/Dev/UnitTests/Utils_TEST/**.cpp",
    }
    includeGTest()
    useUtils()

group "Runtime"
project "Platform"
    kind "SharedLib"
    location "Source/Runtime/Platform"
    files {
        "Source/Runtime/Platform/**.hpp",
        "Source/Runtime/Platform/**.cpp",
    }
    defines "PLATFORM_API_DLL_EXPORT"
    includeSDL()
    linkSDL()
    useUtils()

group "Runtime"
project "RenderCore"
    kind "SharedLib"
    location "Source/Runtime/RenderCore"
    files {
        "Source/Runtime/RenderCore/**.hpp",
        "Source/Runtime/RenderCore/**.cpp",
        "Source/Runtime/RenderCore/glad/glad.h",
        "Source/Runtime/RenderCore/glad/khrplatform.h",
        "Source/Runtime/RenderCore/glad/glad.c"
    }
    defines "RENDER_CORE_API_DLL_EXPORT"
    includeFreeType()
    linkFreeType()
    includeSTB()
    usePlatform()

group "Runtime"
project "ECS"
    kind "SharedLib"
    location "Source/Runtime/ECS"
    files {
        "Source/Runtime/ECS/**.hpp",
        "Source/Runtime/ECS/**.cpp",
    }
    defines "ECS_API_DLL_EXPORT"
    useRenderCore()
    
group "Runtime"
project "Engine"
    kind "SharedLib"
    location "Source/Runtime/Engine"
    files {
        "Source/Runtime/Engine/**.hpp",
        "Source/Runtime/Engine/**.cpp",
    }
    defines "ENGINE_API_DLL_EXPORT"
    useECS()

group "Main"
project "Main"
    kind "ConsoleApp"
    location "Source/Main"
    files {
        "Source/Main/**.hpp",
        "Source/Main/**.cpp",
    }
    useRenderCore()

