#include "Bomb.h"


Bomb::Bomb(int damage) : Weapon(damage, WeaponType::BombType){}

void Bomb::Attack(IDamageable& damageable, float multiplicateur)
{
	cout << " BOOM ! " << endl;
	damageable.TakeDamage(m_damage * multiplicateur, WeaponType::BombType);
}
