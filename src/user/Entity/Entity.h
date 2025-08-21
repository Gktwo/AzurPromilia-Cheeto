#pragma once

#include "user/cheat/feature_base.h"
#include <cmath>

class EntityWrapper
{
private:
    Entity* m_entity;
    BaseData* m_baseData;

public:
    EntityWrapper(Entity* entity);
    ~EntityWrapper();

    // 基本信息获取
    int GetEntityId() const;
    int GetConfigId() const;
    EEntityType_Enum GetEntityType() const;
    UTYPE::String* GetConfigName() const;
    //UTYPE::String* GetClass_Name() const;

    // 位置相关
    UTYPE::Vector3* GetPosition() const;
    void SetPosition(UTYPE::Vector3* position);
    void SetPosition(float x, float y, float z);

    // 时间缩放
    void SetTimeScale(float timeScale);

    // 距离计算
    float CalculateDistance(EntityWrapper* other) const;
    float CalculateDistance(UTYPE::Vector3* targetPos) const;

    // 实用方法
    bool IsValid() const;
    Entity* GetUnityEntity() const { return m_entity; }
    BaseData* GetBaseData() const { return m_baseData; }
};