#pragma once
#include "stdafx.h"
#include "Bouton.h"

using namespace sf;
class Menu {
public:

	Menu(String pathFond = "null");
	Menu(Vector2f pos, Vector2f size, String pathFond = "null");
	
	virtual void tick(RenderWindow* w);
	virtual void draw(RenderWindow* w);

	//Accesseurs et mutateurs
	Bouton* getBouton(int index) { if (index >= 0 && index < 10) return listeBoutons[index]; return nullptr; }
	Vector2f getTaille() { return taille; }
	Vector2f getPos() { return position; }
	void addBouton(Bouton* nBouton, int index) { if (index >= 0 && index < 10) listeBoutons[index] = nBouton; }
	void setTaille(Vector2f nTaille) { taille = nTaille; }

protected:

	String pathTextFond;					//Path vers la texture en fond du menu
	Texture textFond;						//Texture en fond du menu
	std::array<Bouton*, 10> listeBoutons;	//Liste des boutons du menu

	Vector2f position;						//Positiond du fond
	Vector2f taille;						//Taille du fond
};