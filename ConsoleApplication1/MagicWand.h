#pragma once

#include "Weapon.h"

#include <iostream>
using namespace std;

class MagicWand : public Weapon
{
public:
MagicWand(int damage);
void Attack(IDamageable& damageable, float multiplicateur) override;
};