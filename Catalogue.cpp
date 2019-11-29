/*************************************************************************
						   Catalogue  -  description
							 -------------------
	d�but                : 22/11/2019
	copyright            : (C) 2019-2020 par CARREAU Damien et MANDIN Antoine
	e-mail               : carreau.damien@gmail.com | antoine.mandin@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void Catalogue::Ajoute(const Trajet* trajet)
// Algorithme : 
// Ajoute un trajet au catalogue
{
	trajets->Ajouter(trajet);
}
// ------ Fin de Ajoute

const TrajetListe* Catalogue::TrouveTrajet(const char* depart, const char* arrivee) const
// Algorithme : 
// Trouve les trajets possibles pour aller de la ville de depart jusqu a la ville d'arriv�e
{
	TrajetListe* res = new TrajetListe();

	if (trajets->Vide()) {
		cout << "Catalogue vide";
		return res;
	}
	
	Element* curr = trajets->PremierElement();
	while (curr != nullptr) {
		if (!strcmp(curr->contenu->GetVilleDepart(), depart) && 
			!strcmp(curr->contenu->GetVilleArrivee(), arrivee))
			res->Ajouter(curr->contenu);

		curr = curr->suivant;
	}

	return res;
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

	Element* curr = trajets->PremierElement();
	int i = 1;
	while (curr != nullptr) {
		cout << i << " : ";
		curr->contenu->Affiche();
		i++;

		curr = curr->suivant;
		cout << endl;
	}
}
// ----- Fin de Affichage

//----------------------------------------------------- M�thodes priv�s

//-------------------------------------------- Constructeurs - destructeur;

Catalogue::Catalogue()
// Algorithme :
// Initialise trajets
{
#ifdef MAP
	cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

	trajets = new TrajetListe();
} //----- Fin de Catalogue


Catalogue::~Catalogue()
// Algorithme :
// Delete trajets
{
#ifdef MAP
	cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

	delete trajets;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
