#include <iostream>
#include "Character.h"

using namespace std;

int main() {
    //初始化英雄和怪物
    int heroHp, heroMp, heroAttack, heroMpRecovery;
    int monsterHp, monsterAttack;

    //设定英雄和怪物的基本属性
    cout << "Initialize hero (hp, mp, attack, mp recovery): ";
    cin >> heroHp >> heroMp >> heroAttack >> heroMpRecovery;
    
    cout << "Initialize monster (hp, attack): ";
    cin >> monsterHp >> monsterAttack;

    //创建英雄和怪物对象
    Hero hero (heroHp, heroMp, heroAttack, heroMpRecovery);
    Monster monster(monsterHp, monsterAttack);

    int choice;
    //游戏主循环
    while (hero.isAlive() && monster.isAlive()) {
        cout << "choose action (1-4 for skills, 5 for normal attack, q to quit): ";
        cin >> choice;
        if (choice == 'q') break;
        //根据输入的技能，执行相应的操作
        if (choice >= 1 && choice <= 4) {
            hero.useSkill(choice - 1 , monster);
        } else if (choice == 5) {
            monster.receiveDamage(hero.attack);
            cout << "Hero attacks dealing" << hero.attack << " damage." << endl;
        }

        //减少你能冷却时间，恢复魔法值
        hero.decreaseCooldowns();
        hero.recoverMana();

        //如果怪物存活，则反击
        if (monster.isAlive()) {
            hero.receiveDamage(monster.attack);
            cout << "Monster attacks dealing " << monster.attack << " damage." << endl;
        }

        cout << "Hero HP/MP: " << hero.hp << "/" << hero.mp << endl;
        cout << "Monster HP: " << monster.hp << endl;
        
        //输出游戏结果
        if (!hero.isAlive()) {
            cout << "Monster wins!" << endl;
            break;
        } else if (!monster.isAlive()) {
            cout << "Hero wins!" << endl;
            break;
        }
    }
    return 0;

}