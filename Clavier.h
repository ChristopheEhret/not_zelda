#pragma once

#include "stdafx.h"
#include "Touche.h"

class Clavier {

public:

	Clavier();

	void update();											//Verifie quelles touches sont enfoncées

	bool toucheEstEllePressee(Touche t);					//Verifie si la touche est utilisée 

	Touche* getDerniereTouche() { return derniereTouche; }	//Retourne la derniere touche utilisée dans cette frame
	std::array<Touche, 101> listeDernieresTouches;			//Liste de toutes les touches utilisées dans la dernière frame

protected:

	Touche* derniereTouche;									//Dernière touche utilisée
	int nbTouches = 0;										//Nombre de touches dans la liste
};