/*************************************************************************
						   Trajet  -  Classe représentant un trajet
							 -------------------
	début                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

char* Trajet::GetVilleDepart()
// Algorithme : 
// Méthode vide, à implémentée par les classes enfants
{
	return nullptr;
}//----- Fin de GetVilleDepart

char* Trajet::GetVilleArrivee()
// Algorithme : 
// Méthode vide, à implémentée par les classes enfants
{
	return nullptr;
}//----- Fin de GetVilleArrivee

void Trajet::Affiche()
// Algorithme : 
// Méthode vide, à implémentée par les classes enfants
{
	cout << "{Non implémentée}" << endl;
}//----- Fin de Affiche

//------------------------------------------------- Surcharge d'opérateurs
Trajet& Trajet::operator = (const Trajet& unEnsemble)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
// PAS DE CONSTUCTEUR PUBLIC

Trajet::~Trajet()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
Trajet::Trajet() 
// Algorithme :
// Instancie un trajet vide
{
#ifdef MAP
	cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet
