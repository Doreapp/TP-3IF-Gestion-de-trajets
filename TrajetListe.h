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
//Trajet liste repr�sente une liste de trajets
//Dans celle ci il est facile de r�cup�rer le premier �l�ment ainsi que le dernier
//Les "for each" sont �galement facilit�s par des m�thode (Premier et Suivant)
//------------------------------------------------------------------------

//Structure r�pr�sentant un �l�ment de la liste
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
	//----------------------------------------------------- M�thodes publiques
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
		// Ajoute un trajet dans la liste, en derni�re position
		// Contrat :
		//

		int Vide();
		// Mode d'emploi :
		// Retourne 1 (true) si la liste est vide, 0 (false) sinon
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'op�rateurs


//-------------------------------------------- Constructeurs - destructeur
	TrajetListe();
	// Mode d'emploi :
	// Constructeur simple d'une liste vide
	// Contrat :
	//

	virtual ~TrajetListe();
	// Mode d'emploi :
	// Supprime la liste et chacun de ses �l�ments
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

private:
	//----------------------------------------------------- M�thodes priv�e

	//----------------------------------------------------- Attributs priv�e
	//Premier �l�ment de la liste (si vide nullptr)
	Element* premier = nullptr;
	//Dernier �l�ment de la liste (si vide nullptr)
	Element* dernier = nullptr;
	
	//Variables utilis�es pour le foreach
	//indice de l'�l�ment retourn� par 'suivant'
	int foreachIndex = -1;
	//�l�ment retourn� par 'suivant'
	Element* foreachElement = nullptr;

};

//-------------------------------- Autres d�finitions d�pendantes de <Ensemble>

#endif // ENSEMBLE_H


