#include "stdafx.h"
#include "ObjetActivable.h"

using namespace sf;
ObjetActivable::ObjetActivable() {

	actif = false;

	idType = 67;
}

ObjetActivable::ObjetActivable(Vector2f pos) {
	
	actif = false;

	idType = 67;
}

void ObjetActivable::tick(Carte * c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime)
{
	Objet::tick(c, listeEntitees, listeObjets, deltaTime);

	old_actif = actif;
	actif = actif_base;
}

void ObjetActivable::toggleActif() {

	actif = !actif;
}

void ObjetActivable::save(std::ofstream* fluxSave) {
	Objet::save(fluxSave);

	//Save l'etat de base
	if (*fluxSave) {
		*fluxSave << actif_base << " ";
	}
	else {
		std::cout << "Objet Activable : Impossible de créer le fichier" << std::endl;
	}
}

void ObjetActivable::load(std::ifstream* fluxLoad) {
	Objet::load(fluxLoad);

	//Charge l'etat de base
	if (fluxLoad) {
		*fluxLoad >> actif_base;
		actif = actif_base;
	}
	else {
		std::cout << "Objet Activable : Impossible de lire le fichier" << std::endl;
	}
}