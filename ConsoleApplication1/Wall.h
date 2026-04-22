#pragma once

#include "IDamageable.h"
#include "WeaponType.h"


class Wall : public IDamageable
{
private:
	int m_durability;
public:
	Wall(int durability);
	~Wall() = default;
	int GetDurability() const;
	void TakeDamage(int damage, WeaponType weapontype) override;
};
