#pragma once
#include "stdafx.h"
#include "Menu.h"
#include "Carte.h"
#include "InculdeObjets.h"

using namespace sf;
class MenuEditeur : public Menu {
public:

	//NE PAS UTILISER LE CONSTRUCTEUR SANS ARGUMENT
	MenuEditeur();
	//Utiliser celui-ci plutot
	MenuEditeur(Carte* c);

	virtual void tick(RenderWindow* w) override;
	virtual void draw(RenderWindow* w) override;

	//Fonctions d'initialisation
	void initListeObjets();
	void initMenus();

	//Accesseurs
	std::array<Objet*, 8> getListeObjetsBarreSolt2() { return listeObjetsBarreSlot2; }
	Objet* getObjetChoisi() { return objetChoisi; }
	bool isExtendChoix() { return extendChoix; }
	int getTileChoisi() { return idTileChoisi; }

protected:

	Carte* carte;		//Carte afin d'avoir les différents Tiles dispos
	Menu barreSlot1;	//Menu permettant de changer l'item du slot1
	Menu barreSlot2;	//Menu permettant de changer l'item du slot2

	bool actif = false; //Permet de savoir si le menu a bien construit de la bonne façon

	std::array<Objet*, 8> listeObjetsBarreSlot2;	//Liste des objets dispos dans la barre du slot2

	int idTileChoisi = 0;		//Egal à -1 si un objet est selectionné
	Objet* objetChoisi;			//nullptr si un tile est selectionné

	int idTileSlot1 = 0;		//Tile choisi dans le slot1
	Objet* objetSlot2;			//Objet choisi dans le slot2
	bool extendChoix = false;	//Controle l'affichange des 'barreSlot'

	Bouton* boutonExtendChoix;	//Bouton qui permet d'afficher les 'barreslot'
	Bouton* boutonSlot1;		//Bouton permettant de choisir l'item en slot1
	Bouton* boutonSlot2;		//Bouton permettant de choisir l'item en slot2

	Texture textureItemChoisi;	//Texture de l'item choisi, afin de pouvoir montrer quel item est choisi
	Font police;
};