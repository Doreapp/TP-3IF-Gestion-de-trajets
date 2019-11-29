/*************************************************************************
						   Catalogue  -  description
							 -------------------
	d�but                : 22/11/2019
	copyright            : (C) 2019-2020 par CARREAU Damien
	e-mail               : carreau.damien@gmail.com
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilis�es
#include "TrajetListe.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Catalogue>
// R�p�rtorie tous les trajets possibles
//
//------------------------------------------------------------------------

class Catalogue
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	const void Affiche() const;
	// Mode d'emploi :
	//Affiche le catalogue sur le terminal
	//
	// Contrat :
	//

	void Ajoute(const Trajet* trajet);
	// Mode d'emploi :
	// Ajoute un trajet au catalogue (� la liste)
//
	// Contrat :
	//

	const Trajet* TrouveTrajet(const char* depart, const char* arrivee) const;
	// Mode d'emploi :
	// Effectue une recherche des trajets d'une ville depart vers une autre arrivee et renvoi un tableau avec tout les trajets trouv�s (dans le catalogue)
//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur

	Catalogue();
	// Mode d'emploi :
	// Instancie un catalogue (alloue l'espace m�moire pour la liste)
	//
	// Contrat :
	//

	virtual ~Catalogue();
	// Mode d'emploi :
	// Lib�re l'espace m�moire utiliser par le catalogue
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

private:
	//----------------------------------------------------- M�thodes prot�g�es


//----------------------------------------------------- Attributs prot�g�s

	TrajetListe* trajets;
	// Enregistre tous les trajets du catalogue

};

#endif // CATALOGUE_H
