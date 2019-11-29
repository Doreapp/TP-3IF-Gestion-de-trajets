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
#include "TrajetListe.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Représente un trajet composé de plusieurs trajets 
// 
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	char* GetVilleDepart() const;
	char* GetVilleArrivee() const;
	const void Affiche() const;

	void Ajoute(Trajet* trajet);
		// Mode d'emploi :
		// Ajoute le trajet à la liste des trajets 
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
	TrajetCompose();
	// Mode d'emploi :
	// Constructeur vide
	// Contrat :
	//

	virtual ~TrajetCompose();
	// Mode d'emploi :
	// delete les trajets internes
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

private:
	//----------------------------------------------------- Méthodes privées

	//----------------------------------------------------- Attributs privés
	TrajetListe* liste;
	//liste des trajets internes
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>


#endif // TRAJET_COMPOSE_H

