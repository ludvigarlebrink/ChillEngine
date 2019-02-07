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
     
    filter { "kind:not StaticLib", "system:windows" }
        links { "Utils" }
    
    filter { "kind:not StaticLib", "system:not windows" }
        links { "Utils" }

    filter {}
end

workspace "ChillEngine"
    location "Solution"
    language "C++"
    cppdialect "C++17"

    architecture "x86_64"
    configurations { "Debug", "Release" }

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
    targetdir ("Builds/UnitTests/Utils_TEST")
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
