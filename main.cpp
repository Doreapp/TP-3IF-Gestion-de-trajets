/*******************************************************************************
						   main  -  Fichier principal de l'application
							 -------------------
	début                : 22/11/2019
	copyright            : (C) 2019-2020 par CARREAU Damien et MANDIN Antoine
	e-mail               : carreau.damien@gmail.com | antoine.mandin@insa-lyon.fr
********************************************************************************/

//------------Réalisation de la classe <main> (fichier main.cpp) ---------------

//----------------------------------------------------------------------INCLUDE

//--------------------------------------------------------------Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------------Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "TrajetListe.h"

//-------------------------------------------------------------------Constantes

//-----------------------------------------------------------------------PUBLIC

//-----------------------------------------------------------Méthodes publiques

//--------------------------------------------------------------Méthodes privés

//--------------------------------------------------Constructeurs - destructeur

int main()
// Algoritme : permet d'excuter les fonctionalités du code
// Interface homme machine
{
	char lecture[100];
	Catalogue* catalogue = new Catalogue();

	//Jeu d'esssai de base
	Trajet* ts1 = new TrajetSimple("Lyon", "Paris", "Voiture");
	catalogue->Ajoute(ts1);
	Trajet* ts2 = new TrajetSimple("Paris", "Lille", "Train");
	catalogue->Ajoute(ts2);
	TrajetCompose* tc1 = new TrajetCompose();
	tc1->Ajoute(new TrajetSimple("Nimes", "Lyon", "Bus"));
	tc1->Ajoute(new TrajetSimple("Lyon", "Grenoble", "Voiture"));
	catalogue->Ajoute(tc1);

	catalogue->Ajoute(new TrajetSimple("A", "B", "o"));
	catalogue->Ajoute(new TrajetSimple("B", "C", "o"));
	catalogue->Ajoute(new TrajetSimple("C", "D", "o"));
	catalogue->Ajoute(new TrajetSimple("D", "A", "o"));
	catalogue->Ajoute(new TrajetSimple("E", "B", "o"));
	catalogue->Ajoute(new TrajetSimple("E", "F", "o"));
	catalogue->Ajoute(new TrajetSimple("D", "B", "o"));
	catalogue->Ajoute(new TrajetSimple("A", "E", "o"));

	cout << "Bienvenue dans le menu, vous avez accés à différentes fonctionnalitées\n"
		<< "Ajout - permet d'ajouter un trajet à votre catalogue\n"
		<< "Affichage - permet d'afficher votre catalogue\n"
		<< "Recherche - retourne les trajets du catalogue allant d'une ville A à une autre B\n"
		<< "Quitter - Clos le programme\n";

	char ville_depart[100];
	char ville_arrive[100];
	char moyen[100];

	cin >> lecture;
	while (strcmp(lecture, "Quitter") != 0) {
		if (strcmp(lecture, "Ajout") == 0) {
			cout << "Entrez 0 pour ajouter un trajet simple, 1 sinon\n";
			cin >> lecture;
			if (!strcmp(lecture, "0")) {
				cout << "Entrez votre ville de départ\n";
				cin >> ville_depart;
				cout << "Entrez votre ville d'arrivé\n";
				cin >> ville_arrive;
				cout << "Entrez votre moyen de transport\n";
				cin >> moyen;

				Trajet* trajet = new TrajetSimple(ville_depart, ville_arrive, moyen);
				catalogue->Ajoute(trajet);

				cout << "Votre trajet a bien été ajouté\n";
			}
			else if (!strcmp(lecture, "1")) {
				TrajetCompose* trajet = new TrajetCompose();

				cout << "Entrez votre ville de départ\n";
				cin >> ville_depart;

				do {
					if (!strcmp(lecture, "0")) {
						strcpy(ville_depart, ville_arrive);
					}

					cout << "Entrez votre ville d'arrivé\n";
					cin >> ville_arrive;
					cout << "Entrez votre moyen de transport\n";
					cin >> moyen;

					trajet->Ajoute(new TrajetSimple(ville_depart, ville_arrive, moyen));

					cout << "Entrez 0 pour ajouter une nouvelle étape, 1 sinon\n";
					cin >> lecture;
				} while (!strcmp(lecture, "0"));

				catalogue->Ajoute(trajet);
				cout << "Votre trajet a bien été ajouté\n";
			}
			else {
				cout << "Erreur entrée - retour menu\n";
			}
		}
		else if (strcmp(lecture, "Affichage") == 0) {
			catalogue->Affiche();
		}
		else if (strcmp(lecture, "Recherche") == 0) {
			cout << "Entrez votre ville de départ\n";
			cin >> ville_depart;
			cout << "Entrez votre ville d'arrivé\n";
			cin >> ville_arrive;
			cout << "Souhaitez vous faire une recherche simple 0, ou une avancée 1\n";
			cin >> lecture;
			const TrajetListe* recherche = nullptr;
			if (!strcmp(lecture, "0")) {
				recherche = catalogue->TrouveTrajet(ville_depart, ville_arrive);
				int i = 1;
				for (const Trajet* t : *recherche) {
					cout << i++ << " : ";
					t->Affiche();
					cout << endl;
				}
			}
			else if (!strcmp(lecture, "1")) {
				//Recherche avancée
				recherche = catalogue->Recherche(ville_depart, ville_arrive);
				int i = 1;
				for (const Trajet* t : *recherche) {
					if (!strcmp(ville_depart, t->GetVilleDepart()))
						cout << i++ << " : ";

					t->Affiche();

					if (!strcmp(ville_arrive, t->GetVilleArrivee()))
						cout << endl;
					else
						cout << " - ";
				}

			}
			if (recherche == nullptr || !recherche->Taille()) {
				cout << "Trajet non trouvé\n";
			}
			delete recherche;
		}
		cin >> lecture;
	}
	delete catalogue;
	return 0;
}
// ------ Fin de Affichage

//-----------------------------------------------------------------------PRIVE

//----------------------------------------------------------Méthodes protégées
