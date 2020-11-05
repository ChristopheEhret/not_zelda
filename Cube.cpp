#include "stdafx.h"
#include "Cube.h"

using namespace sf;
Cube::Cube() {
	pathTexture = "Images/Objets/Cube/Cube.png";

	description = " Cube : Deplacable par le joueur,  il permet l'activation de mécanismes";

	textObjet.loadFromFile(pathTexture);
	taille = Vector2f(28, 28);

	niveauJoueur = true;

	idType = 66;
}

Cube::Cube(Vector2f pos) {
	position = pos;

	pathTexture = "Images/Objets/Cube/Cube.png";

	description = "Cube : Deplacable par le joueur, il permet l'activation de mécanismes";

	textObjet.loadFromFile(pathTexture);
	taille = Vector2f(28, 28);

	niveauJoueur = true;

	idType = 66;
}

void Cube::tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime) {
	//Fais bouger le cube si besoin
	if (vitesseDroite != 0) {
		float deplacementDroite = (vitesse * deltaTime) / 16;
		while (deplacementDroite >= 1)
		{
			position.x += vitesseDroite;
			--deplacementDroite;

			//Verifie les collisions avec les objets, les entitées et la carte
			bool collision = false;
			collision = !c->verifCollision(position, taille);

			for (int i = 0; i < listeObjets->size(); i++) {
				if (listeObjets->at(i) != nullptr && listeObjets->at(i) != this)
					if (listeObjets->at(i)->isNiveauJoueur())
						if (!collision)
							collision = !listeObjets->at(i)->manageCollision(this->getPos(), this->getSize());
			}

			for (int i = 0; i < listeEntitees->size(); i++) {
				if (listeEntitees->at(i) != nullptr) {
					Entitee* e = listeEntitees->at(i);
					if (e->getPos().x + e->getSize().x > position.x && e->getPos().x < position.x + taille.x && e->getPos().y + e->getSize().y > position.y && e->getPos().y < position.y + taille.y)
						collision = true;
				}
			}

			if (collision) {
				position.x -= vitesseDroite;
				deplacementDroite = 0;
			}
		}

	}

	if (vitesseHaut != 0) {
		float deplacementHaut = (vitesse * deltaTime) / 16;

		while (deplacementHaut >= 1) {
			position.y -= vitesseHaut;
			--deplacementHaut;

			//Verifie les collisions avec les objets, les entitées et la carte
			bool collision = false;
			collision = !c->verifCollision(position, taille);

			for (int i = 0; i < listeObjets->size(); i++) {
				if (listeObjets->at(i) != nullptr && listeObjets->at(i) != this)
					if (listeObjets->at(i)->isNiveauJoueur())
						if(!collision)
								collision = !listeObjets->at(i)->manageCollision(this->getPos(), this->getSize());
				
			}

			for (int i = 0; i < listeEntitees->size(); i++) {
				if (listeEntitees->at(i) != nullptr) {
					Entitee* e = listeEntitees->at(i);
					if (e->getPos().x + e->getSize().x > position.x && e->getPos().x < position.x + taille.x && e->getPos().y + e->getSize().y > position.y && e->getPos().y < position.y + taille.y)
						collision = true;
				}
			}

			if (collision) {
				position.y += vitesseHaut;
				deplacementHaut = 0;
			}
		}
	}

	vitesseDroite = 0;
	vitesseHaut = 0;
}

bool Cube::manageCollisionEntitee(Entitee* e) {
	//Si une entitee fais bouger le cube
	if (e->getPos().x + e->getSize().x > position.x && e->getPos().x < position.x + taille.x && e->getPos().y + e->getSize().y > position.y && e->getPos().y < position.y + taille.y) {
		if (e->getVitesseDroite() != 0)
			vitesseDroite = e->getVitesseDroite();
		else if(e->getVitesseHaut() != 0)
			vitesseHaut = e->getVitesseHaut();

		return false;
	}

	return true;
}