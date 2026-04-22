#include "MagicWand.h"

MagicWand::MagicWand(int damage) : Weapon(damage, WeaponType::MagicWandType){}

void MagicWand::Attack(IDamageable& damageable, float multiplicateur)
{
	cout << "**Son de magie**" << endl;
	damageable.TakeDamage(m_damage * multiplicateur, WeaponType::MagicWandType);
}