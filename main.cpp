/*******************************************************************************
 			  main - description
			  ------------------

	début		: 22/11/2019
	copyright	: (C) 2019-2020 par CARREAU Damien
	e-mail		: carreau.damien@gmail.com
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

//-------------------------------------------------------------------Constantes

//-----------------------------------------------------------------------PUBLIC

//-----------------------------------------------------------Méthodes publiques

//--------------------------------------------------------------Méthodes privés

//--------------------------------------------------Constructeurs - destructeur

int main()
// Algoritme :
//
{
	char * lecture = new char[100];
	int val;
	Catalogue * catalogue = new Catalogue();

	cin >> lecture;
	while(strcmp(lecture,"Quitter")!=0){
		if(strcmp(lecture,"Ajout")==0){
			//cout << "Entrez le nombre d'étapes :";		
			cout << "AJOUT\n";
		}else if(strcmp(lecture,"Affichage")==0){
			//catalogue->Affiche();
			cout << "Affichage\n";
		}else if(strcmp(lecture,"Recherche")==0){
			char * ville_depart = new char[100];
			cout << "Entrez votre ville de départ";
			cin >> ville_depart;
			cout << "Entrez votre ville d'arrivé";
			cin >> lecture;
			Trajet * recherche = catalogue->TrouveTrajet(ville_depart,lecture);
			recherche->Affiche();
		}
		cin >> lecture;
	}	
	delete(catalogue);
	return 0;
}
// ------ Fin de Affichage

//-----------------------------------------------------------------------PRIVE

//----------------------------------------------------------Méthodes protégées
