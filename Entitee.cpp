#include "stdafx.h"
#include "Entitee.h"

Entitee::Entitee() {
	position = Vector2f(0, 0);

	taille = Vector2f(0, 0);
}

void Entitee::tick() {
	compteurTicksMarche++;
	if (compteurTicksMarche >= maxTicksMarche) {
		compteurTicksMarche = 0;
		marche = !marche;
	}


}

void Entitee::draw(RenderWindow* w) {
	Texture textureEntitee;

	String path = pathFichierTextures;

	//Change la texture selon la direction et si l'animation est en phase de marche

	if (direction == BAS)
		path += "bas";
	else if (direction == HAUT)
		path += "haut";
	else if (direction == DROITE)
		path += "droite";
	else if (direction == GAUCHE)
		path += "gauche";

	if (marche)
		path += "_marche";

	path += ".png";

	textureEntitee.loadFromFile(path);

	Sprite spriteEntitee(textureEntitee);
	spriteEntitee.move(position);

	w->draw(spriteEntitee);
}

void Entitee::save(std::ofstream* fluxSave) {
	if (*fluxSave) {

		*fluxSave << idType << " ";
		*fluxSave << position.x << " ";
		*fluxSave << position.y << " ";
	}
	else {
		std::cout << "Entitee : Impossible de créer le fichier" << std::endl;
	}
}

void Entitee::load(std::ifstream* fluxLoad) {
	if (*fluxLoad) {
		int posX = -1;
		int posY = -1;

		*fluxLoad >> posX;
		*fluxLoad >> posY;

		if (posX != -1 && posY != -1)
			setPos(Vector2f(posX, posY));
	}
	else {
		std::cout << "Entitee : Impossible de lire le fichier" << std::endl;
	}
}