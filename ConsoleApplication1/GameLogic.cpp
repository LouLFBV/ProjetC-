#include "GameLogic.h"
#include "Player.h"

void ChangeWeapon()
{
	Player* player = Player::GetInstance();
	cout << "Voici vos armes disponibles : " << endl;
	player->DisplayInventory();

	string response;
	cout << endl << endl << "Voulez-vous changer d'arme ? (o/n) : ";
	cin >> response;
	cin.ignore();
	if (response == "o" || response == "O") {
		int choice;
		cout << "Entrez le numero de l'arme que vous voulez equiper : ";
		cin >> choice;
		cin.ignore();
		if (choice > 0 && choice <= player->GetInventory().size()) {
			player->SetCurrentWeapon(player->GetInventory()[choice - 1]);
			cout << "Vous avez equipe : " << typeid(*player->GetCurrentWeapon()).name() << endl;
		}
		else {
			cout << "Choix invalide !" << endl;
		}
	}
}

void StartCombat(Enemy& enemy) {

	Player* player = Player::GetInstance();
	cout << endl << endl << "Combat entre " << player->GetName() << " et un " << enemy.GetName() << " !" << endl;
	cin.get();
	if (player->GetInventory().size() > 1)
		ChangeWeapon();
	while (true) {

		player->UseWeapon(player->GetCurrentWeapon(), enemy);

		if (!enemy.IsAlive()) {
			cout << "L'ennemi a ete vaincu !" << endl;
			break;
		}

		cin.get();

		enemy.UseWeapon(enemy.GetWeapon(), *player);

		if (!player->IsAlive()) {
			cout << player->GetName() << " a ete vaincu..." << endl;
			break;
		}
		cin.get();
		cout << "Fin du tour. " << endl;
		cout << player->GetName() << " : " << player->GetCurrentHealth() << " PV / " << enemy.GetName() << " : " << enemy.GetCurrentHealth() << " PV" << endl << endl;
		cin.get();
	}
	cout << "Combat termine entre " << player->GetName() << " et un " << enemy.GetName() << " !" << endl;
}