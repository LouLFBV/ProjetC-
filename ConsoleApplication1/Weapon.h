#pragma once
#include "IAttack.h"
#include "WeaponType.h"

#include <string>
using namespace std;


class Weapon : public IAttack
{
protected:
	int m_damage;
	WeaponType m_type;
public:
	Weapon(int damage, WeaponType type);
	virtual ~Weapon() = default;
	int GetDamage() const;
	WeaponType GetType() const;
	string GetName() const;
	void Attack(IDamageable& damageable, float multiplicateur) override = 0;
};
