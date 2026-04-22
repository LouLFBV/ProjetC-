#include "Enemy.h"

Enemy::Enemy(int health, Weapon* weapon,EnemyType enemyType, WeaponType favoriteWeapon, WeaponType weakness) : Character(health)
{
	m_weapon = weapon;
	m_type = enemyType;
	m_favoriteWeapon = favoriteWeapon;
	m_weakness = weakness;
}

Enemy::~Enemy(){}

void Enemy::Die() const
{
	cout << "Le mechant est mort!" << endl;
}

Weapon* Enemy::GetWeapon() const
{
	return m_weapon;
}

void Enemy::TakeDamage(int damage, WeaponType weaponType)
{
	if (weaponType == m_weakness)
	{
		cout << "Votre arme inflige plus de degats a "  << GetName() << " ! Les degats sont doubles !" << endl;
		damage *= 2;
	}
	m_currentHealth -= damage;
	cout << " - " << damage << " PV" << endl;
	if (m_currentHealth <= 0) {
		m_currentHealth = 0;
		Die();
	}
}

void Enemy::UseWeapon(Weapon* weapon, IDamageable& target)
{
	if (weapon != nullptr)
	{
		string weaponName = weapon->GetName();
		if (m_favoriteWeapon == weapon->GetType())
		{
			cout << "L'ennemi utilise son arme favorite attention : " << weaponName << " !" << endl;
			weapon->Attack(target, 2);
		}
		else
		{
			cout << "L'ennemi ne sais pas trop utiliser " << weaponName << endl;
			weapon->Attack(target, 0.5);
		}
	}
}


