/*************************************************************************
						   Trajet Compos�  -  Impl�mentation d'un trajet simple entre 2 villes
							 -------------------
	d�but                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

char* TrajetCompose::GetVilleDepart() const
// Algorithme :
// Retourne la ville de d�part du trajet (donc celle du premier trajet)
// Retourne null si le trajet est vide
{
	if (liste->Vide())
		return nullptr;

	return liste->Premier()->GetVilleDepart();
} //----- Fin de GetVilleDepart

char* TrajetCompose::GetVilleArrivee() const
// Algorithme :
// Retourne la ville d'arriv�e du trajet (donc celle du dernier trajet)
// Retourne null si le trajet est vide
{
	if (liste->Vide())
		return nullptr;

	return liste->Dernier()->GetVilleArrivee();
} //----- Fin de GetVilleArrivee

const void TrajetCompose::Affiche() const
// Algorithme :
// Affiche chaque trajet interne s�par�s par des -
{
	if (liste->Vide()) {
		cout << "{Vide}";
		return;
	}
	
	Element* curr = liste->PremierElement();
	while (curr != nullptr) {
		curr->contenu->Affiche();

		curr = curr->suivant;
		if (curr != nullptr)
			cout << " - ";
	}
} //----- Fin de Affiche

void TrajetCompose::Ajoute(Trajet* trajet)
// Algorithme :
// lie l'actuel dernier �l�ment � un nouoveau �l�ment li� au trajet en param�tre
// pointe dernier vers le nouvele �l�ment cr��
{
	if (liste->Vide()) {
		liste->Ajouter(trajet);
		return;
	}

	if (strcmp(liste->Dernier()->GetVilleArrivee(), trajet->GetVilleDepart())) {
		cerr << "Erreur a l'ajout, les villes ne correspondent pas ("
			<< liste->Dernier()->GetVilleArrivee()
			<< " != "
			<< trajet->GetVilleDepart()
			<< ")"
			<< endl;
		return;
	}

	liste->Ajouter(trajet);
}//----- Fin de Ajoute


//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose()
// Algorithme :
// Initialise liste
{
#ifdef MAP
	cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
	liste = new TrajetListe();
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose()
// Algorithme :
// Delete liste
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
	delete liste;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

