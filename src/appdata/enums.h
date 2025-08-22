#pragma once


enum class EEntityType_Enum : int32_t
{
    None = 0x00000000,           // 无类型/空类型
    Hero = 0x00000001,           // 英雄角色
    Soldier = 0x00000002,        // 士兵
    Boss = 0x00000003,           // BOSS怪物
    Formation = 0x00000004,      // 阵型/编队
    Throwable = 0x00000005,      // 可投掷物
    Item = 0x00000006,           // 物品
    Summon = 0x00000008,         // 召唤物
    AICommander = 0x00000009,    // AI指挥官
    Player = 0x0000000A,         // 玩家角色
    Pet = 0x0000000B,            // 宠物
    Mount = 0x0000000D,          // 坐骑
    Monster = 0x0000000E,        // 普通怪物
    GM = 0x0000000F,             // 游戏管理员(Game Master)
    BigWorldPet = 0x00000010,    // 大世界宠物
    Independent = 0x00000011,    // 独立实体
    BattleField = 0x00000013,    // 战场
    Bullet = 0x00000014,         // 子弹/投射物
    HomePet = 0x00000015,        // 家园宠物
    Playthrough = 0x00000016,    // 玩法相关实体
    RandomEvtObj = 0x00000017,   // 随机事件对象
    KiBo = 0x00000018,           // 某种特殊实体（可能是特定玩法实体）
    KiBoPVEField = 0x00000019,   // KiBo PVE场景实体
    DefenseTower = 0x0000001A,   // 防御塔
    BaseTower = 0x0000001B,      // 基地塔
    PhotoEntity = 0x0000001C,    // 拍照相关实体
    ControllableEntity = 0x0000001D, // 可控制实体
    KiBoNpcEntity = 0x0000001E,  // KiBo NPC实体
    NPC = 0x0000001F,            // 非玩家角色
    WorldItem = 0x00000020,      // 世界物品
    BreakableItem = 0x00000021,  // 可破坏物品
    PuzzleItem = 0x00000022,     // 解谜物品

    // 家园系统相关实体（从0x0000012C开始）
    HomeObject = 0x0000012C,     // 家园物件
    HomeDrop = 0x0000012D,       // 家园掉落物
    DynaTerrain = 0x0000012E,    // 动态地形
};

