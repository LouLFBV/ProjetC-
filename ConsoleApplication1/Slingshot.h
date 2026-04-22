#pragma once

#include "Weapon.h"

#include <iostream>
using namespace std;

class Slingshot : public Weapon
{
public:
	Slingshot(int damage);
	void Attack(IDamageable& damageable, float multiplicateur) override;
};