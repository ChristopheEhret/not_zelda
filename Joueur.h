#pragma once
#include "stdafx.h"
#include "Entitee.h"

#define INPUT_DROITE 0
#define INPUT_AVANT 1
#define INPUT_GAUCHE 2
#define INPUT_ARRIERE 3
#define INPUT_ATTAQUE 4

using namespace sf;
class Joueur : public Entitee {

public: 

	Joueur();

	void tick() override;
	void addInput(int input);				//Ajoute un input a gérer

protected:

	int nbInputs = 0;						//Nombre d'inputs dans la liste
	std::array<int, 5> listeInputs = {};	//Liste des inputs
};