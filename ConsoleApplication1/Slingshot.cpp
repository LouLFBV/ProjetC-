#include "Slingshot.h"

Slingshot::Slingshot(int damage) : Weapon(damage, WeaponType::SlingshotType){}

void Slingshot::Attack(IDamageable& damageable, float multiplicateur)
{
	cout << " PIN PIN " << endl;
	damageable.TakeDamage(m_damage * multiplicateur, WeaponType::SlingshotType);
}