#include "Goblin.h"

Goblin::Goblin(int health, Weapon* weapon) : Enemy(health, weapon, EnemyType::GoblinType, WeaponType::KnifeType, WeaponType::BombType){}

Goblin::~Goblin(){}

string Goblin::GetName() const
{
	return "Goblin";
}

void Goblin::Die() const
{
	cout << "Le Gobelin est mort !" << endl;
}

void Goblin::UseWeapon(Weapon* weapon, IDamageable& target)
{
	Grunting();
	Enemy::UseWeapon(weapon, target);
}

void Goblin::Grunting() const
{
	cout << "Le Gobelin attaque : 'Grrr!'" << endl;
}