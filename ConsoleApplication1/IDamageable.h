#pragma once

#include "WeaponType.h"

class IDamageable
{
public:
	virtual ~IDamageable() = default;
	virtual void TakeDamage(int damage, WeaponType weapontype) = 0;
};
