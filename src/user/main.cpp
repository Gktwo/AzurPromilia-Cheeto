#include "pch.h"
#include "main.h"

#include "core/rendering/renderer.h"
#include "cheat/cheat.h"

void Main::run()
{
    LOG_INFO("Starting initialization...");
    Sleep(1000);
    MessageBoxA(NULL, "start search unity", "info", MB_OK | MB_ICONINFORMATION);
    if (!initializeUnity())
        LOG_ERROR("Unable to initialize Unity! Maybe assemblies are not found?");

    if (!PipeManager::isUsingPipes())
    {
        LOG_INFO("{}", Renderer::getInstance().initialize()
                 ? "Renderer initialized!"
                 : "Failed to initialize renderer!");
    }

    cheat::init();
}

void Main::shutdown()
{
    LOG_INFO("Shutting down...");

    Renderer::getInstance().shutdown();
    cheat::shutdown();
    Sleep(100);
    Logger::close();
}


Main::UnityModuleBackendInfo Main::getUnityBackend()
{
    LOG_INFO("Finding Unity backend...");

    UnityModuleBackendInfo info;
    info.module = nullptr;
    info.mode = UnityResolve::Mode::Mono;

    // Check if Unity is loaded
    if (const auto unityModule = GetModuleHandleA("UnityPlayer.dll"); unityModule == nullptr)
    {
        LOG_ERROR("UnityPlayer.dll not found! Is this a Unity game?");
        return info;
    }

    auto assembly = GetModuleHandleA("GameAssembly.dll");
    if (assembly)
    {
        info.module = assembly;
        info.mode = UnityResolve::Mode::Il2Cpp;
        LOG_INFO("Found Il2Cpp backend!");
        return info;
    }
    LOG_WARN("GameAssembly.dll not found, trying fallback to Mono...");

    std::vector<std::string> monoModules = {
        "mono-2.0-bdwgc.dll",
        "mono.dll"
    };

    for (const auto& monoModule : monoModules)
    {
        if (const auto monoHandle = GetModuleHandleA(monoModule.c_str()); monoHandle)
        {
            info.module = monoHandle;
            info.mode = UnityResolve::Mode::Mono;
            LOG_INFO("Found Mono backend: %s", monoModule.c_str());
            return info;
        }
    }

    LOG_ERROR("Unable to find Unity backend! Neither GameAssembly.dll nor mono.dll found.");
    return info;
}

bool Main::initializeUnity()
{
    auto [module, mode] = getUnityBackend();
    if (module == nullptr)
    {
        LOG_ERROR("Unity backend not found!");
        return false;
    }

    UnityResolve::Init(module, mode);

    return true;
}
