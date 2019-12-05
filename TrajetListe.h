/*************************************************************************
						   Trajet Liste -  Représente une liste de trajets
							 -------------------
	début                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetListe> (fichier TrajetListe.h) ----------------
#if ! defined ( TRAJET_LISTE_H )
#define TRAJET_LISTE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetListe>
// Trajet liste représente une liste de trajets
// Dans celle ci il est facile de récupérer le premier élément ainsi que le dernier
// On peut également supprimer une trajet via sont indice dans la liste
// Les "for each" sont également facilités via la structure IElement
//------------------------------------------------------------------------

//Structure réprésentant un élément de la liste
typedef struct structElement {
	//Contenu de l'element : un trajet
	const Trajet* contenu;

	//Element suivant 
	struct structElement* suivant;
} Element;

//Structure utilisé pour les foreach (élément de l'itération)
typedef struct sIElement {
	//Contenu de l'itération
	Element* p;

	//Indice de l'itération
	int pos;

	//Opérateur de comparaison [utilisé pour l'itération]
	bool operator!=(struct sIElement rhs);

	//Opérateur de valeur [utilisé pour l'itération]
	const Trajet* operator*();

	//Opérateur d'incrémentation [utilisé pour l'itération]
	void operator++();
} IElement;

class TrajetListe
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

		const Trajet* Premier() const;
		// Mode d'emploi :
		// Retourne le premier trajet
		// Et initialise un foreach
		// Contrat :
		// null si la liste est vide

		Element* PremierElement() const;
		// Mode d'emploi :
		// Retourne le premier element de la liste
		// Contrat :
		// null si la liste est vide

		const Trajet* Dernier() const;
		// Mode d'emploi :
		// Retourne le dernier trajet
		// Contrat :
		// null si la liste est vide

		void Ajouter(const Trajet* trajet);
		// Mode d'emploi :
		// Ajoute un trajet dans la liste, en dernière position
		// Contrat :
		// {trajet} non null

		void Supprimer(const int pos);
		// Mode d'emploi :
		// Supprime le (pos+1)ème Element de la liste
		// Contrat :
		// 0 <= pos < {length}

		int Vide() const;
		// Mode d'emploi :
		// Retourne 1 (true) si la liste est vide, 0 (false) sinon
		// Contrat :
		//

		int Taille() const;

		IElement begin() const;
		// Mode d'emploi :
		// [Méthode système] utilisée pour initialiser un foreach
		// Contrat :
		//

		IElement end() const;
		// Mode d'emploi :
		// [Méthode système] utilisée pour finir correctement un foreach
		// Contrat :
		//

		void deleteElements();

	//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
	TrajetListe();
	// Mode d'emploi :
	// Constructeur simple d'une liste vide
	// Contrat :
	//

	TrajetListe(TrajetListe* liste);
	// Mode d'emploi :
	// Constructeur de copie
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
	
	//Dernier élément de la liste (si vide nullptr)
	Element* dernier = nullptr;

	//Premier élément de la liste (si vide nullptr)
	Element* premier = nullptr;

	//Taille de la liste (utile pour l'itération via foreach)
	int length = 0;

};

//-------------------------------- Autres définitions dépendantes de <TrajetListe>

#endif // TRAJET_LISTE_H