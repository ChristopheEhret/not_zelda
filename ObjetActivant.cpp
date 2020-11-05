#include "stdafx.h"
#include "ObjetActivant.h"

ObjetActivant::ObjetActivant() {

	listeObjetsAActiver.fill(nullptr);
}

ObjetActivant::ObjetActivant(Vector2f pos) {

	listeObjetsAActiver.fill(nullptr);
}

void ObjetActivant::addObjetAActiver(ObjetActivable* nObjet) {
	if (nbObjetsAActiver < 10) {
		listeObjetsAActiver[nbObjetsAActiver] = nObjet;
		++nbObjetsAActiver;
	}
}

bool ObjetActivant::removeObjetAActiver(ObjetActivable* oObjet) {
	if (oObjet == nullptr)
		return false;

	bool remove = false;
	for (int i = 0; i < nbObjetsAActiver; i++) {
		if (listeObjetsAActiver[i] == oObjet) {
			if (removeObjetAActiver(i))
				remove = true;
		}
	}

	return remove;
}

bool ObjetActivant::removeObjetAActiver(int index) {
	if (index < 0 && index >= nbObjetsAActiver)
		return false;

	listeObjetsAActiver[index] = nullptr;
	for (int i = index; i < nbObjetsAActiver; i++) {
		if (i < 9)
			listeObjetsAActiver[i] = listeObjetsAActiver[i + 1];
		else if (i == 9)
			listeObjetsAActiver[i] = nullptr;
	}

	nbObjetsAActiver--;

	return true;
}