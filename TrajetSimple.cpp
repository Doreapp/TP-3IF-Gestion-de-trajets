/*************************************************************************
						   Trajet Simple  -  Implémentation d'un trajet simple entre 2 villes
							 -------------------
	début                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
char* TrajetSimple::GetVilleDepart() const
// Algorithme :
//
{
	return villeDepart;
} //----- Fin de GetVilleDepart

char* TrajetSimple::GetVilleArrivee() const
// Algorithme :
//
{
	return villeArrivee;
} //----- Fin de GetVilleDepart

const void TrajetSimple::Affiche() const
// Algorithme :
// Trajet de ... à .... en ...
{
	cout << "Trajet de " << villeDepart << " a " << villeArrivee << " en " << transport;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


TrajetSimple::TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* transport) 
// Algorithme :
// copy pure et simple des valeurs
{
#ifdef MAP
	cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
	this->villeDepart = new char[strlen(villeDepart) + 5];
	this->villeArrivee = new char[strlen(villeDepart) + 5];
	this->transport = new char[strlen(villeDepart) + 5];

	strcpy(this->villeDepart, villeDepart);
	strcpy(this->villeArrivee, villeArrivee);
	strcpy(this->transport, transport);
} //----- Fin de Ensemble


TrajetSimple::~TrajetSimple()
// Algorithme :
// Libère les différentes variable mémoire (3 char* ici)
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
	
	delete[] villeArrivee;
	delete[] villeDepart;
	delete[] transport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées