#pragma once

#include "stdafx.h"
#include "Tile.h"
#include "Entitee.h"

using namespace sf;
class Carte {
	
public:

	Carte();

	//dessine la carte sur la fenetre w
	void draw(RenderWindow* w);

	bool verifCollisionEntitee(Entitee e);					//Verifie si l'entitée entre en collision avec un tile de la carte
	bool verifCollision(Vector2f pos, Vector2f taille);		//Verifie si l'objet entre en collision avec un tile de la carte

	//Accesseurs et mutateurs
	Vector2f getPos() { return position; }
	void setPos(Vector2f nPos) { position = nPos; }

	Tile* getTile(int idTile) { if (idTile < 0 || idTile >= nbTilesDispos) return &listeTiles[0]; return &listeTiles[idTile]; }
	Tile* getTile(int posX, int posY);
	void setTile(int idTile, int posX, int posY);

	void save(std::ofstream* fluxSave);
	void load(std::ifstream* fluxLoad);

protected:

	//liste des tiles disponibles
	Tile listeTiles[3];
	int nbTilesDispos = 3; //Nombre de tiles disponibles

	//liste qui correspond à l'empacement de chaque blocs sur la carte
	int listeTilesCarte[20][20] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

	Vector2f position;		//Position de la carte dans la fenetre

};