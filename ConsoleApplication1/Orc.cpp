#include "Orc.h"

Orc::Orc(int health, Weapon* weapon) : Enemy(health, weapon, EnemyType::OrcType, WeaponType::BombType, WeaponType::MagicWandType) {}

Orc::~Orc(){}

string Orc::GetName() const
{
	return "Orc";
}

void Orc::Die() const
{
	cout << "L'orc est mort!" << endl;
}

void Orc::UseWeapon(Weapon* weapon, IDamageable& target)
{
	Grunting();
	Enemy::UseWeapon(weapon, target);
}

void Orc::Grunting() const
{
	cout << "L'orc attaque : 'Grrroaww!'" << endl;
}
