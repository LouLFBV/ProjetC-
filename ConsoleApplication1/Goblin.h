#pragma once

#include "Enemy.h"

class Goblin : public Enemy
{
public:
	Goblin(int health, Weapon* weapon);
	~Goblin();
	string GetName() const override;
	void Die() const override;
	void UseWeapon(Weapon* weapon, IDamageable& target) override;
	void Grunting() const override;
};