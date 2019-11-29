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
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Ajoute(const Trajet* trajet)
// Algorithme : Ajoute un trajet au catalogue
//
{
	trajets->Ajouter(trajet);
}
// ------ Fin de Ajoute

Trajet* Catalogue::TrouveTrajet(const char* depart, const char* arrivee) const
// Algorithme : Trouve les trjats possibles pour aller de la ville de depart jusqu a la ville d arrivee
//
{
	cout << "Le programme trouve les trajets";

}
// ----- Fin de trouve trajet

const void Catalogue::Affiche() const
// Algorithme : Affiche les trajets du catalogue dans le terminal
//
{
	if (trajets->Vide()) {
		cout << "Catalogue vide";
		return;
	}

	const Trajet* curr = trajets->Premier();
	int i = 1;
	while (curr != nullptr) {
		cout << i << " : ";
		curr->Affiche();
		i++;

		curr = trajets->Suivant();
		if (curr != nullptr)
			cout << endl;
	}
}
// ----- Fin de Affichage

//----------------------------------------------------- Méthodes privés

//-------------------------------------------- Constructeurs - destructeur;

Catalogue::Catalogue()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

	trajets = new TrajetListe();
} //----- Fin de Catalogue


Catalogue::~Catalogue()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

	delete trajets;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
