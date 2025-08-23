#pragma once

#include "core/config/config_object.h"
#include "core/config/fields/field.h"
#include "core/config/fields/hotkey_field.h"
#include "utils/singleton.h"

#define CONFIG_FIELD(TYPE, NAME, DEFAULT) \
    config::Field<TYPE> NAME { this->getPath(), #NAME, DEFAULT }

#define HOTKEY_FIELD(NAME, DEFAULT) \
    config::HotkeyField NAME { this->getPath(), #NAME, DEFAULT }

#define CONFIG_FIELD_VALIDATED(TYPE, name, defaultValue, validator)                \
    config::Field<TYPE> name{this->getPath(), #name, defaultValue};                \
    struct name##_init                                                             \
    {                                                                              \
        name##_init(Config::Field<TYPE>& field) { field.setValidator(validator); } \
    } name##_initializer { name }

namespace cheat
{
    enum class FeatureSection
    {
        Player,
        Combat,
        Game,
        Visual,
        Settings,
        Debug,
        Hooks,
        Count
    };

    template <typename Derived>
    class FeatureBase : public config::ConfigObject<Derived>
    {
    public:
        FeatureBase(const std::string& name, const std::string& description, FeatureSection section)
            : config::ConfigObject<Derived>(getSectionName(), name)
            , m_name(name)
            , m_description(description)
            , m_section(section)
            , m_allowDraw(section != FeatureSection::Hooks && section != FeatureSection::Count)
            , m_enabled(this->getPath(), "enabled", false)
        {
            m_enabledChangedConnection = m_enabled.onChanged(
                [this](bool oldE, bool newE)
                {
                    if (newE != oldE)
                    {
                        if (newE)
                            onEnable();
                        else
                            onDisable();
                    }
                });

            m_toggleKeyConnection = m_toggleKey.setHandler([this] { toggle(); });
        }

        ~FeatureBase() override = default;

        virtual void init() {}

        virtual void draw() {}
        virtual void update() {}

        virtual void onEnable() { LOG_INFO("{} enabled", getName().c_str()); }

        virtual void onDisable() { LOG_INFO("{} disabled", getName().c_str()); }

        const std::string& getName() const { return m_name; }
        const std::string& getDescription() const { return m_description; }
        FeatureSection getSection() const { return m_section; }
        bool isEnabled() const { return m_enabled.get(); }
        bool isAllowDraw() const { return m_allowDraw; }
        config::HotkeyField& getToggleKey() { return m_toggleKey; }

        void setEnabled(bool v) { m_enabled = v; }

        void toggle() { setEnabled(!isEnabled()); }

        void setupConfig()
        {
            this->load();
            if (m_enabled.get()) onEnable();
        }

        void reloadConfig() { this->load(); }

        void saveConfig() { this->save(); }

        void resetToDefault()
        {
            auto fields = config::FieldRegistry::getInstance().getFields(this->getPath());
            for (auto* field : fields)
            {
                field->resetToDefault();
            }
        }

        const char* getSectionName() const { return getSectionNameForSection(m_section); }

    protected:
        std::string m_name;
        std::string m_description;
        FeatureSection m_section;
        bool m_allowDraw;
        bool m_hasEnabledField;

        CONFIG_FIELD(bool, m_enabled_, false);
        HOTKEY_FIELD(m_toggleKey, 0);

    private:
        config::Field<bool>::Connection m_enabledChangedConnection;
        config::HotkeyField::Connection m_toggleKeyConnection;

        // Could use magic_enum but we'll see later
        static const char* getSectionNameForSection(const FeatureSection section)
        {
            switch (section)
            {
            case FeatureSection::Player:
                return "Player";
            case FeatureSection::Combat:
                return "Combat";
            case FeatureSection::Game:
                return "Game";
            case FeatureSection::Visual:
                return "Visual";
            case FeatureSection::Settings:
                return "Settings";
            case FeatureSection::Debug:
                return "Debug";
            case FeatureSection::Hooks:
                return "Hooks";
            case FeatureSection::Count:
            default:
                return "Unknown";
            }
        }
    };
} // namespace cheat
