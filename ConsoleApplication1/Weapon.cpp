#include "Weapon.h"


Weapon::Weapon(int damage, WeaponType type) : m_damage(damage), m_type(type) {}

int Weapon::GetDamage() const
{
	return m_damage;
}

WeaponType Weapon::GetType() const
{
	return m_type;
}

string Weapon::GetName() const
{
	switch (m_type)
	{
	case WeaponType::SwordType:
		return "une epee";
		break;
	case WeaponType::KnifeType:
		return "un couteau";
		break;
	case WeaponType::MagicWandType:
		return "une baguette magic";
		break;
	case WeaponType::SlingshotType:
		return "un lance-pierre";
		break;
	case WeaponType::BombType:
		return "des bombes";
		break;
	default:
		break;
	}
	return "une arme inconnue";
}