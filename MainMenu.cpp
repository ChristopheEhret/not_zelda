#include "stdafx.h"
#include "MainMenu.h"

using namespace sf;
MainMenu::MainMenu() {
	//Configure les menus
	menuAcceuil = Menu("Images/Tiles/Vide.png");
	menuJeu = Menu();
	menuEditeur = Menu("Images/Menus/Editeur/Fond.png");

	//Initialisaton des menus
	Bouton* b1 = new Bouton(Vector2f(100, 120), Vector2f(440, 1), Color::White, "Nouveau jeu super bien");
	b1->setTaillePolice(40);
	menuAcceuil.addBouton(b1, 0);

	boutonJeu = new Bouton(Vector2f(100, 400), Vector2f(440, 50), Color::Black, "Jouer au nouveau jeu super bien", "Images/Bouton/Fond.png", "Images/Bouton/Appuie.png", "Images/Bouton/Survole.png");
	menuAcceuil.addBouton(boutonJeu, 1);

	boutonEditeur = new Bouton(Vector2f(100, 500), Vector2f(440, 50), Color::Black, "Editeur", "Images/Bouton/Fond.png", "Images/Bouton/Appuie.png", "Images/Bouton/Survole.png");
	menuAcceuil.addBouton(boutonEditeur, 2);

	boutonMenu = new Bouton(Vector2f(0, 0), Vector2f(64, 32), Color::Black, "Menu", "Images/Bouton/Fond.png", "Images/Bouton/Appuie.png", "Images/Bouton/Survole.png");
	menuJeu.addBouton(boutonMenu, 0);

	Bouton* b2 = new Bouton(Vector2f(512, 0), Vector2f(128, 32), Color::White, "Jeu Super", "Images/Tiles/Vide.png");
	menuJeu.addBouton(b2, 1);

	menuEditeur.addBouton(boutonMenu, 0);

	Bouton* b3 = new Bouton(Vector2f(512, 0), Vector2f(128, 32), Color::White, "Editeur", "Images/Tiles/Vide.png");
	menuEditeur.addBouton(b3, 1);

}

void MainMenu::tick(RenderWindow* w) {
	//Tick le menu actif
	if (gamemode == GAMEMODE_MENU) {
		menuAcceuil.tick(w);
		if (boutonJeu->getRelache()) 
			gamemode = GAMEMODE_JEU;
		if (boutonEditeur->getRelache())
			gamemode = GAMEMODE_EDITEUR;
	}
	else if (gamemode == GAMEMODE_JEU) {
		menuJeu.tick(w);
		if (boutonMenu->getRelache())
			gamemode = GAMEMODE_MENU;
	}
	else if (gamemode == GAMEMODE_EDITEUR) {
		menuEditeur.tick(w);
		if (boutonMenu->getRelache())
			gamemode = GAMEMODE_MENU;
	}
}

void MainMenu::draw(RenderWindow* w) {
	//Draw le menu actif
	if (gamemode == GAMEMODE_MENU)
		menuAcceuil.draw(w);
	else if (gamemode == GAMEMODE_JEU)
		menuJeu.draw(w);
	else if (gamemode == GAMEMODE_EDITEUR)
		menuEditeur.draw(w);
}