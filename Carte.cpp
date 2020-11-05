#include "stdafx.h"
#include "Carte.h"

Carte::Carte() {

	//Ajoute les différents tiles disponibles dans la liste
	Tile mur = Tile("Images/Tiles/Mur.png", true);
	Tile sol = Tile("Images/Tiles/Sol.png", false);
	Tile vide = Tile("Images/Tiles/Vide.png", true);

	listeTiles[0] = mur;
	listeTiles[1] = sol;
	listeTiles[2] = vide;

	position = Vector2f(0, 0);
}

void Carte::draw(RenderWindow* w) {
	//Parcours la liste
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {

			//Prend le tile correspondant au bloc en position x,y
			Sprite sp(listeTiles[listeTilesCarte[y][x]].texture);
			
			//Déplace le sprite à la bonne position
			sp.move(x * 32 + position.x, y * 32 + position.y);

			w->draw(sp);
		}
	}
}

Tile* Carte::getTile(int posX, int posY) {

	if (posX / 32 < 0 || posX / 32 >= 20 || posY / 32 < 0 || posY / 32 >= 20)
		return &listeTiles[0]; 
	
	int x = posX / 32;
	int y = posY / 32;

	return &listeTiles[listeTilesCarte[y][x]];
}

bool Carte::verifCollisionEntitee(Entitee e) {
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {
			if (listeTiles[listeTilesCarte[y][x]].isSolide())
				if ((e.getPos().x + e.getSize().x > x * 32 + position.x && e.getPos().x < (x + 1) * 32 - 1 + position.x) && (e.getPos().y + e.getSize().y > y * 32 + position.y && e.getPos().y < (y + 1) * 32 - 1 + position.y))
					return true;
		}
	}

	return false;

	/*int posX = (e.getPos().x - position.x) / 32;
	int posY = (e.getPos().y - position.y) / 32;

	if (posX < 0 || posX >= 20 || posY < 0 || posY >= 20)
		return false;

	return !listeTiles[listeTilesCarte[posX][posY]].isSolide();*/

}

bool Carte::verifCollision(Vector2f pos, Vector2f taille) {
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {
			if (listeTiles[listeTilesCarte[y][x]].isSolide())
				if ((pos.x + taille.x > x * 32 + position.x && pos.x < (x + 1) * 32 - 1 + position.x) && (pos.y + taille.y > y * 32 + position.y && pos.y < (y + 1) * 32 - 1 + position.y))
					return false;
		}
	}

	return true;

	/*int posX = (pos.x - position.x) / 32;
	int posY = (pos.y - position.y) / 32;

	if (posX < 0 || posX >= 20 || posY < 0 || posY >= 20)
		return false;

	return !listeTiles[listeTilesCarte[posX][posY]].isSolide();*/
}

void Carte::setTile(int idTile, int posX, int posY) {
	if (posX < 0 || posX >= 20 || posY < 0 || posY >= 20 || idTile < 0 || idTile > nbTilesDispos -1)
		return;

	listeTilesCarte[posY][posX] = idTile;
}

void Carte::save(std::ofstream* fluxSave) {

	if (*fluxSave) {
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 20; x++) {
				int id = listeTilesCarte[y][x];

				*fluxSave << id;
				*fluxSave << " ";
			}
		}
	}
	else {
		std::cout << "Carte : Impossible de créer le fichier" << std::endl;
	}
}

void Carte::load(std::ifstream* fluxLoad) {
	if (*fluxLoad) {
		int newCarte[20][20] = {};

		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 20; x++) {
				int idTile = -1;

				*fluxLoad >> idTile;
				if (idTile == -1) {
					std::cout << "Carte : echec du chargement" << std::endl;
					return;
				}

				newCarte[y][x] = idTile;
			}
		}

		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 20; x++) {
				listeTilesCarte[y][x] = newCarte[y][x];
			}
		}
	}
	else {
		std::cout << "Carte : Impossible de lire le fichier" << std::endl;
	}
}