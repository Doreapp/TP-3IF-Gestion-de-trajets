/*************************************************************************
						   Trajet Simple  -  Implémentation d'un trajet simple entre 2 villes
							 -------------------
	début                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Représente un trajet 'simple' entre deux villes avec un unique moyen de transport
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
//----------------------------------------------------Méthodes surchargées
	char* GetVilleDepart() const;
	// Mode d'emploi :
	// Renvoi la ville de départ du trajet
	// Contrat :
	
	char* GetVilleArrivee() const;
	// Mode d'emploi :
	// Renvoi la ville d'arrivé du trajet
	// Contrat :
	
	void Affiche() const;
	// Mode d'emploi :
	// Affiche le trajet
	// Contrat :

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
	TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* transport);
	// Mode d'emploi :
	// {villeDepart} représente la ville de départ du trajet
	// {villeArrivee} représente la ville d'arrivée du trajet
	// {transport} représente le moyen de transport utilisé
	// Contrat :
	// Tous les paramètres non null

	virtual ~TrajetSimple();
	// Mode d'emploi :
	// Destructeur de trajet simple
	// Contrat :

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

private:
	//----------------------------------------------------- Méthodes privées

	//----------------------------------------------------- Attributs privés
	char* villeDepart;
	//texte représentant le nom de la ville de départ du trajet

	char* villeArrivee;
	//texte représentant le nom de la ville d'arrivé du trajet

	char* transport;
	//texte représentant le moyen de transport du trajet

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJET_SIMPLE_H

