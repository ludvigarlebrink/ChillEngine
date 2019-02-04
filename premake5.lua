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

workspace "ChillEngine"
    location "Solution"
    language "C++"
    cppdialect "C++17"

    architecture "x86_64"
    configurations { "Debug", "Release", "Debug_Editor", "Release_Editor" }

project "Utils"
    kind "SharedLib"
    location "Source/Runtime/Utils"
    files {
        "Source/Runtime/Utils/**.hpp",
        "Source/Runtime/Utils/**.hpp",
    }
    defines "UTILS_API_DLL_EXPORT"

project "Platform"
    kind "SharedLib"
    location "Source/Runtime/Platform"
    files {
        "Source/Runtime/Platform/**.hpp",
        "Source/Runtime/Platform/**.hpp",
    }
    defines "PLATFORM_API_DLL_EXPORT"
    includeSDL()
    linkSDL()
