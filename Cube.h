#pragma once
#include "Objet.h"

using namespace sf;
class Cube : public Objet {
public:

	Cube();
	Cube(Vector2f pos);

	virtual void tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime) override;

	virtual bool manageCollisionEntitee(Entitee* e) override;

protected:
	int vitesseHaut = 0;	//Vitesse car le cube peut bouger
	int vitesseDroite = 0;

	float vitesse = 3.f;

};