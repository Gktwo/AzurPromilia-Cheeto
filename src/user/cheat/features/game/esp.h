#pragma once
#include "user/cheat/feature_base.h"

namespace cheat::features
{
    class ESP : public FeatureBase<ESP>
    {
        DECL_SINGLETON(ESP)

    public:
        ESP();
        void draw() override;

    private:
        CONFIG_FIELD(float, m_range, 1.0f);
        CONFIG_FIELD(bool, m_showMonster, true);
        float range ;
        bool showMonster ;
       
        
        
    };
} // namespace cheat::features
