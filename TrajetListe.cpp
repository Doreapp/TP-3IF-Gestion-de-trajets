/*************************************************************************
						   Trajet Compos�  -  Impl�mentation d'un trajet simple entre 2 villes
							 -------------------
	d�but                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <TrajetListe> (fichier TrajetListe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetListe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques


void TrajetListe::Ajouter(const Trajet* trajet)
// Algorithme :
// Si la liste est vide, on ajoute le trajet en tant que premier et dernier
// Sinon ajoute le trajet en derni�re position
{
	//Liste vide ?
	if (premier == nullptr) {
		premier = new Element();
		premier->contenu = trajet;
		premier->suivant = nullptr;
		dernier = premier;
		return;
	}

	//Nouvel �l�ment contenant le trajet
	Element* nouveau = new Element();
	nouveau->contenu = trajet;
	nouveau->suivant = nullptr;

	//Modification du dernier
	dernier->suivant = nouveau;
	dernier = nouveau;
} //----- Fin de Ajouter

const Trajet* TrajetListe::Suivant() const
// Algorithme :
// retourne l'�l�ment suivant du foreach (null si on a atteint la fin)
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

const Trajet* TrajetListe::Premier() const
// Algorithme :
// retourne le premier trajet et initialise foreachElement et foreachIndex
{
	if (premier == nullptr) {
		foreachElement = nullptr;
		foreachIndex = -1;
		return nullptr;
	}
	foreachElement = premier;
	foreachIndex = 0;
	return premier->contenu;
}


const Trajet* TrajetListe::Dernier()  const
// Algorithme :
// Retourne le dernier trajet 
{
	if (dernier == nullptr) {
		return nullptr;
	}
	return dernier->contenu;
}


int TrajetListe::Vide() const
// Algorithme :
// Retourne si la liste est vide, cad si il n'y a pas de premier �l�ment
{
	return premier == nullptr;
} //----- Fin de Vide


//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetListe::TrajetListe()
// Algorithme :
// Constructeur vide
{
#ifdef MAP
	cout << "Appel au constructeur de <TrajetListe>" << endl;
#endif
} //----- Fin de TrajetListe (constructeur)


TrajetListe::~TrajetListe()
// Algorithme :
// Detruit chaque �l�ment de la liste
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

//----------------------------------------------------- M�thodes prot�g�es

