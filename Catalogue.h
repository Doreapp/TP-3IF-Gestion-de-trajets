/*************************************************************************
						   Catalogue  -  description
							 -------------------
	début                : 22/11/2019
	copyright            : (C) 2019-2020 par CARREAU Damien
	e-mail               : carreau.damien@gmail.com
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "TrajetListe.h"

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

	const void Affiche() const;
	// Mode d'emploi :
	//Affiche le catalogue sur le terminal
	//
	// Contrat :
	//

	void Ajoute(const Trajet* trajet);
	// Mode d'emploi :
	// Ajoute un trajet au catalogue (à la liste)
//
	// Contrat :
	//

	const TrajetListe* TrouveTrajet(const char* depart, const char* arrivee) const;
	// Mode d'emploi :
	// Effectue une recherche des trajets d'une ville depart vers une autre arrivee et renvoi un tableau avec tout les trajets trouvés (dans le catalogue)
//
	// Contrat :
	//

	const TrajetListe* Recherche(const char* depart, const char* arrivee) const;
	//Mode d'emploi :
	// Effectue une recherche des trajets d'une ville depart vers une ville arrivee, les composition de trajets sont possibles
	//
	//Contrat :

//-------------------------------------------- Constructeurs - destructeur

	Catalogue();
	// Mode d'emploi :
	// Instancie un catalogue (alloue l'espace mémoire pour la liste)
	//
	// Contrat :
	//

	virtual ~Catalogue();
	// Mode d'emploi :
	// Libère l'espace mémoire utiliser par le catalogue
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

private:
	//----------------------------------------------------- Méthodes protégées


//----------------------------------------------------- Attributs protégés

	TrajetListe* trajets;
	// Enregistre tous les trajets du catalogue

};

#endif // CATALOGUE_H
