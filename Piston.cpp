#include "stdafx.h"
#include "Piston.h"

using namespace sf;
Piston::Piston() {
	pathTexture = "Images/Objets/Piston/Piston.png";
	textObjet.loadFromFile(pathTexture);

	textTetePiston.loadFromFile("Images/Objets/Piston/Tete_Piston.png");

	description = "Piston : Objet activable poussant les entitées";
	taille = Vector2f(32, 32);

	niveauJoueur = true;

	idType = 68;
}

Piston::Piston(Vector2f pos) {
	position = pos;

	pathTexture = "Images/Objets/Piston/Piston.png";
	textObjet.loadFromFile(pathTexture);

	description = "Piston : Objet activable poussant les entitées";
	taille = Vector2f(32, 32);

	niveauJoueur = true;

	idType = 68;
}

void Piston::tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime) {
	//Si le piston est actif, mais pas étendu, on avance l'animation
	if (actif && etatPiston != PISTON_ETENDU) {
		timerAnimation += deltaTime;
		if (timerAnimation >= tempsAnimation) {
			++etatPiston;
			timerAnimation = 0;
		}
	}
	//Si le piston n'est pas actif, mais pas rétracté, on avance l'animation
	else if (!actif && etatPiston != PISTON_REPOS) {
		timerAnimation += deltaTime;
		if (timerAnimation >= tempsAnimation) {
			--etatPiston;
			timerAnimation = 0;
		}
	}

	//Si le piston est entrain d'etre étendu, lorqu'il change d'etat, on pousse les entitées en chemin
	if (actif && etatPiston != oldEtatPiston) {
		//Change la taille de la tete selon l'etat et la rotation du piston 
		if (etatPiston == PISTON_INTERMEDIARE) {
			if (rotation == BAS || rotation == HAUT)
				tailleTetePiston = Vector2f(32, 16);
			else
				tailleTetePiston = Vector2f(16, 32);
		}
		else if (etatPiston == PISTON_ETENDU) {
			tailleTetePiston = Vector2f(32, 32);
		}

		//Change la position de la tête selon la rotation du piston
		posTetePiston = position;
		switch (rotation)
		{
		case HAUT:
			posTetePiston.y -= 32;
			break;
		case BAS:
			posTetePiston.y += 32;
			break;
		case GAUCHE:
			posTetePiston.x -= 32;
			break;
		case DROITE:
			posTetePiston.x += 32;
			break;
		}

		//Vérifie si le piston essaie de pousser un bloc ou un objet impossible à pousser
		if (!c->verifCollision(posTetePiston, tailleTetePiston) && !bloque) {
			actif = false;
			etatPiston = PISTON_REPOS;
			return;

			bloque = true;
		}

		for (int i = 0; i < listeObjets->size(); i++) {
			if (listeObjets->at(i) != nullptr) {
				Objet* o = listeObjets->at(i);
				if (o->getPos().x + o->getSize().x > posTetePiston.x && o->getPos().x < posTetePiston.x + 32 && o->getPos().y + o->getSize().y > posTetePiston.y && o->getPos().y < posTetePiston.y + 32) {
					actif = false;
					etatPiston = PISTON_REPOS;
					return;

					bloque = true;
				}
			}
		}

		//Vérifie si le piston pousse une entitée
		for (int i = 0; i < listeEntitees->size(); i++) {
			if (listeEntitees->at(i) != nullptr) {
				Entitee* e = listeEntitees->at(i);
				if (e->getPos().x + e->getSize().x > posTetePiston.x && e->getPos().x < posTetePiston.x + tailleTetePiston.x && e->getPos().y + e->getSize().y > posTetePiston.y && e->getPos().y < posTetePiston.y + tailleTetePiston.y) {
					Vector2f newPosEntitee = e->getPos();

					//Pousse l'entitée dans la bonne direction
					switch (rotation)
					{
					case HAUT:
						newPosEntitee.y = posTetePiston.y + 32 - tailleTetePiston.y - e->getSize().y;
						break;
					case BAS:
						newPosEntitee.y = posTetePiston.y + tailleTetePiston.y;
						break;
					case GAUCHE:
						newPosEntitee.x = posTetePiston.x + 32 - tailleTetePiston.x - e->getSize().x;
						break;
					case DROITE:
						newPosEntitee.x = posTetePiston.x + tailleTetePiston.x;
						break;
					}

					e->setPos(newPosEntitee);

					//Vérifie si l'entitée se fait "ecraser" par un mur ou par un bloc
					if (!c->verifCollision(e->getPos(), e->getSize())) {
						//e->meurt();
						std::cout << "meurt" << std::endl;
					}

					for (int i = 0; i < listeObjets->size(); i++){
						if (listeObjets->at(i) != nullptr) {
							Objet* o = listeObjets->at(i);
							if (o != this && o->isNiveauJoueur())
								if (e->getPos().x + e->getSize().x > o->getPos().x && e->getPos().x < o->getPos().x + o->getSize().x && e->getPos().y + e->getSize().y > o->getPos().y && e->getPos().y < o->getPos().y + o->getSize().y) {
									//e->meurt();
									std::cout << "meurt" << std::endl;
								}
						}
					}

					//Vérifie si l'entitée va au même endroit qu'une autre entitée
					for (int i = 0; i < listeEntitees->size(); i++) {
						if (listeEntitees->at(i) != nullptr && listeEntitees->at(i) != e) {
							Entitee* e2 = listeEntitees->at(i);
							if (e->getPos().x + e->getSize().x > e2->getPos().x && e->getPos().x < e2->getPos().x + e2->getSize().x && e->getPos().y + e->getSize().y > e2->getPos().y && e->getPos().y < e2->getPos().y + e2->getSize().y) {
								//e->meurt();
								//e2->meurt();
								std::cout << "meurt" << std::endl;
								//Si oui, les deux entitées meurent
							}
						}
					}

				}
			}
		}
	}

	ObjetActivable::tick(c, listeEntitees, listeObjets, deltaTime);
}

