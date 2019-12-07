/*************************************************************************
						   Trajet Liste -  Représente une liste de trajets
							 -------------------
	début                : 22/11/2019
	copyright            : (C) 2019-2020 par CARREAU Damien et Antoine MANDIN
	e-mail               : carreau.damien@gmail.com | antoine.mandin@insa-lyon.fr
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

//---------------------------------------------------- Structures internes 
typedef struct structElement {
//-------------------------------------------------------------- Attributs
	const Trajet* contenu;
	//Contenu de l'element : un trajet

	struct structElement* suivant;
	//Element suivant 
} Element;
//Structure réprésentant un élément de la liste

typedef struct sIElement {
//-------------------------------------------------------------- Attributs
	Element* p;
	//Contenu de l'itération

	int pos;
	//Indice de l'itération

//------------------------------------------------ Surcharges d'opérateurs
	bool operator!=(struct sIElement rhs);
	//Opérateur de comparaison 	[utilisé pour l'itération]

	const Trajet* operator*();
	//Opérateur de valeur 		[utilisé pour l'itération]

	void operator++();
	//Opérateur d'incrémentation 	[utilisé pour l'itération]
} IElement;
//Structure utilisé pour les foreach (élément de l'itération)

//------------------------------------------------------ Classe principale
class TrajetListe
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
		const Trajet* GetPremier() const;
		// Mode d'emploi :
		// Retourne le premier trajet
		// Contrat :
		// null si la liste est vide

		const Trajet* GetDernier() const;
		// Mode d'emploi :
		// Retourne le dernier trajet
		// Contrat :
		// null si la liste est vide

		void Ajoute(const Trajet* trajet);
		// Mode d'emploi :
		// Ajoute un trajet dans la liste, en dernière position
		// Contrat :
		// {trajet} non null

		void Supprime(const int pos);
		// Mode d'emploi :
		// Supprime le (pos+1)ème Element de la liste
		// Contrat :
		// 0 <= pos < {length}

		int Taille() const;
		// Mode d'emploi :
		// Retourne la taille de la liste
		// Contrat :

		IElement begin() const;
		// Mode d'emploi :
		// [Méthode système] utilisée pour initialiser un foreach
		// Contrat :

		IElement end() const;
		// Mode d'emploi :
		// [Méthode système] utilisée pour finir correctement un foreach
		// Contrat :

		void LibereElements();
		// Mode d'emploi :
		// Appelle le destructeur de chaque trajet de la liste

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
	TrajetListe();
	// Mode d'emploi :
	// Constructeur simple d'une liste vide
	// Contrat :

	TrajetListe(TrajetListe* liste);
	// Mode d'emploi :
	// Constructeur de copie
	// La nouvelle liste contient les mêmes éléments (en terme d'adresse)
	// que la liste en paramètre
	// Contrat :

	virtual ~TrajetListe();
	// Mode d'emploi :
	// Supprime la liste (sans ses éléments)
	// Contrat :

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	

private:
//----------------------------------------------------- Méthodes privée

//----------------------------------------------------- Attributs privée
	Element* dernier = nullptr;
	//Dernier élément de la liste (si vide nullptr)

	Element* premier = nullptr;
	//Premier élément de la liste (si vide nullptr)

	int length = 0;
	//Taille de la liste (utile pour l'itération via foreach)
};

//-------------------------------- Autres définitions dépendantes de <TrajetListe>

#endif // TRAJET_LISTE_H
