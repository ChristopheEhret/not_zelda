#include "stdafx.h"
#include "Salle.h"
#include "Joueur.h"
#include "MainMenu.h"
#include "MenuEditeur.h"
#pragma once

using namespace sf;
class Fenetre {

public:
	Fenetre();

	void initialisation();

	void tick();
	void draw();

	void manage();				//Fonction principale qui tourne en boucle
	void manageJoueur();		//Fonction qui actualise la pos du joueur et gere les collision

	void resetMenu();			//Reset lorsqu'on revient sur le menu principal 

	void manageEditeur();
	void drawEditeur(RenderWindow* w); //Fonction qui d�ssine les pr�visualisations eventuelles due � l'utilisation de l'editeur

	//Accesseurs
	RenderWindow* getWindow() { return window; }
	bool isFini() { return fin; }

protected:

	Clock timer;
	double time;					//temps pass� en ms
	double memTime = 0;			//temps pass� � la derni�re frame
	double deltaTime = 0;		//temps pass� entre la derni�re frame

	RenderWindow* window;		//Fenetre principale
	Salle salle;				//Salle 
	Clavier clavier;			//Clavier qui manage

	MainMenu menu;				//Menu principal
	MenuEditeur menuEditeur;	//Menu �diteur
	Font police;

	bool fin = false;			//True si la fenetre est ferm�e

	//Touches utiles
	Touche avant = Touche("Z", Keyboard::Z);
	Touche arriere = Touche("S", Keyboard::S);
	Touche gauche = Touche("Q", Keyboard::Q);
	Touche droite = Touche("D", Keyboard::D);
	Touche espace = Touche(" ", Keyboard::Space);
	Touche rotationEditeurDroite = Touche("E", Keyboard::E);
	Touche rotationEditeurGauche = Touche("A", Keyboard::A);

	//LMB = Left Mouse Button, Etat � la derniere frame
	bool LMBUtiliseDerniereFrame = false; 
	//RMB = Right Mouse Button, Etat � la derni�re frame
	bool RMBUtiliseDerniereFrame = false; 

	bool editeurConnecte = false;		//True si l'utilisateur veut connecter deux objets
	ObjetActivant* objetAConnecter;		//Objet � connecter quand 'editeurConnecte' est true
	Vector2f oldPosSourisEditeur;		//Position du tile survol� par la souris dans l'editeur 
	int rotationObjetEditeur = HAUT;	//Rotation de l'objet entrain d'etre plac�

	int oldGamemode = GAMEMODE_MENU;	//Gamemode du menu � la derni�re frame	
};