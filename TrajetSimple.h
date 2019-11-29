/*************************************************************************
						   Trajet Simple  -  Impl�mentation d'un trajet simple entre 2 villes
							 -------------------
	d�but                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	char* GetVilleDepart() const;
	char* GetVilleArrivee() const;
	const void Affiche() const;

	//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur
	TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* transport);
	// Mode d'emploi :
	//		villeDepart repr�sente la ville de d�part du trajet
	//		villeArrivee repr�sente la ville d'arriv�e du trajet
	//		transport repr�sente le moyen de transport utilis�
	// Contrat :
	//

	virtual ~TrajetSimple();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

private:
	//----------------------------------------------------- M�thodes priv�es

	//----------------------------------------------------- Attributs priv�s
	char* villeDepart;
	//texte repr�sentant le nom de la ville de d�part du trajet

	char* villeArrivee;
	//texte repr�sentant le nom de la ville d'arriv� du trajet

	char* transport;
	//texte repr�sentant le moyen de transport du trajet

};

//-------------------------------- Autres d�finitions d�pendantes de <TrajetSimple>

#endif // TRAJET_SIMPLE_H

