#pragma once
#include "stdafx.h"
#include "Menu.h"

#define GAMEMODE_MENU 0
#define GAMEMODE_JEU 1
#define GAMEMODE_EDITEUR 2

using namespace sf;
class MainMenu {
public:

	MainMenu();

	void tick(RenderWindow* w);
	void draw(RenderWindow* w);

	void retourneMenuPrincipal() { gamemode = GAMEMODE_MENU; }
	int getGamemode() { return gamemode; } //Accesseur versle gamemode

protected:

	Menu menuAcceuil;				//Menu de l'acceuil
	Menu menuJeu;					//Menu du jeu
	Menu menuEditeur;				//Menu de l'editeur

	Bouton* boutonJeu;				//Bouton permettant d'acceder au menuJeu
	Bouton* boutonEditeur;			//Bouton permettant d'acceder au menuAcceuil
	Bouton* boutonMenu;				//Bouton permettant d'acceder au menuEditeur

	int gamemode = GAMEMODE_MENU;	//Gamemode, càd quel menu est actif à present
};