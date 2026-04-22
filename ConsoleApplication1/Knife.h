#pragma once

#include "Weapon.h"

#include <iostream>
using namespace std;

class Knife : public Weapon
{
public:
	Knife(int damage);
	void Attack(IDamageable& damageable, float multiplicateur) override;
};