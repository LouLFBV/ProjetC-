#include "Mage.h"

Mage::Mage(int health, Weapon* weapon) : Enemy(health, weapon, EnemyType::MageType, WeaponType::MagicWandType, WeaponType::SwordType){}

Mage::~Mage(){}

string Mage::GetName() const
{
	return "Mage";
}

void Mage::Die() const
{
	cout << " Le Mage est mort!" << endl;
}

void Mage::UseWeapon(Weapon* weapon, IDamageable& target)
{
	Grunting();
	Enemy::UseWeapon(weapon, target);
}

void Mage::Grunting() const
{
	cout << "Le Mage attaque : 'Incantation...'" << endl;
}