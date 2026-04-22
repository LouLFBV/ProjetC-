#pragma once
#include <vector>
#include "Character.h"



class Player : public Character
{
private:
	static Player* m_instance;

    Player(int health, string name);
    Player(const Player&) = delete;

    string m_name;
	Weapon* m_currentWeapon;
    vector<Weapon*> m_inventory;
    static const size_t MAX_INVENTORY_SIZE = 5;

public:
	static Player* GetInstance(int health = 100, string name = "Hero");
    ~Player();

	string GetName() const override;
    void AddWeapon(Weapon* weapon);
	void DisplayInventory() const;
	vector<Weapon*> GetInventory() const;
    bool InventoryFull() const;
    Weapon* GetCurrentWeapon() const;
    void SetCurrentWeapon(Weapon* weapon);
	void UseWeapon(Weapon* weapon, IDamageable& target) override;
};