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
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	char* GetVilleDepart() const;
	char* GetVilleArrivee() const;
	const void Affiche() const;

	//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
	TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* transport);
	// Mode d'emploi :
	//		villeDepart représente la ville de départ du trajet
	//		villeArrivee représente la ville d'arrivée du trajet
	//		transport représente le moyen de transport utilisé
	// Contrat :
	//

	virtual ~TrajetSimple();
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
	char* villeDepart;
	//texte représentant le nom de la ville de départ du trajet

	char* villeArrivee;
	//texte représentant le nom de la ville d'arrivé du trajet

	char* transport;
	//texte représentant le moyen de transport du trajet

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJET_SIMPLE_H

