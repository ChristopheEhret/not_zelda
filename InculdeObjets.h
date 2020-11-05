#pragma once

//Header permettant d'include tous les objets dispos sans rendre le code illisible
//N'est pas fais dans "stdafx.h" pour ne pas créer d'erreurs d'include

#include "Objet.h"
#include "Cube.h"
#include "Plaque.h"
#include "Lumiere.h"
#include "Effaceur.h"
#include "ObstacleActivable.h"
#include "Piston.h"
#include "SensUnique.h"
#include "Sortie.h"

class IncludeObjets {

public:
	IncludeObjets() { }

	//Crée un nouvel objet du type que l'objet passé en argument
	Objet* creeNouvelObjet(Objet* objetBase) {
		Objet* nObjet = nullptr;
		
		//Verifie la classe de l'objet passé en argument
		if (objetBase != nullptr) {
			if (typeid(Cube) == typeid(*objetBase)) {
				nObjet = new Cube();
			}
			else if (typeid(Plaque) == typeid(*objetBase)) {
				nObjet = new Plaque();
			}
			else if (typeid(Lumiere) == typeid(*objetBase)) {
				nObjet = new Lumiere();
			}
			else if (typeid(Effaceur) == typeid(*objetBase)) {
				nObjet = new Effaceur();
			}
			else if (typeid(ObstacleActivable) == typeid(*objetBase)) {
				nObjet = new ObstacleActivable();
			}
			else if (typeid(Piston) == typeid(*objetBase)) {
				nObjet = new Piston();
			}
			else if (typeid(SensUnique) == typeid(*objetBase)) {
				nObjet = new SensUnique();
			}
			else if (typeid(Sortie) == typeid(*objetBase)) {
				nObjet = new Sortie();
			}
		}

		return nObjet;
	}

	/*

	else if (typeid(Lumiere) == typeid(*objetBase)) {
	nObjet = new Lumiere();
	}
	*/ //Schéma à copier

	Objet* getObjetById(int idType) {
		Objet* nObjet = nullptr;

		//Renvoie un objet de la bonne classe selon l'id en argument
		if (idType > 65 && idType <= 95) {
			if (idType == 66)
				nObjet = new Cube();
			else if (idType == 67)
				nObjet = new Plaque();
			else if (idType == 68)
				nObjet = new Piston();
			else if (idType == 69)
				nObjet = new ObstacleActivable();
			else if (idType == 70)
				nObjet = new Lumiere();
			else if (idType == 71)
				nObjet = new SensUnique();
			else if (idType == 72)
				nObjet = new Sortie();
		}

		return nObjet;
	}

	/*
		else if (idType == 70)
			nObjet = new Lumiere();
	*/ //Schéma à copier
};