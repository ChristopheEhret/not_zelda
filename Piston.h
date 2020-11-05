#pragma once
#include "stdafx.h"
#include "ObjetActivable.h"

#define PISTON_REPOS 0
#define PISTON_INTERMEDIARE 1
#define PISTON_ETENDU 2

class Piston : public ObjetActivable {
public: 

	Piston();
	Piston(Vector2f pos);

	virtual void tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime) override;
	virtual void draw(RenderWindow* w) override;

	virtual bool manageCollisionEntitee(Entitee* e) override;
	virtual bool manageCollision(Vector2f pos, Vector2f size) override;

private:
	char etatPiston = PISTON_REPOS;		//Etat du piston
	char oldEtatPiston = PISTON_REPOS;	//Etat du piston � la derni�re frame
	int tempsAnimation = 160;			//Temps en ms entre deux etat
	int timerAnimation = 0;				//Compteur du temps depuis le dernier �tat

	bool bloque = false;				//True si qqchose bloque le piston

	Vector2f posTetePiston;				//Position de la t�te du piston, selon la rotation
	Vector2f tailleTetePiston;			//Taille de la t�te selon l'etat du piston
	Texture textTetePiston;				//Texture de la t�te du piston, selon l'etat du piston
};