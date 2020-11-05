#include "stdafx.h"
#include "Sortie.h"

Sortie::Sortie() {
	pathTexture = "Images/Objets/Sortie/Sortie.png";

	description = "Sortie : Objet mettant fin au niveau. Il ne peut y avoir qu'une sortie par niveau";

	textObjet.loadFromFile(pathTexture);
	taille = Vector2f(32, 32);

	niveauJoueur = true;

	idType = 72;

}

Sortie::Sortie(Vector2f pos) {
	position = pos;

	pathTexture = "Images/Objets/Sortie/Sortie.png";

	description = "Sortie : Objet mettant fin au niveau. Il ne peut y avoir qu'une sortie par niveau";

	textObjet.loadFromFile(pathTexture);
	taille = Vector2f(32, 32);

	niveauJoueur = true;

	idType = 72;

}

bool Sortie::manageCollisionEntitee(Entitee* e) {
	if (dynamic_cast<Joueur*>(e)) {
		switch (rotation)
		{
		case HAUT:
			if (e->getPos().y + e->getSize().y >= position.y - 1 && e->getPos().y + e->getSize().y < position.y + 1
					&& e->getPos().x + e->getSize().x > position.x + 3 && e->getPos().x < position.x + taille.x - 3)
				fin = true;

			break;

		case BAS: 
			if (e->getPos().y >= position.y + taille.y - 1 && e->getPos().y <= position.y + taille.y + 1
					&& e->getPos().x + e->getSize().x > position.x + 3 && e->getPos().x < position.x + taille.x - 3)
				fin = true;

			break;

		case GAUCHE:
			if (e->getPos().x + e->getSize().x >= position.x - 1 && e->getPos().x + e->getSize().x <= position.x + 1
					&& e->getPos().y + e->getSize().y > position.y + 3 && e->getPos().y < position.y + taille.y - 3)
				fin = true;

			break;

		case DROITE:
			if (e->getPos().x >= position.x + taille.x - 1 && e->getPos().x <= position.x + taille.x + 1
				&& e->getPos().y + e->getSize().y > position.y + 3 && e->getPos().y < position.y + taille.y - 3)
				fin = true;

			break;
		}

	}

	return Objet::manageCollisionEntitee(e);
}