#include "stdafx.h"
#include "Tile.h"

Tile::Tile() {
	texture.loadFromFile("Images/Tiles/TileError.png");
}

Tile::Tile(String path, bool solide) {
	texturePath = path;
	this->solide = solide;

	if (!texture.loadFromFile(texturePath)) {
		texture.loadFromFile("Images/Tiles/TileError.png");
	}
}