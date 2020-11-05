#include "stdafx.h"
#include "MenuEditeur.h"

using namespace sf;
MenuEditeur::MenuEditeur() {

	//Constructeur a ne pas utiliser
	actif = false;
}

MenuEditeur::MenuEditeur(Carte* c) {
	carte = c;
	police.loadFromFile("Font/police.ttf");


	initListeObjets();

	objetSlot2 =  new Cube();
	objetChoisi = nullptr;

	initMenus();

	//Load de la texture pour la preview
	textureItemChoisi.loadFromFile(carte->getTile(idTileChoisi)->texturePath);

	actif = true;
}

void MenuEditeur::initMenus() {
	//Initialisation du menuEditeur
	boutonExtendChoix = new Bouton(Vector2f(0, 672), Vector2f(32, 32), Color::Black, "", "Images/Menus/Editeur/BoutonLeve.png", "Images/Menus/Editeur/BoutonLeve_Appuie.png");
	listeBoutons[0] = boutonExtendChoix;
	boutonSlot1 = new Bouton(Vector2f(32, 672), Vector2f(32, 32), Color::White, "", carte->getTile(idTileSlot1)->texturePath);
	listeBoutons[1] = boutonSlot1;
	boutonSlot2 = new Bouton(Vector2f(64, 672), Vector2f(32, 32), Color::White, "", objetSlot2->getPathTexture());
	listeBoutons[2] = boutonSlot2;

	//Initialisation de la barreSlot1
	barreSlot1 = Menu();
	for (int i = 0; i < 3; i++) {
		Bouton* b = new Bouton(Vector2f(32, 640 - i * 32), Vector2f(32, 32), Color::Black, "", carte->getTile(i)->texturePath);
		barreSlot1.addBouton(b, i);
	}

	//Initialisation de la barreSlot2
	barreSlot2 = Menu();
	for (int i = 0; i < listeObjetsBarreSlot2.size(); i++) {
		Bouton* b = new Bouton(Vector2f(64, 640 - i * 32), Vector2f(32, 32), Color::Black, "", listeObjetsBarreSlot2[i]->getPathTexture());
		barreSlot2.addBouton(b, i);
	}
}

void MenuEditeur::initListeObjets() {
	listeObjetsBarreSlot2[0] = new Cube();
	listeObjetsBarreSlot2[1] = new Plaque();
	listeObjetsBarreSlot2[2] = new Lumiere();
	listeObjetsBarreSlot2[3] = new ObstacleActivable();
	listeObjetsBarreSlot2[4] = new Piston();
	listeObjetsBarreSlot2[5] = new SensUnique();
	listeObjetsBarreSlot2[6] = new Sortie();
	listeObjetsBarreSlot2[7] = new Effaceur();
}

void MenuEditeur::tick(RenderWindow* w) {
	if (actif) {
		Menu::tick(w);
		
		if (extendChoix) { //Si l'utilisateur est entrain de choisir 
			barreSlot1.tick(w);
			barreSlot2.tick(w);

			bool utiliseMenuChoix = false;	//true si l'utilisateur clique sur l'un des choix

			for (int i = 0; i < 3; i++) {	//Verifie si l'utilisateur choisi dans 'barreSlot1'
				if (barreSlot1.getBouton(i)->getRelache()) {
					idTileSlot1 = i;	

					boutonSlot1->~Bouton();			//Destruction du bouton slot1
					Bouton* b = new Bouton(Vector2f(32, 672), Vector2f(32, 32), Color::White, "", carte->getTile(idTileSlot1)->texturePath);
					boutonSlot1 = b;				//Pour en construire un autre avec la bonne texture
					listeBoutons[1] = boutonSlot1;

					idTileChoisi = idTileSlot1;		//Et on selectionne le Tile choisi
					objetChoisi = nullptr;
					textureItemChoisi.loadFromFile(carte->getTile(idTileChoisi)->texturePath);
				}

				if (barreSlot1.getBouton(i)->getClique())	//Vérifie si on utilise le menu
					utiliseMenuChoix = true;
			}

			for (int i = 0; i < listeObjetsBarreSlot2.size(); i++) { //Verifie si l'utilisateur choisi dans 'barreSlot2'
				if (barreSlot2.getBouton(i)->getRelache()) {
					objetSlot2 = listeObjetsBarreSlot2[i];

					boutonSlot2->~Bouton();			//Meme principe qu'au dessus
					Bouton* b = new Bouton(Vector2f(64, 672), Vector2f(32, 32), Color::White, "", objetSlot2->getPathTexture());
					boutonSlot2 = b;
					listeBoutons[2] = boutonSlot2;

					objetChoisi = objetSlot2;
					idTileChoisi = -1;
					textureItemChoisi.loadFromFile(objetChoisi->getPathTexture());
				}

				if (barreSlot2.getBouton(i)->getClique())	//Verifie si on utilise le menu
					utiliseMenuChoix = true;
			}

			if (boutonExtendChoix->getRelache())
				extendChoix = false;

			if (boutonExtendChoix->getClique())	//Chiant a expliquer mais necessaire pour fermer le menu
				utiliseMenuChoix = true;

			//Si on clique sans "utiliser le menu", on le ferme
			if ((Mouse::isButtonPressed(Mouse::Left) || Mouse::isButtonPressed(Mouse::Right)) && !utiliseMenuChoix) //Si l'utilisateur clique qqpart mais n'utilise pas le menu, alors on ferme le menu
				extendChoix = false;

		}
		else {
			if (boutonExtendChoix->getRelache())
				extendChoix = true;

			if (boutonSlot1->getRelache()) {	//Si l'utilisateur choisi le slot1
				idTileChoisi = idTileSlot1;		//Actualise les variable
				objetChoisi = nullptr;

				//Actualise la texture de preview
				textureItemChoisi.loadFromFile(carte->getTile(idTileChoisi)->texturePath);
			}

			if (boutonSlot2->getRelache()) {	//Si l'utilisateur choisi le slot2
				objetChoisi = objetSlot2;		//Meme principe qu'au dessus
				idTileChoisi = -1;

				textureItemChoisi.loadFromFile(objetChoisi->getPathTexture());
			}
		}
	}
}

void MenuEditeur::draw(RenderWindow* w) {
	if (actif) {
		Menu::draw(w);	//Draw classique du menuEditeur

		Sprite itemChoisi = Sprite(textureItemChoisi);	//Affiche la texture de preview
		itemChoisi.move(Vector2f(608, 672));
		w->draw(itemChoisi);

		if (extendChoix) {
			barreSlot1.draw(w);	//Draw du menu de choix
			barreSlot2.draw(w);

			for (int i = 0; i < listeObjetsBarreSlot2.size(); i++) {
				if (barreSlot2.getBouton(i)->getSurvole()) { //Si on survole un des objet
					String infos = listeObjetsBarreSlot2[i]->getDescription(); //On ecrit une descriptions
					
					Text texteInfos(infos, police, 15);
					
					if (texteInfos.getLocalBounds().width >= 500) {	//Si la decription est trop grande
						infos.insert(infos.getSize() / 2, "\n");	//On va à la ligne
						texteInfos = Text(infos, police, 15);
					}

					texteInfos.setFillColor(Color::White);
					texteInfos.move(320 - (texteInfos.getLocalBounds().width / 2), 16 - (texteInfos.getLocalBounds().height / 2));

					w->draw(texteInfos);

				}
			}
		}
	}
}