#include "pch.h"
#include "cheat.h"

#include "feature_manager.h"
#include "features/game/esp.h"



void cheat::init()
{
    ConfigManager::getInstance().load();

    auto& manager = FeatureManager::getInstance();

    manager.registerFeatures<
        // features::Debug,

        // Cheat features
        features::ESP
    >();

    const auto fullVersion = Application::get_version()()->ToString();
    const size_t dotPos = fullVersion.rfind('.');
    const auto version = fullVersion.substr(dotPos + 1);
    LOG_INFO("AzurPromilia version: {}", version.c_str());

    manager.init();
}

void cheat::shutdown()
{
    auto& hookManager = HookManager::getInstance();
    hookManager.shutdown();
    LOG_INFO("Hooks shutdown successfully");
}
