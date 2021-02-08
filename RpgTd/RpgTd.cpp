// RpgTd.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "GameObject.h"
#include "TribeChief.h"

// g++ -o main Weapon.cpp Character.cpp main.cpp && ./main 

int main() {
    GameObject* game = new GameObject();
    Weapon* weap = new Weapon("Small Sword", 15, 2);
    Warrior* warrior = new Warrior("Soulja Toy", 100, 40, weap, { 0, 2 }, 10);
    Shaman* shaman = new Shaman("Nude Feet", 80, 15, new Weapon("Good Stick", 15, 5), { -1, -2 }, 30, 10);
    Shaman* shaman2 = new Shaman("Vanup ye", 40, 7, new Weapon("Average Stick", 10, 3), { -1, -1 }, 20, 8);
    Berserk* viking = new Berserk("Ragnorgk", 110, 55, new Weapon("Barely Sharp Axe", 40, 3), { 0, 0 }, 15);
    TribeChief<Shaman>* chief = new TribeChief<Shaman>();
    chief->setPosition({ 4, 0 });
    chief->setName("Guru BioCoop");

    cout << "##########################################" << endl;
    cout << "                  START                   " << endl;
    cout << "##########################################" << endl;
    warrior->displayInfo();
    shaman->displayInfo();
    shaman2->displayInfo();
    viking->displayInfo();
    chief->displayInfo();
    chief->SendTribe(warrior);

    cout << "##########################################" << endl;
    cout << "               FIRST MOVES                " << endl;
    cout << "##########################################" << endl;
    warrior->rotativeAttack();
    viking->attack(shaman);
    shaman->attack(warrior);
    warrior->move(-1, -3);
    warrior->rotativeAttack();
    viking->attack(warrior);
    shaman->attack(viking);

    cout << "##########################################" << endl;
    cout << "              SECOND MOVES                " << endl;
    cout << "##########################################" << endl;
    warrior->removeWeapon(weap);
    warrior->changeWeapon(warrior->addWeapon("Mega Huge Sword", 60, 6));
    warrior->rotativeAttack();
    shaman->heal(shaman);
    viking->rotativeAttack();
    shaman->throwFireball(warrior);

    cout << "##########################################" << endl;
    cout << "               THIRD MOVES                " << endl;
    cout << "##########################################" << endl;
    warrior->attack(viking);
    viking->attack(warrior);
    shaman->throwFireball(viking);
    viking->rotativeAttack();

    cout << "##########################################" << endl;
    cout << "                 ENDING                   " << endl;
    cout << "##########################################" << endl;
    warrior->displayInfo();
    shaman->displayInfo();
    shaman2->displayInfo();
    viking->displayInfo();
    chief->displayInfo();

    delete game;
    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
