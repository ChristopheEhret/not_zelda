#include "stdafx.h"
#include "Objet.h"

using namespace sf;
Objet::Objet() {
	position = Vector2f(0, 0);

	textObjet.loadFromFile("Images/Tiles/TileError.png");
	taille = Vector2f(textObjet.getSize().x, textObjet.getSize().y);

	idType = 65;
}

Objet::Objet(Vector2f pos) {
	position = pos;

	textObjet.loadFromFile("Images/Tiles/TileError.png");
	taille = Vector2f(textObjet.getSize().x, textObjet.getSize().y);

	idType = 65;
}

void Objet::draw(RenderWindow* w) {
	Sprite spObjet = Sprite(textObjet);
	spObjet.move(position);

	//Deplace le sprite selon la rotation, car la rotation ne se fait pas au niveau du centre mais au niveau de l'origine
	switch (rotation)
	{
	case GAUCHE:
		spObjet.move(Vector2f(0, taille.y));
		break;
	case DROITE:
		spObjet.move(Vector2f(taille.x, 0));
		break;
	case BAS:
		spObjet.move(Vector2f(taille.x, taille.y));
		break;
	}
	spObjet.setRotation(90 * rotation);

	w->draw(spObjet);
}

void Objet::tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime) {
	
}

bool Objet::manageCollisionEntitee(Entitee* e) {
	if (e->getPos().x + e->getSize().x > position.x && e->getPos().x < position.x + taille.x && e->getPos().y + e->getSize().y > position.y && e->getPos().y < position.y + taille.y) {
		return false;
	}

	return true;
}

bool Objet::manageCollision(Vector2f pos, Vector2f size) {
	if (pos.x + size.x > position.x && pos.x < position.x + taille.x && pos.y + size.y > position.y && pos.y < position.y + taille.y) {
		return false;
	}

	return true;
}

//Demander a raph : Destruction?
void Objet::save(std::ofstream* fluxSave) {
	if (*fluxSave) {
		*fluxSave << idType << " ";
		*fluxSave << position.x << " ";
		*fluxSave << position.y << " ";
		*fluxSave << rotation << " ";

	}
	else {
		std::cout << "Objet : Impossible de créer le fichier" << std::endl;
	}
}

void Objet::load(std::ifstream* fluxLoad) {
	if (*fluxLoad) {
		int posX = -1;
		int posY = -1;
		int rot = -1;

		*fluxLoad >> posX;
		*fluxLoad >> posY;
		*fluxLoad >> rot;

		if (posX != -1 && posY != -1)
			setPos(Vector2f(posX, posY));

		if (rot != -1)
			setRotation(rot);
	}
	else {
		std::cout << "Objet : Impossible de lire le fichier" << std::endl;
	}
}