/*************************************************************************
						   Catalogue  -  Contient l'ensemble des trajets possibles
							 -------------------
	début                : 22/11/2019
	copyright            : (C) 2019-2020 par CARREAU Damien et Antoine MANDIN
	e-mail               : carreau.damien@gmail.com | antoine.mandin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "TrajetListe.h"
#include "TrajetCompose.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Répértorie tous les trajets possibles
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques

	void Affiche() const;
	// Mode d'emploi :
	// Affiche le catalogue sur le terminal
	// Contrat :

	void Ajoute(const Trajet* trajet);
	// Mode d'emploi :
	// Ajoute un trajet au catalogue
	// Contrat :
	// {trajet} non null

	const TrajetListe* TrouveTrajet(const char* depart, const char* arrivee) const;
	// Mode d'emploi :
	// Effectue une recherche des trajets d'une ville {depart} vers une autre {arrivee} et 
	// renvoi un tableau avec tout les trajets trouvés (dans le catalogue)
	// [RECHERCHE CLASSIQUE]
	// Contrat :
	// {depart} et {arrivee} non null

	const TrajetListe* Recherche(const char* depart, const char* arrivee) const;
	// Mode d'emploi :
	// Effectue une recherche des trajets d'une ville {depart} vers une ville {arrivee}, 
	// les composition de trajets sont possibles
	// [RECHERCHE AVANCEE]
	// Contrat :
	// {depart} et {arrivee} non null

//-------------------------------------------- Constructeurs - destructeur

	Catalogue();
	// Mode d'emploi :
	// Instancie un catalogue (alloue l'espace mémoire pour la liste)
	// Contrat :

	virtual ~Catalogue();
	// Mode d'emploi :
	// Libère l'espace mémoire utiliser par le catalogue
	// Contrat :

//------------------------------------------------------------------ PRIVE
private:
//----------------------------------------------------- Méthodes protégées
	void RechercheDepart(const char* depart, const char* arrivee, TrajetListe* into, TrajetListe* res, 
		TrajetListe* debut = nullptr) const;
	// Mode d'emploi :
	// recherche les trajets (possiblement composés) entre les villes {depart} et {arrivee}
	// en utilisant les trajets contenus dans {into} et stockant les résultats dans {res}
	// {debut} représente le trajet fait pour atteindre la ville {depart}
	// {debut} est null si {depart} est le point initial du trajet recherché
	// Contrat :
	// depart, arrivee, into et res non null


//----------------------------------------------------- Attributs protégés
	TrajetListe* trajets;
	// Enregistre tous les trajets du catalogue

};

#endif // CATALOGUE_H
