# 🏰 Dungeon Crawler - RPG Console

Un jeu de rôle (RPG) textuel développé en C++ illustrant les principes fondamentaux de la programmation orientée objet (POO), les design patterns et la gestion dynamique de la mémoire.

## 📝 Présentation du Projet

Dans ce jeu, le joueur incarne un héros qui doit traverser un donjon généré aléatoirement. Pour sortir vivant, il devra vaincre une série d'ennemis (Orcs, Gobelins, Mages) et détruire des obstacles pour trouver de nouvelles armes.

### Points clés :
- **Système de Combat** : Combat au tour par tour entre le joueur et des ennemis aux caractéristiques variées.
- **Gestion d'Inventaire** : Possibilité de collecter plusieurs armes et de changer d'équipement en plein combat.
- **Génération Aléatoire** : Le nombre d'ennemis, leur santé et leur équipement changent à chaque partie.


## 🛠 Concepts de Programmation Utilisés

Ce projet a été conçu pour mettre en pratique des concepts avancés du C++ :

### 1. Design Pattern : 

- `Singleton` :
La classe `Player` utilise le motif **Singleton**. Cela garantit qu'une seule instance du joueur existe tout au long de la partie et qu'elle est accessible de n'importe où dans le code via `Player::GetInstance()`.
 *Sécurité* : Le constructeur de copie et l'opérateur d'assignation sont supprimés (`= delete`) pour empêcher toute duplication.
- `Strategy` : Peu importe l'arme utilisée, elles seront utilisées de la même façon grâce à l'interface IAttack.

### 2. Héritage et Polymorphisme
- **Entités** : `Player` et `Enemy` héritent d'une classe de base `Character`, les différents ennemis héritent de `Enemy`.
- **Armes** : Toutes les armes (`Sword`, `Bomb`, `MagicWand`, etc.) héritent de la classe abstraite `Weapon`.
- **Interface** : Utilisation de l'interface `IDamageable` pour permettre au joueur d'attaquer aussi bien des ennemis que des objets statiques (murs).
Mais aussi de `IAttack` pour gérer les méthodes d'attaques de chaques armes.

### 3. Gestion de la Mémoire 
Le projet utilise une classe `Dungeon` pour orchestrer le cycle de vie du jeu. 
- **Allocation** : Les objets sont créés dynamiquement sur le tas (heap) lors de l'initialisation.
- **Libération** : Le destructeur `~Dungeon()` assure le nettoyage systématique de la mémoire (via `delete`) pour éviter toute fuite de mémoire.

### 4. Modularité
Le code est séparé en plusieurs fichiers :
- `Dungeon.h/cpp` : Logique de haut niveau et gestion des ressources.
- `GameLogic.h/cpp` : Fonctions utilitaires de combat et d'interaction.
- `Player.h/cpp` : Gestion de l'état unique du joueur.


## 🚀 Comment lancer le jeu

### Prérequis
- Un compilateur C++ (supportant au moins le C++11).
- Un environnement de développement (VS Code, Visual Studio, CLion) ou un terminal.

### Compilation
Utilisez la commande suivante dans votre terminal en étant dans le dossier `/ConsoleAppliation1` (en incluant tous les fichiers `.cpp`) :
```bash
g++ -o dungeon_game *.cpp
```
### Exécution
```
Bash
./dungeon_game
```
## 🎮 Déroulement d'une partie
- Configuration : Entrez votre nom et choisissez votre santé de départ.
- Exploration : Le jeu génère entre 3 et 10 ennemis.

### Combat :
- Vous attaquez en premier.
- Vous pouvez changer d'arme si vous en possédez plusieurs.
- Après chaque victoire, vous devez détruire un mur qui peut cacher un butin.
- Victoire : Éliminez tous les ennemis pour sortir du donjon.


## 📂 Structure des fichiers principaux
```main.cpp``` : Point d'entrée, instancie la classe Dungeon.

```Dungeon.cpp``` : Initialise les listes d'armes et d'ennemis.

```Character.h``` : Classe parente définissant la santé et les méthodes de base.

```Weapon.h``` : Classe abstraite définissant le comportement des armes.

```Wall.h``` : Objet destructible implémentant IDamageable.
