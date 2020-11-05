#include "stdafx.h"
#include "Joueur.h"

using namespace sf;
Joueur::Joueur() {
	pathFichierTextures = "Images/Entitees/Joueur/joueur_";

	taille = Vector2f(30, 30);

	vitesse = 4.f;

	idType = 98;
}

void Joueur::tick() {  
	Entitee::tick();

	vitesseDroite = 0;
	vitesseHaut = 0;

	//Change la directon et la vitesse en fonction des inputs

	for (int i = 0; i < nbInputs; i++) {
		switch (listeInputs[i])
		{
		case INPUT_DROITE:
			vitesseDroite = 1;
			direction = DROITE;
			break;
		
		case INPUT_GAUCHE:
			vitesseDroite = -1;
			direction = GAUCHE;
			break;

		case INPUT_AVANT:
			vitesseHaut = 1;
			direction = HAUT;
			break;

		case INPUT_ARRIERE:
			vitesseHaut = -1;
			direction = BAS;
			break;
		}
	}

	listeInputs.empty();
	nbInputs = 0;
}

void Joueur::addInput(int input) {
	if (nbInputs < listeInputs.size()) {
		listeInputs[nbInputs] = input;
		nbInputs++;
	}
}