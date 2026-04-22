#include "Sword.h"

Sword::Sword(int damage) : Weapon(damage, WeaponType::SwordType){}

void Sword::Attack(IDamageable& damageable, float multiplicateur)
{
	cout << "SLASH !" << endl;
    damageable.TakeDamage(m_damage * multiplicateur, WeaponType::SwordType);
}