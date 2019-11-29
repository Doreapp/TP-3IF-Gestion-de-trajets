/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 22/11/2019
    copyright            : (C) 2019-2020 par CARREAU Damien
    e-mail               : carreau.damien@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Affiche( )
// Algorithme : Affiche les trajets du catalogue dans le terminal
//
{
	for(int i = 0 ; i < trajets->taille ; i++){
		trajets->tableau[i].Affiche();
		cout << "" << endl
	}
}
// ----- Fin de Affichage

//----------------------------------------------------- Méthodes privés

void Reallocation( Liste* liste )
// Algorithme : Réalloue un espace plus grand pour le tableau de trajets
//
{
	trajets->allocation+=10;
	tab* = new Trajet[trajets->allocation];
	for(int i = 0 ; i < trajets->taille ; i++){
		tab[i] = trajets->tableau[i];
	}
	delete trajets->tableau;
	trajets->tableau = tab;
} //----- Fin de Reallocation

//-------------------------------------------- Constructeurs - destructeur;

Catalogue::Catalogue ( )
// Algorithme :
//
{
	#ifdef MAP
    		cout << "Appel au constructeur de <Catalogue>" << endl;
	#endif
	
	trajets->allocation = 10;
	trajets->taille = 0;
	trajets->tableau = new Trajet[trajets->allocation];
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
	#ifdef MAP
    		cout << "Appel au destructeur de <Catalogue>" << endl;
	#endif

	for(int i = 0; i < trajets->taille ; i++ ){
		delete trajets->tableau[i];
	}
	delete[] trajets->tableau;
	delete trajets;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

