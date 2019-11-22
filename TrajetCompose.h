/*************************************************************************
						   Trajet Compos�  -  Impl�mentation d'un trajet simple entre 2 villes
							 -------------------
	d�but                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TrajetCompose>
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
	//----------------------------------------------------- M�thodes publiques
	char* GetVilleDepart();
	char* GetVilleArrivee();
	const void Affiche();

	void Ajoute(Trajet* trajet);
		// Mode d'emploi :
		// Ajoute le trajet � la liste des trajets 
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'op�rateurs



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
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

private:
	//----------------------------------------------------- M�thodes priv�es

	//----------------------------------------------------- Attributs priv�s
	Element* premier;
	//Premier �lement de la liste de trajet 

	Element* dernier;
	//Dernier �lement de la liste de trajet
};

//-------------------------------- Autres d�finitions d�pendantes de <Ensemble>


#endif // ENSEMBLE_H
