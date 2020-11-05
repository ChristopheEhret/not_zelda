#include "stdafx.h"
#include "Menu.h"

Menu::Menu(String pathFond) {
	position = Vector2f(0, 0);
	taille = Vector2f(0, 0);

	if (pathFond != "null")
		textFond.loadFromFile(pathFond);

	listeBoutons.fill(nullptr); //Remplit la liste avec des nullptr
}

Menu::Menu(Vector2f pos, Vector2f size, String pathFond) {
	position = pos;
	taille = size;

	if (pathFond != "null")
		textFond.loadFromFile(pathFond);

	listeBoutons.fill(nullptr); //Remplit la liste avec des nullptr
}

void Menu::draw(RenderWindow* w) {

	Sprite fond = Sprite(textFond);

	//Met le fond à la taille de la fenetre
	if (taille == Vector2f(0, 0)) {
		if (fond.getTexture() != nullptr && fond.getTexture()->getSize() != Vector2u(0, 0)) {
			fond.setScale(w->getSize().x / fond.getTexture()->getSize().x, w->getSize().y / fond.getTexture()->getSize().y);
		}
	}
	else {
		if (fond.getTexture() != nullptr && fond.getTexture()->getSize() != Vector2u(0, 0)) {
			fond.setScale(taille.x / fond.getTexture()->getSize().x, taille.y / fond.getTexture()->getSize().y);
		}
	}

	fond.setPosition(position);
	w->draw(fond);
	
	//Puis draw les boutons
	for (int i = 0; i < listeBoutons.size(); i++) {
		if(listeBoutons[i] != nullptr)
			listeBoutons[i]->draw(w);
	}
}

void Menu::tick(RenderWindow* w) {
	for (int i = 0; i < listeBoutons.size(); i++) {
		if(listeBoutons[i] != nullptr)
			if (listeBoutons[i]->isActif()) {
				Vector2f posReelleBouton(w->getPosition().x + 9 + listeBoutons[i]->getPos().x, w->getPosition().y + 39 + listeBoutons[i]->getPos().y); //On ajoute 9 en X et 39 en Y à cause du décalage

				//Verifie si l'ulisateur interagit avec un des boutons
				if (Mouse::getPosition().x >= posReelleBouton.x && Mouse::getPosition().x < posReelleBouton.x + listeBoutons[i]->getSize().x && Mouse::getPosition().y >= posReelleBouton.y && Mouse::getPosition().y < posReelleBouton.y + listeBoutons[i]->getSize().y) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						listeBoutons[i]->setClique(true);
						listeBoutons[i]->setSurvole(false);
						listeBoutons[i]->setRelache(false);
					}
					else {
						listeBoutons[i]->setSurvole(true);
						listeBoutons[i]->setRelache(listeBoutons[i]->getClique());
						listeBoutons[i]->setClique(false);
					}
				}
				else {
					listeBoutons[i]->setClique(false);
					listeBoutons[i]->setSurvole(false);
					listeBoutons[i]->setRelache(false);
				}
			}
	}
}