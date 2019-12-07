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
// Représente un trajet générique
// Classe abstraite liée à une ville de départ et une ville d'arrivée
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
	virtual char* GetVilleDepart() const = 0;
	// Mode d'emploi :
	// Retourne la ville de départ du trajet sous forme de tableau de caractère
	// Méthode abstraite à implémenter par les classes enfants
	// Contrat : 

	virtual char* GetVilleArrivee() const = 0;
	// Mode d'emploi :
	// Retourne la ville d'arrivée du trajet sous forme de tableau de caractère
	// Méthode abstraite à implémenter par les classes enfants
	// Contrat : 

	virtual void Affiche() const = 0;
	// Mode d'emploi :
	// Affiche le trajet 
	// Méthode abstraite à implémenter par les classes enfants
	// Contrat : 

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
	//PAS DE CONSTRUCTEUR PUBLIC 

	virtual ~Trajet();
	// Mode d'emploi :
	// Contrat :

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
