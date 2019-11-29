/*************************************************************************
						   Trajet  -  Classe repr�sentant un trajet
							 -------------------
	d�but                : 22/11/2019 - /
	copyright            : (C) 2019/2020 par Carreau Damien et Mandin Antoine
	e-mail               : antoine.mandin@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	virtual char* GetVilleDepart() const = 0;
	// Mode d'emploi :
	// Retourne la ville de d�part du trajet sous forme de tableau de caract�re
	// Retourne NULL si m�thode non surcharg�e (impl�ment�e par une classe enfant)
	// Contrat : 
	// 

	virtual char* GetVilleArrivee() const = 0;
	// Mode d'emploi :
	// Retourne la ville d'arriv�e du trajet sous forme de tableau de caract�re
	// Retourne NULL si m�thode non surcharg�e (impl�ment�e par une classe enfant)
	// Contrat : 
	// 

	virtual const void Affiche() const = 0;
	// Mode d'emploi :
	// Affiche le trajet 
	// Affiche '{Non impl�ment�e}' si m�thode non surcharg�e (impl�ment�e par une classe enfant)
	// Contrat : 
	// 


	//------------------------------------------------- Surcharge d'op�rateurs


//-------------------------------------------- Constructeurs - destructeur
	//PAS DE CONSTRUCTEUR PUBLIC

	virtual ~Trajet();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

};

//-------------------------------- Autres d�finitions d�pendantes de <Trajet>

#endif // TRAJET_H

