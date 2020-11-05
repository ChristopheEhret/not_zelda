#pragma once

#include "stdafx.h"

class Touche {

public:

	Touche();
	Touche(std::string n, int id, bool pressed = false , bool held = false, bool released = false);

	//Accesseurs et mutateurs
	bool isPressed() { return pressed; }
	bool isHeld() { return held; }
	bool isReleased() { return released; }
	void setPressed(bool nPressed) { pressed = nPressed; }
	void setHeld(bool nHeld) { held = nHeld; }
	void setReleased(bool nReleased) { released = nReleased; }

	sf::String getName() { return nom; }
	int getId() { return id; }

protected:
	sf::String nom = "n/a";			//Nom de la touche
	int id = -1;					//Id de la touche (Selon sfml)

	bool pressed = false;			//True si la touche est utilisée
	bool held = false;				//True si la touche est maintenue au moins 2 frames
	bool released = false;			//True si la touche est relachée mais étais maintenue à la dernière frame (inactif)

};