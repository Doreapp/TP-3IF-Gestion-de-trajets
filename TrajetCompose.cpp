/*************************************************************************
						   Trajet Composé  -  Implémentation d'un trajet simple entre 2 villes
							 -------------------
	début                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

char* TrajetCompose::GetVilleDepart() const
// Algorithme :
// Retourne la ville de départ du trajet (donc celle du premier trajet)
// Retourne null si le trajet est vide
{
	if (liste->Vide())
		return nullptr;

	return liste->Premier()->GetVilleDepart();
} //----- Fin de GetVilleDepart

char* TrajetCompose::GetVilleArrivee() const
// Algorithme :
// Retourne la ville d'arrivée du trajet (donc celle du dernier trajet)
// Retourne null si le trajet est vide
{
	if (liste->Vide())
		return nullptr;

	return liste->Dernier()->GetVilleArrivee();
} //----- Fin de GetVilleArrivee

const void TrajetCompose::Affiche() const
// Algorithme :
// Affiche chaque trajet interne séparés par des -
{
	if (liste->Vide()) {
		cout << "{Vide}";
		return;
	}
	
	//indice du trajet affiché
	int index = 0;

	//taille totale de la liste
	int const length = liste->Taille();

	for (const Trajet* t : *liste) {
		t->Affiche;

		//s'il ne s'agit pas du dernier element, ajoute un ' - ' à la fin
		if (++index < length)
			cout << " - ";
	}
	/*Element* curr = liste->PremierElement();
	while (curr != nullptr) {
		curr->contenu->Affiche();

		curr = curr->suivant;
		if (curr != nullptr)
			cout << " - ";
	}*/
} //----- Fin de Affiche

void TrajetCompose::Ajoute(const Trajet* trajet)
// Algorithme :
// lie l'actuel dernier élément à un nouoveau élément (lié au trajet en paramètre)
// pointe dernier vers le nouvele élément créé
// Affiche une erreur si l'actuelle ville d'arrivée ne correspond pas à la ville
// de départ du trajet à ajouter
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

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose()
// Algorithme :
// Initialise la liste
{
#ifdef MAP
	cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
	liste = new TrajetListe();
} //----- Fin de TrajetCompose


TrajetCompose::TrajetCompose(TrajetCompose* src)
// Algorithme :
// Initialise liste avec les éléments contenus dans la source
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
	liste = new TrajetListe(src->liste);
}

TrajetCompose::~TrajetCompose()
// Algorithme :
// Supprime la liste 
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
	delete liste;
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

