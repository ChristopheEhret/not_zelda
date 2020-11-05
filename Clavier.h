#pragma once

#include "stdafx.h"
#include "Touche.h"

class Clavier {

public:

	Clavier();

	void update();											//Verifie quelles touches sont enfonc�es

	bool toucheEstEllePressee(Touche t);					//Verifie si la touche est utilis�e 

	Touche* getDerniereTouche() { return derniereTouche; }	//Retourne la derniere touche utilis�e dans cette frame
	std::array<Touche, 101> listeDernieresTouches;			//Liste de toutes les touches utilis�es dans la derni�re frame

protected:

	Touche* derniereTouche;									//Derni�re touche utilis�e
	int nbTouches = 0;										//Nombre de touches dans la liste
};