/*************************************************************************
						   Trajet Compos�  -  Impl�mentation d'un trajet simple entre 2 villes
							 -------------------
	d�but                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetListe> (fichier TrajetListe.h) ----------------
#if ! defined ( ENSEMBLE_H )
#define ENSEMBLE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TrajetListe>
//
//
//------------------------------------------------------------------------

typedef struct structElement {
	//Contenu de l'element : un trajet
	Trajet* contenu;

	//Element suivant 
	struct structElement* suivant;
} Element;

class TrajetListe
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
		//Trajet* Recuperer(int index);
		// Mode d'emploi :
		//
		// Contrat :
		//

		Trajet* Suivant();
		// Mode d'emploi :
		//
		// Contrat :
		//

		Trajet* Premier();
		// Mode d'emploi :
		//
		// Contrat :
		//

		Trajet* Dernier();
		// Mode d'emploi :
		//
		// Contrat :
		//

		void Ajouter(Trajet* trajet);
		// Mode d'emploi :
		//
		// Contrat :
		//

		int Vide();
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'op�rateurs


//-------------------------------------------- Constructeurs - destructeur
	TrajetListe();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~TrajetListe();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

private:
	//----------------------------------------------------- M�thodes priv�e

	//----------------------------------------------------- Attributs priv�e
	Element* premier = nullptr;
	Element* dernier = nullptr;
	int foreachIndex = -1;
	Element* foreachElement = nullptr;

};

//-------------------------------- Autres d�finitions d�pendantes de <Ensemble>

#endif // ENSEMBLE_H


