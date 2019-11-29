/*************************************************************************
						   Trajet Simple  -  Impl�mentation d'un trajet simple entre 2 villes
							 -------------------
	d�but                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
char* TrajetSimple::GetVilleDepart() const
// Algorithme :
// get basique
{
	return villeDepart;
} //----- Fin de GetVilleDepart

char* TrajetSimple::GetVilleArrivee() const
// Algorithme :
// get basique
{
	return villeArrivee;
} //----- Fin de GetVilleDepart

const void TrajetSimple::Affiche() const
// Algorithme :
// "Trajet de ... � .... en ..."
{
	cout << "Trajet de " << villeDepart << " a " << villeArrivee << " en " << transport;
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* transport) 
// Algorithme :
// copy pure et simple des valeurs
{
#ifdef MAP
	cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
	this->villeDepart = new char[strlen(villeDepart) + 1];
	this->villeArrivee = new char[strlen(villeDepart) + 1];
	this->transport = new char[strlen(villeDepart) + 1];

	strcpy(this->villeDepart, villeDepart);
	strcpy(this->villeArrivee, villeArrivee);
	strcpy(this->transport, transport);
} //----- Fin de Ensemble

TrajetSimple::~TrajetSimple()
// Algorithme :
// Lib�re les diff�rentes variable m�moire (3 char* ici)
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
	
	delete[] villeArrivee;
	delete[] villeDepart;
	delete[] transport;
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

