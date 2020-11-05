#include "stdafx.h"
#include "SensUnique.h"

using namespace sf;
SensUnique::SensUnique() {
	pathTexture = "Images/Objets/SensUnique/SensUnique.png";

	description = "SensUnique : Objet ne pouvant etre traversé que dans un seul sens";

	textObjet.loadFromFile(pathTexture);
	taille = Vector2f(32, 32);

	niveauJoueur = true;

	idType = 71;
}

SensUnique::SensUnique(Vector2f pos) {
	position = pos;

	pathTexture = "Images/Objets/SensUnique/SensUnique.png";

	description = "SensUnique : Objet ne pouvant etre traversé que dans un seul sens";

	textObjet.loadFromFile(pathTexture);
	taille = Vector2f(32, 32);

	niveauJoueur = true;

	idType = 71;
}

bool SensUnique::manageCollisionEntitee(Entitee* e) {
	switch (rotation)
	{
	case HAUT:
		if(e->getVitesseHaut() < 0)
			if (e->getPos().y + e->getSize().y >= position.y && e->getPos().y + e->getSize().y <= position.y + 1
					&& e->getPos().x + e->getSize().x > position.x && e->getPos().x < position.x + taille.x) 
				return false;

		break;

	case BAS:
		if(e->getVitesseHaut() > 0)
			if (e->getPos().y >= position.y + taille.y - 2 && e->getPos().y <= position.y + taille.y - 1
					&& e->getPos().x + e->getSize().x > position.x && e->getPos().x < position.x + taille.x) 
				return false;

		break;

	case GAUCHE:
		if(e->getVitesseDroite() > 0)
			if (e->getPos().x + e->getSize().x >= position.x && e->getPos().x + e->getSize().x <= position.x + 1
					&& e->getPos().y + e->getSize().y > position.y && e->getPos().y < position.y + taille.y) 
				return false;

		break;

	case DROITE:
		if(e->getVitesseDroite() < 0)
			if (e->getPos().x >= position.x + taille.x - 2 && e->getPos().x <= position.x + taille.x - 1
					&& e->getPos().y + e->getSize().y > position.y && e->getPos().y < position.y + taille.y) 
				return false;

		break;
	}

	return true;
}

bool SensUnique::manageCollision(Vector2f pos, Vector2f size) {

	return true;
}