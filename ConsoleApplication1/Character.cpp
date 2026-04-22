#include "Character.h"

Character::Character(int health) : m_maxHealth(health), m_currentHealth(health) {}

Character::~Character() {}

bool Character::IsAlive() const
{
	return m_currentHealth > 0;
}

void Character::Die() const
{
	cout << "Le personnage est mort !" << endl;
}

int Character::GetCurrentHealth() const
{
	return m_currentHealth;
}

void Character::TakeDamage(int damage, WeaponType weaponType)
{
	m_currentHealth -= damage;
	cout << " - " << damage << " PV" << endl;
	if (m_currentHealth <= 0) {
		m_currentHealth = 0;
		Die();
	}
}

void Character::UseWeapon(Weapon* weapon, IDamageable& target)
{
	if (weapon != nullptr)
	{
		weapon->Attack(target, 1);
		cout << "Attaque avec " << weapon->GetDamage() << " points de degats!" << endl;
	}
	else
		cout << "Aucune arme equipee pour attaquer!" << endl;
}
