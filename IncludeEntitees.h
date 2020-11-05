#pragma once
#include "Entitee.h"
#include "Joueur.h"

class IncludeEntitees {

public:

	IncludeEntitees() { }

	//Cr�e une nouvelle entit�e du type que l'entit�e pass�e en argument
	Entitee* creeNouvelleEntitee(Entitee* entiteeBase) {
		Entitee* nEntitee = nullptr;

		//Verifie la classe de l'entit�e pass�e en argument
		if (entiteeBase != nullptr) {
			if (typeid(Joueur) == typeid(*entiteeBase)) {
				nEntitee = new Joueur();
			}
		}

		return nEntitee;
	}

	//Renvoie une entit�e de la bonne classe selon l'id en argument
	Entitee* getEntiteeById(int idEntitee) {
		Entitee* nEntitee = nullptr;

		if (idEntitee > 97 && idEntitee <= 117) {
			if (idEntitee == 98)
				nEntitee = new Joueur();
		}

		return nEntitee;
	}
};