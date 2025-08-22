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
        void update() override;
        void drawESP();

    private:
        CONFIG_FIELD(float, m_range, 50.0f);
        CONFIG_FIELD(bool, m_showMonster, false);
        CONFIG_FIELD(bool, m_showPlayer, false);
        CONFIG_FIELD(bool, m_showNpc, false);
        CONFIG_FIELD(bool, m_drawLine, false);
        CONFIG_FIELD(bool, m_drawBox, false);
        CONFIG_FIELD(bool, m_drawName, true);
        CONFIG_FIELD(bool, m_drawDistance, true);
        CONFIG_FIELD(bool, m_showAll, true);



        float range ;
        bool draw_Line;
        bool draw_Box;
        bool draw_Name;
        bool draw_Distance;

        bool showAll;

        bool showMonster ;
        bool showPlayer;
        bool showNpc;

       
        ImColor red = ImColor(255, 0, 0); // 红色
        ImColor orange = ImColor(255, 165, 0); // 橙色
        ImColor yellow = ImColor(255, 255, 0); // 黄色
        ImColor green = ImColor(0, 255, 0); // 绿色
        ImColor blue = ImColor(0, 0, 255); // 蓝色
        ImColor qing = ImColor(0, 255, 255); // 青色
        ImColor purple = ImColor(148, 0, 211); // 紫色
        ImColor white = ImColor(255, 255, 255); // 白色
        ImColor deeppink = ImColor(255, 20, 147); // 深粉色
        ImColor pink = ImColor(255, 192, 203); // 粉色
        ImColor black = ImColor(0, 0, 0); // 黑色
        ImColor gray = ImColor(128, 128, 128); // 灰色
        
        
        ImColor getColorbyType(EEntityType_Enum entity_type);
        bool shouldshowbyType (EEntityType_Enum entity_type);
        std::string addtext(std::string text,std::string newtext);



    };
} // namespace cheat::features
