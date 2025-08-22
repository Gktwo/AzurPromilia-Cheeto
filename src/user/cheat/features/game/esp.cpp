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
            SAFE_EXECUTE({
                drawESP();
                //try show a entity info
            })
            
        }
    }
    void ESP::update(){
        // if (!s_instance->isEnabled()) return;
        // SAFE_EXECUTE({
        //         drawESP();
        //         //try show a entity info
        // })
    }
    void ESP::drawESP()
    {
       // if (!s_instance->isEnabled()) return;
        
        auto*  entities = UNITY_CALL(EntityManager::GetAllEntities);

        //}
        
        //LOG_DEBUG("ESP: Processing %d entities", entities->size);
        
        if (!entities || entities->size == 0) 
            printf("ESP: not found entity\n");
            return;
        printf("ESP: found %d entities\n",entities->size);
        LOG_DEBUG("ESP: Processing {} entities", entities->size);
        for (int i = 0; i < entities->size; i++)
        {


                Entity* entity = &(*entities)[i];
                if (!entity) continue;
                std::string showtext = "";
                //UTYPE::String* name = UNITY_CALL(entity->get_className, entity);
                //printf("%s\n", name->ToString().c_str());

                //basedata is real?
                const char*  name =entity->basedata()->getClassName();            
                LOG_DEBUG("entity[ {} ]data class name : {}",i, name);

                int id = entity->basedata()->entityId();
                LOG_DEBUG("entity[ {} ]data id : {}",i, id);

                //EEntityType_Enum entity_type = entity->basedata()->entityType();
                //if (!shouldshowbyType(entity_type)) continue;

                // get entity name
               // name = entity->basedata()->configName();
                //addtext(showtext,name->ToString());




                //UTYPE::Vector3* entity_pos = entity->basedata()->GetPosition();
                //LOG_DEBUG("entity pos: {},{},{},",entity_pos.X,entity_pos.Y,entity_pos.Z);
                //UTYPE::Vector3* rect = UNITY_CALL(Camera::WorldToScreenPoint(UNITY_CALL(Camera::Camera_get_main()), entity_pos));
                
               // if (rect.Z < 0.1f) continue;
                //int screenWidth = UNITY_CALL(Screen::get_width);
                //int screenHeight = UNITY_CALL(Screen::get_height);

                //ImVec2 imguiPos(rect.X, screenHeight - rect.Y);

                
                //ImColor drawcolor = getColorbyType(entity_type);


                // ImGui::GetForegroundDrawList()->AddLine(ImVec2(screenWidth / 2, 0), imguiPos, drawcolor, 1.0f);
                // ImGui::GetForegroundDrawList()->AddText(nullptr, 18.0f, imguiPos, drawcolor, showtext.c_str());


        }
    }
    ImColor ESP::getColorbyType(EEntityType_Enum entity_type){
        switch (entity_type)
        {
        case EEntityType_Enum::Hero:
        case EEntityType_Enum::Player:
        case EEntityType_Enum::Pet:
            return green;
            break;
        // case EEntityType_Enum::Soldier:
        //     return orange;
        case EEntityType_Enum::Boss:
        case EEntityType_Enum::Monster:
            return red;
            break;
        default:
            return white;
            break;
        }
    }
    bool ESP::shouldshowbyType (EEntityType_Enum entity_type){ 
        switch (entity_type)
        {
        case EEntityType_Enum::Hero:
        case EEntityType_Enum::Player:
            return showPlayer;          
            break;

        case EEntityType_Enum::Boss:
        case EEntityType_Enum::Monster:
            return showMonster;
            break;
        default:
            return showAll;
            break;
        }
    }
    std::string ESP::addtext(std::string text,std::string newtext){
        if (text.empty()) text += " | ";
        text+=newtext;
        return text;
    }

}