#include "Character.h"
using namespace std;

//Hero 构造函数
Hero::Hero(int hp, int mp, int attack, int mpRecovery) 
    : Character(hp, attack), mp(mp), mpRecovery(mpRecovery) {
    
    //初始化相关技能的数据，设定每个技能的冷却时间、伤害值、魔法消耗和治疗量
    skillCooldown[0] = 3;
    skillCooldown[1] = 2;
    skillCooldown[2] = 4;
    skillCooldown[3] = 1;
    damage[0] = 30; 
    damage[1] = 50; 
    damage[2] = 25; 
    damage[3] = 0;
    manaCost[0] = 10; 
    manaCost[1] = 20; 
    manaCost[2] = 15; 
    manaCost[3] = 5;
    healAmount = 20;

    // 初始化当前冷却时间数组为0
    for (int i = 0; i < 4; i++) {
        currentCooldown[i] = 0;
    }
    
}

//英雄使用技能的方法
void Hero::useSkill(int skillIndex, Monster& monster) {
    if (currentCooldown[skillIndex] == 0 && mp >= manaCost[skillIndex]) {
        mp -= manaCost[skillIndex];
        if (damage[skillIndex] > 0) {
            monster.receiveDamage(damage[skillIndex]);
            cout << "Hero uses skill" << skillIndex + 1 << ", dealing " << damage[skillIndex] << " damage to the monster." << endl;  
        } else {
            hp += healAmount;            //用治疗技能加血
            cout << "Hero heals self for " <<healAmount << " health." << endl;
        }
        currentCooldown[skillIndex] = skillCooldown[skillIndex];
    } else {
        if (currentCooldown[skillIndex] > 0) {
            cout << "skill " << skillIndex + 1 << " is on cooldown, " << currentCooldown[skillIndex] << " turns remaining." << endl;
        } else {
            cout << "Not enough MP to use skill " << skillIndex + 1 << "." << endl;
        }
    }
}


//减少技能的冷却时间
void Hero::decreaseCooldowns() {
    for (int i = 0; i < 4; i++) {
        if (currentCooldown[i] > 0) {
            currentCooldown[i]--;
        }
    }
}

//恢复魔法值
void Hero::recoverMana() {
    mp += mpRecovery;
}