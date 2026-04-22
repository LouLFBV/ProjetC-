#pragma once

#include "IDamageable.h"

class IAttack
{
public:
	virtual ~IAttack() = default;
	virtual void Attack(IDamageable& damageable, float multiplicateur) = 0;
};
