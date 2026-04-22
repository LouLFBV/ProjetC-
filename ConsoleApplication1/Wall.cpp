#include "Wall.h"


#include <iostream>
using namespace std;

Wall::Wall(int durability) : m_durability(durability){}

void Wall::TakeDamage(int damage, WeaponType weapontype)
{
	m_durability -= damage;
	cout << "La mur subit " << damage << " de degats." << endl;
	if (m_durability < 0)
	{
		cout << "Et il se detruit!" << endl;
		m_durability = 0;
	}
}


int Wall::GetDurability() const
{
	return m_durability;
}