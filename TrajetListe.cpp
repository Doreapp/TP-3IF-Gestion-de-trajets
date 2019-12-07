/*************************************************************************
						   Trajet Liste  -  Représente une liste de trajets
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
// si vide, ne fait rien
// sinon supprimer l'élement en (pos+1)ème position de la liste 
// (sans le supprimer de la mémoire)
{
	if (!length) //si vide
		return;

	length--;
	if (pos == 0) {
		premier = premier->suivant;
		if (!length) //si désormais vide
			dernier = nullptr;
		return;
	}

	//recherche l'élément juste avant l'élément à supprimer (ième élément)
	Element* before = premier;
	for (int i = 1; i < pos; i++) {
		before = before->suivant;
	}
	if (before->suivant != nullptr){
		//Element pour lequel la mémoire doit être libérée
		Element* toFree = before->suivant;

		before->suivant = toFree->suivant;
		
		delete toFree;
	}

	if (before->suivant == nullptr)
		dernier = before;
}//----- fin de Supprimer

const Trajet* TrajetListe::Premier() const
// Algorithme :
// retourne le premier trajet (null si la liste est vide)
{
	if (!length) {
		return nullptr;
	}
	return premier->contenu;
}//----- fin de Premier

const Trajet* TrajetListe::Dernier()  const
// Algorithme :
// Retourne le dernier trajet 
{
	if (dernier == nullptr) {
		return nullptr;
	}
	return dernier->contenu;
}//----- fin de Dernier


int TrajetListe::Taille() const {
	return length;
}

IElement TrajetListe::begin() const
// Algorithme :
// [Méthode système] retourne le premier élément d'ittération, indice 0
{
	IElement res = IElement();
	res.p = premier;
	res.pos = 0;
	return res;
}//----- fin de begin

IElement TrajetListe::end() const
// Algorithme :
// [Méthode système] retourne le dernier élément d'ittération, indice {length}
{
	IElement res = IElement();
	res.p = dernier;
	res.pos = length;
	return res;
}//----- fin de end

//------------------------------------------------- Surcharge d'opérateurs

bool sIElement::operator!=(struct sIElement rhs)
// Algorithme :
// retourne si les [IElement]s sont différents (indices différents) 
{
	return pos != rhs.pos;
}//----- fin de operator!=

const Trajet* sIElement::operator*()
// Algorithme :
// retourne la valeur de l'élément : Element->Trajet
{
	return p->contenu;
}//----- fin de operator*

void sIElement::operator++()
// Algorithme :
// passe à l'élément ittérable suivant : pos++ et Element = Element->suivant
{
	++pos;
	p = p->suivant;
}//----- fin de operator++

void TrajetListe::deleteElements()
// Algorithme :
// libère l'espace mémoire de tous les trajets de la liste
{
	for (const Trajet* t : *this)
		delete t;
}//----- fin de deleteElements

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
} //----- Fin de TrajetListe (constructeur de copie)

TrajetListe::~TrajetListe()
// Algorithme :
// Detruit chaque élément de la liste
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetListe>" << endl;
#endif
	for (Element* curr = premier; curr != nullptr; curr = premier) {
		premier = curr->suivant;

		delete curr;
	}
	premier = nullptr;
	length = 0;
} //----- Fin de ~TrajetListe

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
