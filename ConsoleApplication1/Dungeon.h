#pragma once
#include <vector>
#include "Weapon.h"
#include "Enemy.h"
#include "Player.h"

using namespace std;

class Dungeon {
private:
    vector<Weapon*> m_weapons;
    vector<Enemy*> m_enemies;
    Player* m_player;

public:
    Dungeon();  
    ~Dungeon(); 

    void Init();
    void Run();
};