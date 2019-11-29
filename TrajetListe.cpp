/*************************************************************************
						   Trajet Composé  -  Implémentation d'un trajet simple entre 2 villes
							 -------------------
	début                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetListe> (fichier TrajetListe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetListe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void TrajetListe::Ajouter(Trajet* trajet)
// Algorithme :
// 
{
	if (premier == nullptr) {
		premier = new Element();
		premier->contenu = trajet;
		premier->suivant = nullptr;
		dernier = premier;
		return;
	}

	Element* nouveau = new Element();
	nouveau->contenu = trajet;
	nouveau->suivant = nullptr;

	dernier->suivant = nouveau;
	dernier = nouveau;
} //----- Fin de Ajouter

Trajet* TrajetListe::Suivant()
// // Algorithme :
//
{
	if (foreachIndex == -1)
		return Premier();

	if (foreachElement == nullptr)
		return nullptr;

	foreachElement = foreachElement->suivant;

	if (foreachElement == nullptr)
		return nullptr;

	foreachIndex++;
	return foreachElement->contenu;
}
//----- Fin de Suivant

Trajet* TrajetListe::Premier() {
	if (premier == nullptr) {
		foreachElement = nullptr;
		foreachIndex = -1;
		return nullptr;
	}
	foreachElement = premier;
	foreachIndex = 0;
	return premier->contenu;
}
// Mode d'emploi :
//
// Contrat :
//

Trajet* TrajetListe::Dernier() {
	if (dernier == nullptr) {
		return nullptr;
	}
	return dernier->contenu;
}
// Mode d'emploi :
//
// Contrat :
//

int TrajetListe::Vide()
// Algorithme :
// 
{
	return premier == nullptr;
} //----- Fin de Vide


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
TrajetListe::TrajetListe()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <TrajetListe>" << endl;
#endif
} //----- Fin de TrajetListe (constructeur)


TrajetListe::~TrajetListe()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <EnTrajetListesemble>" << endl;
#endif
	for (Element* curr = premier; curr != nullptr; curr = premier) {
		premier = curr->suivant;

		delete curr->contenu;
		delete curr;
	}
	premier = nullptr;
	foreachElement = nullptr;
	foreachIndex = -1;
} //----- Fin de ~TrajetListe





//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

