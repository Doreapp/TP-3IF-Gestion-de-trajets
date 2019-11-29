/*************************************************************************
						   Trajet Compos�  -  Impl�mentation d'un trajet simple entre 2 villes
							 -------------------
	d�but                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Trajet.h"
#include "TrajetListe.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TrajetCompose>
// Repr�sente un trajet compos� de plusieurs trajets 
// 
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	char* GetVilleDepart() const;
	char* GetVilleArrivee() const;
	const void Affiche() const;

	void Ajoute(Trajet* trajet);
		// Mode d'emploi :
		// Ajoute le trajet � la liste des trajets 
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur
	TrajetCompose();
	// Mode d'emploi :
	// Constructeur vide
	// Contrat :
	//

	virtual ~TrajetCompose();
	// Mode d'emploi :
	// delete les trajets internes
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

private:
	//----------------------------------------------------- M�thodes priv�es

	//----------------------------------------------------- Attributs priv�s
	TrajetListe* liste;
	//liste des trajets internes
};

//-------------------------------- Autres d�finitions d�pendantes de <TrajetCompose>


#endif // TRAJET_COMPOSE_H

