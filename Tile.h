#include "stdafx.h"

#pragma once

using namespace sf;
class Tile {

public:
	Tile();
	Tile(String path, bool solide);

	//Accesseurs et mutateurs
	bool isSolide() { return solide; }
	void setSolide(bool nSolide) { solide = nSolide; }

	String texturePath;		//Path vers la texture du Tile
	Texture texture;		//Texture du Tile

protected:
	bool solide = false;	//False si le joueur peut marche dessus
};