/*************************************************************************
						   Trajet  -  Classe représentant un trajet
							 -------------------
	début                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	virtual char* GetVilleDepart() const = 0;
	// Mode d'emploi :
	// Retourne la ville de départ du trajet sous forme de tableau de caractère
	// Retourne NULL si méthode non surchargée (implémentée par une classe enfant)
	// Contrat : 
	// 

	virtual char* GetVilleArrivee() const = 0;
	// Mode d'emploi :
	// Retourne la ville d'arrivée du trajet sous forme de tableau de caractère
	// Retourne NULL si méthode non surchargée (implémentée par une classe enfant)
	// Contrat : 
	// 

	virtual const void Affiche() const = 0;
	// Mode d'emploi :
	// Affiche le trajet 
	// Affiche '{Non implémentée}' si méthode non surchargée (implémentée par une classe enfant)
	// Contrat : 
	// 


	//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
	//PAS DE CONSTRUCTEUR PUBLIC

	virtual ~Trajet();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H

