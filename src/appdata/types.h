#pragma once

#include "enums.h"
#include "cs-types.h"
#include "types-helper.h"

using UTYPE = UnityResolve::UnityType;

///////////////////////////////
/// All Forward Declarations
///////////////////////////////
class Application;
class AzurPlay;
class BaseData;
class Entity;
class EntityManager;
class Camera;
class Screen;
class RenderSettings;

///////////////////////////////
/// Class Definitions
///////////////////////////////

class Application
{
    UNITY_CLASS_DECL("UnityEngine.CoreModule.dll", "Application")

    UNITY_METHOD(UTYPE::String*, get_version,)
};

class AzurPlay
{
    UNITY_CLASS_DECL("Assembly-CSharp.dll", "AzurPlay")
    UNITY_METHOD(void, WorldUpdate, AzurPlay*,float)

};
class BaseData
{
    UNITY_CLASS_DECL("Assembly-CSharp.dll", "BaseData")

    

    UNITY_FIELD(int, battleId, 0x110)
    UNITY_FIELD(int, entityId, 0x118)
    UNITY_FIELD(EEntityType_Enum, entityType, 0x124)
    UNITY_FIELD(int, configId, 0x12C)
    UNITY_FIELD(UTYPE::String*, configName, 0x130)


    UNITY_METHOD(UTYPE::Vector3*, GetPosition, BaseData*)
    UNITY_METHOD(void, SetPosition, BaseData*, UTYPE::Vector3*)
    UNITY_METHOD(void, SetSelfTimeScale, BaseData*,float)
  


};
class Entity
{
    UNITY_CLASS_DECL("Assembly-CSharp.dll", "Entity")
    UNITY_FIELD(BaseData*, basedata, 0x10)
    UNITY_METHOD(UTYPE::String*, get_className, Entity*)


    //UNITY_METHOD(UTYPE::String*, className)
};

class EntityManager
{
    UNITY_CLASS_DECL("Assembly-CSharp.dll", "EntityManager")

    UNITY_METHOD(UTYPE::List<Entity>*, GetAllEntities)
    
};

class Camera
{
    UNITY_CLASS_DECL("UnityEngine.CoreModule.dll", "Camera")
    UNITY_METHOD(UTYPE::Vector3*, WorldToScreenPoint, Camera*, UTYPE::Vector3*)
    UNITY_METHOD(UTYPE::Vector3*, ScreenToWorldPoint, Camera*, UTYPE::Vector3*)
    UNITY_METHOD(UTYPE::Vector3*, WorldToViewportPoint, Camera*, UTYPE::Vector3*)
    UNITY_METHOD(UTYPE::Vector3*, ViewportToWorldPoint, Camera*, UTYPE::Vector3*)
    UNITY_METHOD(void, CopyFrom, Camera*, Camera*)
    UNITY_METHOD(Camera*, get_main,)
    UNITY_METHOD(Camera*, get_current,)
};

class Screen
{
    UNITY_CLASS_DECL("UnityEngine.CoreModule.dll", "Screen")
    UNITY_METHOD(int, get_width)
    UNITY_METHOD(int, get_height)
    UNITY_METHOD(void, set_width)
    UNITY_METHOD(void, set_height)
    UNITY_METHOD(void, SetResolution, int, int, bool)
};

class RenderSettings
{
    UNITY_CLASS_DECL("UnityEngine.CoreModule.dll", "RenderSettings")
    UNITY_METHOD(bool, get_fog)
    UNITY_METHOD(void, set_fog,bool)

};

