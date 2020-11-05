#pragma once
#include "stdafx.h"

#define HAUT 0
#define DROITE 1
#define BAS 2
#define GAUCHE 3

using namespace sf;
class Entitee {

public:
	Entitee();

	void draw(RenderWindow* w);
	virtual void tick();
	
	//Accesseurs et mutateurs
	Vector2f getPos() { return position; }
	Vector2f getSize() { return taille; }
	void setPos(Vector2f nPos) { position = nPos; }
	void setSize(Vector2f nTaille) { taille = nTaille; }

	int getDirection() { return direction; }
	int getVitesseHaut() { return vitesseHaut; }
	int getVitesseDroite() { return vitesseDroite; }
	float getVitesse() { return vitesse; }
	void setDirection(int nDirection) { while (nDirection < HAUT) ++nDirection; while (nDirection > GAUCHE) --nDirection; direction = nDirection; }
	void setVitesseHaut(int nVitesseHaut) { vitesseHaut = nVitesseHaut; }
	void setVitesseDroite(int nVitesseDroite) { vitesseDroite = nVitesseDroite; }
	void setVitesse(int nVitesse) { vitesse = nVitesse; }

	virtual void save(std::ofstream* fluxSave);
	virtual void load(std::ifstream* fluxLoad);


protected:

	Vector2f position;					//Position dans la fenetre
	Vector2f taille;					//Taille de la collision de l'entitée

	float vitesse = 4.f;				//Vitesse de l'entitée
	int vitesseHaut = 0;				//Négatif si le joueur doit aller en bas, positif pour en haut
	int vitesseDroite = 0;				//Négatif si le joueur doit aller à gauche, positif pour à droite

	String pathFichierTextures = "Images/Entitees/Null/null_"; //Début de chaque images qui constituent l'animation de l'entitée
	
	bool marche = false;				//True si l'animation de l'entitée est sur phase marche
	int compteurTicksMarche = 0;		//Compteur de tick de l'animation
	int maxTicksMarche = 20;			//Nombre de ticks avant de passer l'animation sur la phase marche
	
	int direction = BAS;				//Direction vers laquelle l'entitée fait face

	char idType = 97;					//De 97 à 117 (97 = Type invalide)
										//Id de chaque classe d'entitées (Utilisé pour la sauvegarde de l'objet)
};