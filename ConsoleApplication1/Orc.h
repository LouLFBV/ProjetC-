#pragma once

#include "Enemy.h"

#include <iostream>
using namespace std;

class Orc : public Enemy
{
public:
	Orc(int health, Weapon* weapon);
	~Orc();
	string GetName() const override;
	void Die() const override;
	void UseWeapon(Weapon* weapon, IDamageable& target) override;
	void Grunting() const override;
};