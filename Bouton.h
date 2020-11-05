#pragma once
#include "stdafx.h"

using namespace sf;
class Bouton {
public:

	Bouton();

	Bouton(Vector2f pos, Vector2f taille, Color couleur = Color::Black, String contenu = " ", String pathImageFond = "null", String pathImageAppuye = "null", String pathImageSurvole = "null");

	void draw(RenderWindow* w);

	//Accesseurs et mutateurs
	Vector2f getPos() { return position; }
	Vector2f getSize() { return size; }
	void setPos(Vector2f nPos) { position = nPos; }
	void setSize(Vector2f nSize) { size = nSize; }
	void setTaillePolice(int nTaillePolice) { taillePolice = nTaillePolice; }

	bool getSurvole() { return survole; }
	bool getClique() { return clique; }
	bool getRelache() { return relache; }
	bool isActif() { return actif; }
	void setSurvole(bool nSurvole) { survole = nSurvole; }
	void setClique(bool nClique) { clique = nClique; }
	void setRelache(bool nRelache) { relache = nRelache; }
	void setActif(bool nActif) { actif = nActif; }

protected:

	Vector2f position;			//Position dans la fenetre
	Vector2f size;				//Taille du bouton
	Color couleurTexte;			//Couleur du texte
	String phraseContenu;		//Phrase affichée dans le bouton
	Texture textFond;			//Texture du bouton normal
	Texture textClique;			//Texture du bouton suvolé par la souris
	Texture textSurvole;		//Texture du bouton quand on clique dessus
	
	bool survole = false;		//True si le curseur est au dessus du bouton
	bool clique = false;		//True si l'utilisateur clique sur le bouton
	bool relache = false;
	bool actif = false;			//True si le bouton est actif et a été bien déclaré

	Font police;				//Police du texte
	int taillePolice = 20;		//Taille du texte

};