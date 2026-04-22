#pragma once

#include "Weapon.h"

#include <iostream>
using namespace std;

class Sword : public Weapon
{
public:
	Sword(int damage);
	void Attack(IDamageable& damageable, float multiplicateur) override;
};