/*************************************************************************
						   Trajet  -  Classe repr�sentant un trajet
							 -------------------
	d�but                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type Ensemble::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

char* Trajet::GetVilleDepart()
// Algorithme : 
// M�thode vide, � impl�ment�e par les classes enfants
{
	return nullptr;
}//----- Fin de GetVilleDepart

char* Trajet::GetVilleArrivee()
// Algorithme : 
// M�thode vide, � impl�ment�e par les classes enfants
{
	return nullptr;
}//----- Fin de GetVilleArrivee

void Trajet::Affiche()
// Algorithme : 
// M�thode vide, � impl�ment�e par les classes enfants
{
	cout << "{Non impl�ment�e}" << endl;
}//----- Fin de Affiche

//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es
Trajet::Trajet() 
// Algorithme :
// Instancie un trajet vide
{
#ifdef MAP
	cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Ensemble
