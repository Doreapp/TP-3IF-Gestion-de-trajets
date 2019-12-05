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


void TrajetListe::Ajouter(const Trajet* trajet)
// Algorithme :
// Si la liste est vide, on ajoute le trajet en tant que premier et dernier
// Sinon ajoute le trajet en dernière position
{
	//Incrémente la taile de la liste :
	length++;

	//Liste vide ?
	if (premier == nullptr) {
		premier = new Element();
		premier->contenu = trajet;
		premier->suivant = nullptr;
		dernier = premier;
		return;
	}

	//Nouvel élément contenant le trajet
	Element* nouveau = new Element();
	nouveau->contenu = trajet;
	nouveau->suivant = nullptr;

	//Modification du dernier
	dernier->suivant = nouveau;
	dernier = nouveau;
} //----- Fin de Ajouter

void TrajetListe::Supprimer(const int pos)
// Algorithme :
//
{
	if (Vide())
		return;

	length--;
	if (pos == 0) {
		premier = premier->suivant;
		if (Vide())
			dernier = nullptr;
		return;
	}

	Element* before = premier;
	for (int i = 1; i < pos; i++) {
		before = before->suivant;
	}
	if (before->suivant != nullptr)
		before->suivant = before->suivant->suivant;

	if (before->suivant == nullptr)
		dernier = before;
}

const Trajet* TrajetListe::Premier() const
// Algorithme :
// retourne le premier trajet et initialise foreachElement et foreachIndex
{
	if (premier == nullptr) {
		return nullptr;
	}
	return premier->contenu;
	return nullptr;
}

Element* TrajetListe::PremierElement() const {
	return premier;
}

const Trajet* TrajetListe::Dernier()  const
// Algorithme :
// Retourne le dernier trajet 
{
	if (dernier == nullptr) {
		return nullptr;
	}
	return dernier->contenu;
	return nullptr;
}

int TrajetListe::Vide() const
// Algorithme :
// Retourne si la liste est vide, cad si il n'y a pas de premier élément
{
	return premier == nullptr;
} //----- Fin de Vide


int TrajetListe::Taille() const {
	return length;
}

IElement TrajetListe::begin() const
// Algorithme :
// [Méthode système] retourne le premier élément, indice 0
{
	return IElement(premier, 0);
}

IElement TrajetListe::end() const
// Algorithme :
// [Méthode système] retourne le dernier élément, indice {length}
{
	return IElement(dernier, length);
}

//------------------------------------------------- Surcharge d'opérateurs

bool sIElement::operator!=(struct sIElement rhs)
// Algorithme :
// retourne si les {IElement}s sont différents (indices différents) 
{
	return pos != rhs.pos;
}

const Trajet* sIElement::operator*()
// Algorithme :
// retourne la valeur de l'élément : Element->Trajet
{
	return p->contenu;
}

void sIElement::operator++()
// Algorithme :
// passe à l'élément itérable suivant : pos++ et Element = Element->suivant
{
	++pos;
	p = p->suivant;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetListe::TrajetListe()
// Algorithme :
// Constructeur vide
{
#ifdef MAP
	cout << "Appel au constructeur de <TrajetListe>" << endl;
#endif
} //----- Fin de TrajetListe (constructeur)

TrajetListe::TrajetListe(TrajetListe* liste)
// Algorithme :
// Constructeur vide
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <TrajetListe>" << endl;
#endif
	for (const Trajet* t : *liste)
		Ajouter(t);
} //----- Fin de TrajetListe (constructeur)


TrajetListe::~TrajetListe()
// Algorithme :
// Detruit chaque élément de la liste
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
	//foreachElement = nullptr;
	//foreachIndex = -1;
} //----- Fin de ~TrajetListe

sIElement::sIElement(Element* p, int pos)
// Algorithme :
// Initialise l'élément itérable, contenant l'{Element} p, à l'indice pos
	: p(p), pos(pos) 
{} //----- Fin de sIElement

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées