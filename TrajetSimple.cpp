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
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
char* TrajetSimple::GetVilleDepart()
// Algorithme :
//
{
	return villeDepart;
} //----- Fin de GetVilleDepart

char* TrajetSimple::GetVilleArrivee()
// Algorithme :
//
{
	return villeArrivee;
} //----- Fin de GetVilleDepart


//------------------------------------------------- Surcharge d'opérateurs
TrajetSimple& TrajetSimple::operator = (const TrajetSimple& unTrajetSimple)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur


TrajetSimple::TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* transport)
// Algorithme :
//
{
	//TODO ! 
#ifdef MAP
	cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
} //----- Fin de Ensemble


TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

