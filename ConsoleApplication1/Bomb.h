#pragma once

#include "Weapon.h"

#include <iostream>
using namespace std;

class Bomb : public Weapon
{
public:
	Bomb(int damage);
	void Attack(IDamageable& damageable, float multiplicateur) override;
};
