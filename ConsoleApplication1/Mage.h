#pragma once

#include "Enemy.h"

#include <iostream>
using namespace std;

class Mage : public Enemy
{
public:
	Mage(int health, Weapon* weapon);
	~Mage();
	string GetName() const override;
	void Die() const override;
	void UseWeapon(Weapon* weapon, IDamageable& target) override;
	void Grunting() const override;
};