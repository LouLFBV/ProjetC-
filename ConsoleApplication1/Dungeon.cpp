#include "Dungeon.h"
#include "GameLogic.h"

#include "Player.h"

#include "Goblin.h"
#include "Mage.h"
#include "Orc.h"

#include "Wall.h"

#include "Sword.h"
#include "Knife.h"
#include "Slingshot.h"
#include "Bomb.h"
#include "MagicWand.h"
#include "Weapon.h"

#include <memory>
#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;



Dungeon::Dungeon(){}

Dungeon::~Dungeon()
{
    for (Enemy* enemy : m_enemies) {
        delete enemy;
    }

    m_enemies.clear();

    delete Player::GetInstance();

    for (Weapon* weapon :m_weapons) {
        delete weapon;
    }
    m_weapons.clear();
}

void Dungeon::Init()
{// --- INITIALISATION ---
    Sword* sword = new Sword(10);
    Knife* knife = new Knife(5);
    Slingshot* slingshot = new Slingshot(3);
    Bomb* bomb = new Bomb(20);
    MagicWand* magicWand = new MagicWand(15);

    // Liste des armes disponibles
    m_weapons = { sword, knife, slingshot, bomb, magicWand };

    // Player
    string playerName = "";
    cout << "Entrez le nom de votre personnage : ";
    cin >> playerName;
    cin.ignore();

    int initialHealth = 0;
    cout << "Entrez la sante initiale de votre personnage (ex: 100) : ";
    cin >> initialHealth;
    cin.ignore();

    m_player = Player::GetInstance(initialHealth, playerName);

    m_player->AddWeapon(sword);
    m_player->SetCurrentWeapon(sword);


    // Générateur aléatoire pour le nombre d'ennemis
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(3, 10);

    int enemyCount = dis(gen);

    // Générateur aléatoire pour la santé des ennemis
    random_device rdHealth;
    mt19937 genHealth(rdHealth());
    uniform_int_distribution<> disHealth(30, 100);

    // Générateur aléatoire pour choisir une arme
    random_device rdWeapon;
    mt19937 genWeapon(rdWeapon());
    uniform_int_distribution<> disWeapon(0, m_weapons.size() - 1);

    for (int i = 0; i < enemyCount; i++) {
        int health = disHealth(genHealth);
        Weapon* randomWeapon = m_weapons[disWeapon(genWeapon)];

        // On tire au sort le type d'ennemi (0: Orc, 1: Goblin, 2: Mage)
        uniform_int_distribution<> disType(0, 2);
        int type = disType(gen);

        Enemy* enemy = nullptr;

        if (type == 0) {
            enemy = new Orc(health, randomWeapon);
        }
        else if (type == 1) {
            enemy = new Goblin(health, randomWeapon);
        }
        else {
            enemy = new Mage(health, randomWeapon);
        }

        if (enemy) {
            m_enemies.push_back(enemy);
        }
    }

    cout << "Nombre d'ennemis crees : " << m_enemies.size() << endl << endl;
}

void Dungeon::Run()
{
    cout << "Bienvenue, " << m_player->GetName() << "! Vous allez entrer dans un donjon mysterieux, votre en mission ? Vaincre tous les ennemis pour en sortir. Bonne chance !" << endl;
    // BOUCLE DE JEU 
    while (m_player->IsAlive() && !m_enemies.empty()) {
        StartCombat(*m_enemies.back());

        if (!m_player->IsAlive()) {
            break;
        }
        else {
            m_enemies.pop_back();


            random_device rdWeapon;
            mt19937 genWeapon(rdWeapon());
            uniform_int_distribution<> disWeapon(0, m_weapons.size() - 1);

            random_device rdItem;
            mt19937 genItem(rdItem());
            uniform_int_distribution<> disItem(1, 3);

            random_device rdWall;
            mt19937 genWall(rdWall());
            uniform_int_distribution<> disWall(1, 2);

            Wall wall(disWall(genWall));


            cin.get();
            cout << m_player->GetName() << " vous faites face a un mur, detruisez le ! Quelque chose se cache peut-etre derriere !" << endl;
            cin.get();

            while (wall.GetDurability() > 0) {

                m_player->UseWeapon(m_player->GetCurrentWeapon(), wall);
                cin.get();
            }

            if (disItem(genItem) == 3) {
                Weapon* newWeapon = m_weapons[disWeapon(genWeapon)];
                cout << "Vous avez trouve une nouvelle arme derriere le mur : " << newWeapon->GetName() << "!" << endl;
                m_player->AddWeapon(newWeapon);
            }
            else
                cout << "Rien n'etait cache derriere le mur..." << endl;

            cin.get();
        }
    }

    if (m_player->IsAlive())
        cout << endl << endl << "Felicitations ! Vous avez vaincu tous les ennemis ! Vous avez reussi a sortir de ce donjon !" << endl;
    else
        cout << endl << endl << "Malheureusement ce donjon sera votre tombeau " << m_player->GetName() << endl << "Vous avez perdu." << endl;
}
