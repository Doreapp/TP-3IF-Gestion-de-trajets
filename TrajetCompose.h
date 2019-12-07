/*************************************************************************
						   Trajet Composé  -  Implémentation d'un trajet simple entre 2 villes
							 -------------------
	début                : 22/11/2019
	copyright            : (C) 2019-2020 par CARREAU Damien et Antoine MANDIN
	e-mail               : carreau.damien@gmail.com | antoine.mandin@insa-lyon.fr
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
	// Mode d'emploi :
	// [Méthode héritée de Trajet] Renvoi la ville de départ du trajet
	// Contrat :
	
	char* GetVilleArrivee() const;
	// Mode d'emploi :
	// [Méthode héritée de Trajet] Renvoi la ville d'arrivé du trajet
	// Contrat :
	
	void Affiche() const;
	// Mode d'emploi :
	// [Méthode héritée de Trajet] Affiche le trajet
	// Contrat :

	void Ajoute(const Trajet* trajet);
	// Mode d'emploi :
	// Ajoute le trajet à la liste des trajets 
	// Contrat :
	// {trajet} non null


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
	TrajetCompose();
	// Mode d'emploi :
	// Constructeur vide
	// Contrat :

	TrajetCompose(TrajetCompose* src);
	// Mode d'emploi :
	// Constructeur de copie, possède les mêmes trajets (par adresses)
	// Contrat :
	// {src} non null

	virtual ~TrajetCompose();
	// Mode d'emploi :
	// Supprime les trajets internes
	// Contrat :

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
