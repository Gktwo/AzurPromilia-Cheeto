﻿#pragma once
#include "user/cheat/feature_base.h"

namespace cheat::features
{
    class DumbEnemies : public FeatureBase<DumbEnemies>
    {
        DECL_SINGLETON(DumbEnemies)

    public:
        DumbEnemies();

        void draw() override;

    private:
        bool m_dumbPlayer = false; // For testing

        static bool hBattleEntity_get_HasMainTarget(BattleEntity* _this);
        // static bool hBattleEntity_CanBeTargeted(BattleEntity* _this, BattleEntity* attacker, SkillSlot_Enum skillSlot);
    };
}
