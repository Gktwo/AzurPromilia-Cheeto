﻿#pragma once
#include "user/cheat/feature_base.h"

namespace cheat::features
{
    class Debug : public FeatureBase<Debug>
    {
        DECL_SINGLETON(Debug)

    public:
        Debug();

        void draw() override;

    private:
        bool m_test0;

        static void hBattleEntity_ApplyStat(BattleEntity* _this, StatType_Enum statType);
        static void hBattleEntityStatProcessor_Apply(BattleEntityStatProcessor* _this, StatType_Enum statType);
        static void* hCharacter_ApplyDamage(Character* _this, BattleEntity* attacker, DamageResult damageResult);
    };
}
