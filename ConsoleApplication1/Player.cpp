#include "Player.h"

Player* Player::m_instance = nullptr;

Player* Player::GetInstance(int health, string name) {
	if (m_instance == nullptr) {
		m_instance = new Player(health, name);
	}
	return m_instance;
}

Player::Player(int health, string name) : Character(health), m_name(name) {
	m_currentWeapon = nullptr;
}

Player::~Player()
{
	m_inventory.clear();
}

string Player::GetName() const
{
	return m_name;
}


void Player::AddWeapon(Weapon* weapon)
{
	if (!InventoryFull())
		m_inventory.push_back(weapon);
}

void Player::DisplayInventory() const
{
	for (size_t i = 0; i < m_inventory.size(); ++i) {
		cout << i + 1 << ". " << m_inventory[i]->GetName() << " (Degats: " << m_inventory[i]->GetDamage() << ")" << endl;
	}
}

vector<Weapon*> Player::GetInventory() const
{
	return m_inventory;
}

bool Player::InventoryFull() const
{
	return m_inventory.size() >= MAX_INVENTORY_SIZE;
}


Weapon* Player::GetCurrentWeapon() const
{
	return m_currentWeapon;
}

void Player::SetCurrentWeapon(Weapon* weapon)
{
	if (weapon != nullptr) {
		m_currentWeapon = weapon;
	}
}

void Player::UseWeapon(Weapon* weapon, IDamageable& target)
{
	if (weapon != nullptr)
	{
		cout << m_name << " attaque ! " << endl;
		weapon->Attack(target, 1);
	}
	else
		cout << "Aucune arme equipee pour attaquer!" << endl;
}



