/*******************************************************************************
 			  main - description
			  ------------------

	début		: 22/11/2019
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
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

//-------------------------------------------------------------------Constantes

//-----------------------------------------------------------------------PUBLIC

//-----------------------------------------------------------Méthodes publiques

//--------------------------------------------------------------Méthodes privés

//--------------------------------------------------Constructeurs - destructeur

int main()
// Algoritme : permet d'excuter les fonctionalités du code
// Interface homme code
//
{
	char * lecture = new char[100];
	Catalogue * catalogue = new Catalogue();
	
	Trajet * ts1 = new TrajetSimple("Lyon","Paris","Voiture");
	catalogue->Ajoute(ts1);
	Trajet * ts2 = new TrajetSimple("Paris","Lille","Train");
	catalogue->Ajoute(ts2);
	TrajetCompose * tc1 = new TrajetCompose();
	tc1->Ajoute(new TrajetSimple("Nimes","Lyon","Bus"));
	tc1->Ajoute(new TrajetSimple("Lyon","Grenoble","Voiture"));
	catalogue->Ajoute(tc1);

	cin >> lecture;
	while(strcmp(lecture,"Quitter")!=0){
		if(strcmp(lecture,"Ajout")==0){
			cout << "Entrez 0 pour ajouter un trajet simple, 1 sinon\n";
			int choix;
			cin >> choix;
			if(choix == 0){
				cout << "Entrez votre ville de départ\n";
				char * ville_depart = new char[100];
				cin >> ville_depart;
				cout << "Entrez votre ville d'arrivé\n";
				char * ville_arrive = new char[100];
				cin >> ville_arrive;
				cout << "Entrez votre moyen de transport\n";
				char * moyen = new char[100];
				cin >> moyen;
				Trajet * trajet = new TrajetSimple(ville_depart,ville_arrive,moyen);
				catalogue->Ajoute(trajet);
				cout << "Votre trajet a bien été ajouté\n";	
				delete ville_depart;
				delete ville_arrive;
				delete moyen;
			}else if(choix == 1){
				TrajetCompose * trajet = new TrajetCompose();
				char * ville_depart = new char[100];
				char * ville_arrive = new char[100];
				char * moyen = new char[100];
				do{
					cout << "Entrez votre ville de départ\n";
					cin >> ville_depart;
					cout << "Entrez votre ville d'arrivé\n";
					cin >> ville_arrive;
					cout << "Entrez votre moyen de transport\n";
					cin >> moyen;
					
					trajet->Ajoute(new TrajetSimple(ville_depart,ville_arrive,moyen));

					cout << "Entrez 1 pour ajouter une nouvelle étape, 0 sinon\n";
					cin >> choix;
				}while(choix == 1);

				catalogue->Ajoute(trajet);
				cout << "Votre trajet a bien été ajouté\n";
				delete ville_depart;
				delete ville_arrive;
				delete moyen;
			}		
		}else if(strcmp(lecture,"Affichage")==0){
			catalogue->Affiche();
		}else if(strcmp(lecture,"Recherche")==0){
			char * ville_depart = new char[100];
			cout << "Entrez votre ville de départ\n";
			cin >> ville_depart;
			cout << "Entrez votre ville d'arrivé\n";
			cin >> lecture;
			const Trajet * recherche = catalogue->TrouveTrajet(ville_depart,lecture);
			if(recherche!=nullptr)
				recherche->Affiche();
			cout << "\n";
			delete ville_depart;
		}
		cin >> lecture;
	}	
	delete catalogue;
	return 0;
}
// ------ Fin de Affichage

//-----------------------------------------------------------------------PRIVE

//----------------------------------------------------------Méthodes protégées
