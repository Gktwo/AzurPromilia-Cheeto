#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <filesystem>
#include <unordered_set>

#include <UnityResolve.hpp>

#include <magic_enum.hpp>

#include <imgui.h>
#include <misc/cpp/imgui_stdlib.h>

#include <nlohmann/json.hpp>

// Project includes
#include "utils/dx_utils.h"
#include "utils/logger.h"
#include "memory/hook_manager.h"
#include "core/pipe/pipe_manager.h"
#include "core/events/event.h"
#include "ui/gui.h"
#include "appdata/helpers.h"
#include "appdata/types.h"
#include "utils/error.h"
