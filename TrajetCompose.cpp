/*************************************************************************
						   Trajet Composé  -  Implémentation d'un trajet simple entre 2 villes
							 -------------------
	début                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

char* TrajetCompose::GetVilleDepart()
// Algorithme :
// Retourne la ville de départ du trajet (donc celle du premier trajet)
// Retourne null si le trajet est vide
{
	if (premier == nullptr)
		return nullptr;

	return premier->contenu->GetVilleDepart();
} //----- Fin de GetVilleDepart

char* TrajetCompose::GetVilleArrivee()
// Algorithme :
// Retourne la ville d'arrivée du trajet (donc celle du dernier trajet)
// Retourne null si le trajet est vide
{
	if (dernier == nullptr)
		return nullptr;

	return dernier->contenu->GetVilleArrivee();
} //----- Fin de GetVilleArrivee

const void TrajetCompose::Affiche() 
// Algorithme :
// Affiche chaque trajet interne séparés par des -
{
	if (premier == nullptr) {
		cout << "{Vide}";
		return;
	}

	for (Element* curr = premier; curr != nullptr; curr = curr->suivant) {
		curr->contenu->Affiche();

		if (curr->suivant != nullptr)
			cout << " - ";
	}
	
} //----- Fin de Affiche

void TrajetCompose::Ajoute(Trajet* trajet)
// Algorithme :
// lie l'actuel dernier élément à un nouoveau élément lié au trajet en paramètre
// pointe dernier vers le nouvele élément créé
{
	if (premier == nullptr) {
		premier = new Element();
		premier->contenu = trajet;
		premier->suivant = nullptr;
		dernier = premier;
		return;
	}

	if (strcmp(dernier->contenu->GetVilleArrivee(), trajet->GetVilleDepart())) {
		cerr << "Erreur a l'ajout, les villes ne correspondent pas ("
			<< dernier->contenu->GetVilleArrivee()
			<< " != "
			<< trajet->GetVilleDepart()
			<< ")"
			<< endl;
		return;
	}

	Element *nouveau = new Element();
	nouveau->contenu = trajet;
	nouveau->suivant = nullptr;
	
	dernier->suivant = nouveau;
	dernier = nouveau;
}//----- Fin de Ajoute



//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
	premier = nullptr;
	dernier = nullptr;
} //----- Fin de Ensemble


TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Ensemble>" << endl;
#endif

	for (Element* curr = premier; curr != nullptr; curr = premier) {
		premier = curr->suivant;

		delete curr->contenu;
		delete curr;
	}
	premier = nullptr;
	dernier = nullptr;
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

