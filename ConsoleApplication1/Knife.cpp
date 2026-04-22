#include "Knife.h"

Knife::Knife(int damage) : Weapon(damage, WeaponType::KnifeType){}

void Knife::Attack(IDamageable& damageable, float multiplicateur)
{
	cout << "TIC TIC" << endl;
	damageable.TakeDamage(m_damage * multiplicateur, WeaponType::KnifeType);
}