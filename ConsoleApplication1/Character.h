#pragma once

#include <string>

#include "Weapon.h"
#include "IDamageable.h"

#include <iostream>
using namespace std;

class Character : public IDamageable
{
protected :
	int m_maxHealth;
	int m_currentHealth;

public:
	Character(int health);
	virtual ~Character();
	bool IsAlive() const;
	virtual string GetName() const = 0;
	virtual void Die() const;
	int GetCurrentHealth() const;
	void TakeDamage(int damage, WeaponType weaponType) override;
	virtual void UseWeapon(Weapon* weapon, IDamageable& target);
};
