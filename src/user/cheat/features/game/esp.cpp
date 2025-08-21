#include "pch.h"
#include "esp.h"


namespace cheat::features
{
    ESP::ESP()
        : FeatureBase("ESP", "OPEN ESP", FeatureSection::Game), range(m_range.get()), showMonster(m_showMonster.get())
    {
       
    }

    void ESP::draw() {
        if (s_instance->isEnabled())
        {
            ImGui::InputFloat("范围", &range, 1.0f, 5.0f, "%.1f");
            ImGui::Checkbox("显示怪物", &showMonster);
        }

    
    
    }


} // namespace cheat::features
