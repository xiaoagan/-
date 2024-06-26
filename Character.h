#pragma once 
#include <iostream>

class Monster;

class Character {
public:
    int hp;         //生命值
    int attack;     //攻击力

    //构造函数，初始化生命值和攻击力
    Character(int hp, int attack) : hp(hp), attack(attack) {}
    virtual ~Character() {}
    virtual bool isAlive() const { return hp > 0; }
    virtual void receiveDamage(int damage) { hp -= damage; }

};


//派生类  Hero
class Hero : public Character {
public:
    int mp;                 //魔法点
    int mpRecovery;         //魔法回复量
    int skillCooldown[4];   //技能冷却时间
    int currentCooldown[4];   //技能冷却时间数组，假设有4个技能
    int damage[4];          //技能伤害值
    int manaCost[4];         //技能消耗的魔法值
    int healAmount;         //治疗技能的治疗量
    //构造函数
    Hero(int hp, int mp, int attack, int mpRecovery);

    void recoverMana();
    void useSkill(int skillIndex);
    void useSkill(int skillIndex, Monster& monster);
    void decreaseCooldowns();
};

// 派生类 Monster，继承自Character,代表怪物
class Monster : public Character {
public:
    Monster(int hp, int attack) : Character(hp, attack) {}
};