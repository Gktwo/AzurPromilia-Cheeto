#include "pch.h"
#include "event_manager.h"


inline Event<> EventManager::onReloadConfig;
inline Event<int, bool&> EventManager::onKeyDown;
inline FastEvent<> EventManager::onUpdate;

EventManager::EventManager() = default;

EventManager::~EventManager() { shutdown(); }

EventManager& EventManager::getInstance()
{
    static EventManager instance;
    return instance;
}

void EventManager::shutdown()
{
    onReloadConfig.clear();
    onKeyDown.clear();
    onUpdate.clear();
}
