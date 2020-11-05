#include "stdafx.h"
#include "Bouton.h"

using namespace sf;
Bouton::Bouton() {
	position = Vector2f(0, 0);
	size = Vector2f(0, 0);
	phraseContenu = " ";
	couleurTexte = Color::Black;
}

Bouton::Bouton(Vector2f pos, Vector2f taille, Color couleur, String contenu, String pathImageFond, String pathImageClique, String pathImageSurvole) {
	position = pos;
	size = taille;
	phraseContenu = contenu;

	couleurTexte = couleur;

	if(pathImageFond != "null")
		textFond.loadFromFile(pathImageFond);
	

	if (pathImageClique != "null")
		textClique.loadFromFile(pathImageClique);
	else
		textClique = textFond;

	if (pathImageSurvole != "null")
		textSurvole.loadFromFile(pathImageSurvole);
	else
		textSurvole = textFond;

	police.loadFromFile("Font/police.ttf");

	actif = true;
}

void Bouton::draw(RenderWindow* w) {
	if (actif) {		
		//Crée et place le texte au bon endroit
		Text contenu = Text(phraseContenu,  police);
		contenu.setCharacterSize(taillePolice);
		contenu.setFillColor(couleurTexte);
		contenu.move(position.x + (size.x / 2) - (contenu.getLocalBounds().width / 2), position.y + (size.y / 2) - (contenu.getLocalBounds().height));

		//Choisi la texture en fonction de l'etat du bouton
		Sprite spriteBouton;
		if (clique)
			spriteBouton = Sprite(textClique);
		else if (survole)
			spriteBouton = Sprite(textSurvole);
		else
			spriteBouton = Sprite(textFond);

		if (spriteBouton.getTexture() != nullptr) {
			spriteBouton.move(position);
			spriteBouton.setScale(size.x / spriteBouton.getTexture()->getSize().x, size.y / spriteBouton.getTexture()->getSize().y);
			w->draw(spriteBouton);

		}

		if(police.getInfo().family != "")
			w->draw(contenu);
	}
}