void Piston::draw(RenderWindow* w) {

	//Charge les textures qui correspondent à l'etat du piston
	if (etatPiston != oldEtatPiston) {
		switch (etatPiston)
		{
		case PISTON_REPOS:
			textObjet.loadFromFile("Images/Objets/Piston/Piston.png");
			break;
		case PISTON_INTERMEDIARE:
			textObjet.loadFromFile("Images/Objets/Piston/Piston_Etendu.png");
			textTetePiston.loadFromFile("Images/Objets/Piston/Tete_Piston.png");
			break;

		case PISTON_ETENDU:
			textObjet.loadFromFile("Images/Objets/Piston/Piston_Etendu.png");
			textTetePiston.loadFromFile("Images/Objets/Piston/Tete_Piston_Etendu.png");
			break;
		}
	}

	//Draw le sprite de la tête au bon endroit selon la rotation du piston
	if (etatPiston != PISTON_REPOS) {
		Sprite spriteTetePiston(textTetePiston);
		spriteTetePiston.move(position);
		spriteTetePiston.rotate(rotation * 90);

		switch (rotation)
		{
		case GAUCHE:
			spriteTetePiston.move(Vector2f(-taille.x, taille.y));
			break;
		case DROITE:
			spriteTetePiston.move(Vector2f(taille.x * 2, 0));
			break;
		case BAS:
			spriteTetePiston.move(Vector2f(taille.x, taille.y * 2));
			break;
		case HAUT:
			spriteTetePiston.move(Vector2f(0, -taille.y));
			break;
		}

		w->draw(spriteTetePiston);
	}

	Objet::draw(w);

	oldEtatPiston = etatPiston;
}

bool Piston::manageCollisionEntitee(Entitee* e) {
	if(etatPiston == PISTON_ETENDU)
		if (e->getPos().x + e->getSize().x > posTetePiston.x && e->getPos().x < posTetePiston.x + 32 && e->getPos().y + e->getSize().y > posTetePiston.y && e->getPos().y < posTetePiston.y + 32) {
			return false;
		}

	Objet::manageCollisionEntitee(e);
}

bool Piston::manageCollision(Vector2f pos, Vector2f size) {
	if (etatPiston == PISTON_ETENDU)
		if (pos.x + size.x > posTetePiston.x && pos.x < posTetePiston.x + 32 && pos.y + size.y > posTetePiston.y && pos.y < posTetePiston.y + 32) {
			return false;
		}

	Objet::manageCollision(pos, size);
}