#include "pch.h"
#include "Entity.h"

EntityWrapper::EntityWrapper(Entity* entity)
    : m_entity(entity), m_baseData(nullptr)
{
    if (m_entity && m_entity->basedata())
    {
        m_baseData = m_entity->basedata();
    }
}

EntityWrapper::~EntityWrapper()
{
    
}

int EntityWrapper::GetEntityId() const
{
    if (!IsValid()) return -1;
    return m_baseData->entityId();
}

int EntityWrapper::GetConfigId() const
{
    if (!IsValid()) return -1;
    return m_baseData->configId();
}

EEntityType_Enum EntityWrapper::GetEntityType() const
{
    if (!IsValid()) return static_cast<EEntityType_Enum>(0);
    return m_baseData->entityType();
}

UTYPE::String* EntityWrapper::GetConfigName() const
{
    if (!IsValid()) return nullptr;
    return m_baseData->configName();
}

//UTYPE::String* EntityWrapper::GetClass_Name() const
//{
//    if (!IsValid()) return nullptr;
//    return m_baseData->className();
//}

UTYPE::Vector3* EntityWrapper::GetPosition() const
{
    
    if (!IsValid()) return nullptr;
    return UNITY_CALL(m_baseData->GetPosition, m_baseData);         
}

void EntityWrapper::SetPosition(UTYPE::Vector3* position)
{
    if (!IsValid() || !position) return;
    UNITY_CALL(m_baseData->SetPosition, m_baseData, position);
}

void EntityWrapper::SetPosition(float x, float y, float z)
{
    if (!IsValid()) return;
    
    // 创建临时Vector3对象
    UTYPE::Vector3 newPos;
    newPos.x = x;
    newPos.y = y;
    newPos.z = z;
    
    UNITY_CALL(m_baseData->SetPosition, m_baseData, &newPos);
}

void EntityWrapper::SetTimeScale(float timeScale)
{
    if (!IsValid()) return;
    UNITY_CALL(m_baseData->SetSelfTimeScale, m_baseData, timeScale);
}

float EntityWrapper::CalculateDistance(EntityWrapper* other) const
{
    if (!other || !IsValid() || !other->IsValid()) return -1.0f;
    
    UTYPE::Vector3* pos1 = GetPosition();
    UTYPE::Vector3* pos2 = other->GetPosition();
    
    if (!pos1 || !pos2) return -1.0f;
    
    float dx = pos1->x - pos2->x;
    float dy = pos1->y - pos2->y;
    float dz = pos1->z - pos2->z;
    
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

float EntityWrapper::CalculateDistance(UTYPE::Vector3* targetPos) const
{
    if (!IsValid() || !targetPos) return -1.0f;
    
    UTYPE::Vector3* pos = GetPosition();
    if (!pos) return -1.0f;
    
    float dx = pos->x - targetPos->x;
    float dy = pos->y - targetPos->y;
    float dz = pos->z - targetPos->z;
    
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

bool EntityWrapper::IsValid() const
{
    return m_entity != nullptr && m_baseData != nullptr;
}