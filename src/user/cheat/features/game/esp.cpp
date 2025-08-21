#include "pch.h"
#include "esp.h"



namespace cheat::features
{
    ESP::ESP()
        : FeatureBase("ESP", "OPEN ESP", FeatureSection::Game)
        , range(m_range.get())
        , showMonster(m_showMonster.get())
        , showPlayer(m_showPlayer.get())
        , showNpc(m_showNpc.get())
        , draw_Line(m_drawLine.get())
        , draw_Box(m_drawBox.get())
        , draw_Name(m_drawName.get())
        , draw_Distance(m_drawDistance.get())
        , showAll(m_showAll.get())
    {
    }

    void ESP::draw()
    {
        if (!s_instance->isEnabled()) return;

        ImGui::InputFloat("范围", &range, 1.0f, 5.0f, "%.1f");
        ImGui::Checkbox("显示NPC", &showNpc);
        ImGui::Checkbox("显示线", &draw_Line);
        ImGui::Checkbox("显示框", &draw_Box);
        ImGui::Checkbox("显示名称", &draw_Name);
        ImGui::Checkbox("显示距离", &draw_Distance);
        ImGui::SeparatorText("Type");
        ImGui::Checkbox("显示怪物", &showMonster);
        ImGui::Checkbox("显示玩家", &showPlayer);

        ImGui::Checkbox("显示所有", &showAll);
        if(ImGui::Button("get entities")){
            
            drawESP();
            
        }
    }

    void ESP::drawESP() {
       // if (!s_instance->isEnabled()) return;
        
        auto*  entities = UNITY_CALL(EntityManager::GetAllEntities);

        //}
        
        //LOG_DEBUG("ESP: Processing %d entities", entities->size);
        printf("ESP: Processing %d entities\n", entities ? entities->size : 0);
        if (!entities || entities->size == 0) 
            return;
        for (int i = 0; i < entities->size; i++)
        {
            try {
            
                Entity* entity = &(*entities)[i];
                if (!entity) continue;
                //UTYPE::String* name = UNITY_CALL(entity->get_className, entity);
                //printf("%s\n", name->ToString().c_str());
                UTYPE::String* name = entity->basedata()->configName();
                 printf("%s\n", name->ToString().c_str());
                
            } catch (const std::exception& e) {

                continue;
            } 
        }
    }

} // namespace cheat::features
