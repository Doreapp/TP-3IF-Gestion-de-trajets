/*************************************************************************
						   Trajet Composé  -  Implémentation d'un trajet simple entre 2 villes
							 -------------------
	début                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

typedef struct sElement {
	Trajet* contenu;
	struct sElement* suivant;
} Element;

class TrajetCompose : public Trajet
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	char* GetVilleDepart();
	char* GetVilleArrivee();
	const void Affiche();

	void Ajoute(Trajet* trajet);
		// Mode d'emploi :
		// Ajoute le trajet à la liste des trajets 
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
	TrajetCompose();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~TrajetCompose();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

private:
	//----------------------------------------------------- Méthodes privées

	//----------------------------------------------------- Attributs privés
	Element* premier;
	//Premier élement de la liste de trajet 

	Element* dernier;
	//Dernier élement de la liste de trajet
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>


#endif // ENSEMBLE_H

