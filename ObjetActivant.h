#pragma once
#include "stdafx.h"
#include "ObjetActivable.h"

class ObjetActivant : public Objet {
public:

	ObjetActivant();
	ObjetActivant(Vector2f pos);

	//Accesseurs et mutateurs
	ObjetActivable* getObjetAActiver(int index) { if(index < 10 && index >= 0) return listeObjetsAActiver[index]; }
	std::array<ObjetActivable*, 10>* getListeObjetsAActiver() { return &listeObjetsAActiver; }
	void addObjetAActiver(ObjetActivable* nObjet);
	bool removeObjetAActiver(ObjetActivable* oObjet);
	bool removeObjetAActiver(int index);

protected:
	std::array<ObjetActivable*, 10> listeObjetsAActiver;	//Liste des objets à activer
	int nbObjetsAActiver = 0;								//Nombre d'objets dans la liste

};