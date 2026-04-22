#pragma once

#include "Character.h"
#include "Weapon.h"
#include "IAttack.h"
#include "EnemyType.h"

#include <iostream>
using namespace std;


class Enemy : public Character
{
protected:
	Weapon* m_weapon;
	EnemyType m_type;
	WeaponType m_favoriteWeapon;
	WeaponType m_weakness;

public:
	Enemy(int health, Weapon* weapon, EnemyType enemyType, WeaponType favoriteWeapon, WeaponType weakness);
	virtual ~Enemy();
	virtual void Die() const override;
	Weapon* GetWeapon() const ;
	virtual void UseWeapon(Weapon* weapon, IDamageable& target) override;
	virtual void TakeDamage(int damage, WeaponType weaponType) override;
	virtual void Grunting() const = 0;
};
