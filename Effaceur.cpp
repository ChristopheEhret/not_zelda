#include "stdafx.h"
#include "Effaceur.h"

Effaceur::Effaceur() {
	pathTexture = "Images/Objets/Effaceur/Effaceur.png";

	description = "Effaceur: Efface l'objet s�l�ctionn�s";

	textObjet.loadFromFile(pathTexture);
	taille = Vector2f(32, 32);

	niveauJoueur = true;
}

Effaceur::Effaceur(Vector2f pos) {
	position = pos;

	pathTexture = "Images/Objets/Effaceur/Effaceur.png";
	description = "Effaceur : Efface les objets s�l�ctionn�s";

	textObjet.loadFromFile(pathTexture);
	taille = Vector2f(32, 32);

	niveauJoueur = true;
}