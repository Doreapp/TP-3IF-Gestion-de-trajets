/*************************************************************************
						   Catalogue  -  Représente le catalogue des trajets disponible
							 -------------------
	début                : 22/11/2019
	copyright            : (C) 2019-2020 par CARREAU Damien et MANDIN Antoine
	e-mail               : carreau.damien@gmail.com | antoine.mandin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Ajoute(const Trajet* trajet)
// Algorithme : 
// Ajoute {trajet} au catalogue (à la liste de trajets)
{
	trajets->Ajoute(trajet);
}// ------ Fin de Ajoute

const TrajetListe* Catalogue::TrouveTrajet(const char* depart, const char* arrivee) const
// Algorithme : 
// Recherche les trajets directs allant de la ville {depart} à la ville {arrivee}
// -> Parcours simple de la liste des trajets
// Affiche 'Catalogue vide' si la liste de trajets est vide
{
	TrajetListe* res = new TrajetListe();

	if (!trajets->Taille()) {
		cout << "Catalogue vide\n";
		return res;
	}
	
	for (const Trajet* t : *trajets) {
		if (!strcmp(t->GetVilleDepart(), depart) &&
			!strcmp(t->GetVilleArrivee(), arrivee))
			res->Ajoute(t);
	}

	return res;
}// ----- Fin de TrouveTrajet


const TrajetListe* Catalogue::Recherche(const char* depart, const char* arrivee) const
// Algorithme : 
// Recherche avancée = Cherche toutes les possibles compositions de trajets permettant
// d'arriver à la ville {arrivee} en partant de la ville {depart}
// -> Voir [RechercheDepart] pour l'algorithme récursif utilisé
// Affiche 'Catalogue Vide' si la liste des trajets est vide
{
	//Liste à remplir des trajets possibles
	TrajetListe* res = new TrajetListe();

	if(!trajets->Taille()){
		cout << "Catalogue vide\n";
		return res;
	}	

	RechercheDepart(depart, arrivee, new TrajetListe(trajets), res);

	return res;
}//----- Fin de Recherche


void Catalogue::RechercheDepart(const char* depart, const char* arrivee, TrajetListe* into, 
	TrajetListe* res, TrajetListe* debut) const 
// Algorithme :
// 1) Nettoye la liste {into} des trajets finissant à la ville {arrivee} (interdit les boucles)
// 2) Pour chaques trajets de {into}
//		S'il commence par {depart} :
//			a) s'il finit par {arrivee}: l'ajouter à la liste {res}
//			b) sinon: appeler RechercheDepart avec {depart} vallant la ville d'arrivée du trajet en question
{
	// Supprimer ceux qui finissent par depart :
	int const length(into->Taille());
	int* indexes = new int[length];
	int i;

	// remplissage du tableau de -1
	for (i = 0; i < into->Taille(); i++)
		indexes[i] = -1;
	
	// Trouve les indices de trajets finissant par depart (à supprimer)
	i = 0;
	int j = 0;
	for (const Trajet* t : *into) {
		if (!strcmp(t->GetVilleArrivee(), depart) && i < length) {
			indexes[i++] = j--; //enregistre puis décrémente j, 
			//car une fois une fois un trajet supprimé, le trajet suivant à supprimer
			//sera 1 indice plus tôt dans la liste et de même pour les suivants
		}
		j++;
	}

	// Supprime réellement les trajets
	for (i = 0; i < length && indexes[i] != -1; i++) {
		into->Supprime(indexes[i]);
	}

	delete[] indexes;

	//Pour chaque trajet de {into}
	for (const Trajet* trajet : *into) 
	{
		if (!strcmp(trajet->GetVilleDepart(), depart)) 
		{
			if (!strcmp(trajet->GetVilleArrivee(), arrivee)) 
			{
				if (debut == nullptr) { // si debut null (pas de trajet avant necessaire pour arriver à {depart})
					res->Ajoute(trajet);
				}
				else { //sinon ajoute un trajet composé vallant {debut + trajet}
					for (const Trajet* t : *debut)
						res->Ajoute(t);
					res->Ajoute(trajet);
				}
			}
			//sinon
			else 
			{
				//Initalise ou incrément un trajet composé avec {trajet}
				TrajetListe* mDebut;
				if (debut == nullptr)
					mDebut = new TrajetListe();
				else
					mDebut = new TrajetListe(debut);

				mDebut->Ajoute(trajet);

				//Recherche récursivement
				RechercheDepart(trajet->GetVilleArrivee(), arrivee, new TrajetListe(into), res, mDebut);
			}
		}
	}
	if (debut != nullptr)
		delete debut;
	delete into;
}// ----- Fin de RechercheDepart


void Catalogue::Affiche() const
// Algorithme : 
// Affiche les trajets du catalogue dans le terminal
{
	if (!trajets->Taille()) {
		cout << "Catalogue vide" << endl;
		return;
	}

	int i = 1;
	for (const Trajet* t : *trajets) {
		cout << i++ << " : ";
		t->Affiche();
		cout << endl;
	}
}// ----- Fin de Affiche

//----------------------------------------------------- Méthodes privés

//-------------------------------------------- Constructeurs - destructeur;

Catalogue::Catalogue()
// Algorithme :
// Créer une liste de trajets, correspondant au catalogue
{
#ifdef MAP
	cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

	trajets = new TrajetListe();
} //----- Fin de Catalogue


Catalogue::~Catalogue()
// Algorithme :
// Appelle le destructeur de chaque trajet du catalogue
// Libère l'espace mémoire alloué au catalogue
{
#ifdef MAP
	cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
	trajets->LibereElements();
	delete trajets;
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
