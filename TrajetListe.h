/*************************************************************************
						   Trajet Composé  -  Implémentation d'un trajet simple entre 2 villes
							 -------------------
	début                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetListe> (fichier TrajetListe.h) ----------------
#if ! defined ( ENSEMBLE_H )
#define ENSEMBLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetListe>
//Trajet liste représente une liste de trajets
//Dans celle ci il est facile de récupérer le premier élément ainsi que le dernier
//Les "for each" sont également facilités par des méthode (Premier et Suivant)
//------------------------------------------------------------------------

//Structure réprésentant un élément de la liste
typedef struct structElement {
	//Contenu de l'element : un trajet
	const Trajet* contenu;

	//Element suivant 
	struct structElement* suivant;
} Element;

class TrajetListe
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
		const Trajet* Suivant();
		// Mode d'emploi : 
		// A utiliser pour un foreach
		// Retourne le trajet suivant
		// Contrat :
		//

		const Trajet* Premier();
		// Mode d'emploi :
		// Retourne le premier trajet
		// Et initialise un foreach
		// Contrat :
		//

		const Trajet* Dernier();
		// Mode d'emploi :
		// Retourne le dernier trajet
		// Contrat :
		//

		void Ajouter(const Trajet* trajet);
		// Mode d'emploi :
		// Ajoute un trajet dans la liste, en dernière position
		// Contrat :
		//

		int Vide();
		// Mode d'emploi :
		// Retourne 1 (true) si la liste est vide, 0 (false) sinon
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
	TrajetListe();
	// Mode d'emploi :
	// Constructeur simple d'une liste vide
	// Contrat :
	//

	virtual ~TrajetListe();
	// Mode d'emploi :
	// Supprime la liste et chacun de ses éléments
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

private:
	//----------------------------------------------------- Méthodes privée

	//----------------------------------------------------- Attributs privée
	//Premier élément de la liste (si vide nullptr)
	Element* premier = nullptr;
	//Dernier élément de la liste (si vide nullptr)
	Element* dernier = nullptr;
	
	//Variables utilisées pour le foreach
	//indice de l'élément retourné par 'suivant'
	int foreachIndex = -1;
	//élément retourné par 'suivant'
	Element* foreachElement = nullptr;

};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // ENSEMBLE_H


