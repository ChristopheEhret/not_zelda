#pragma once
#include "stdafx.h"
#include "ObjetActivant.h"
#include "Cube.h"

class Plaque : public ObjetActivant {
public:

	Plaque();
	Plaque(Vector2f pos);

	virtual void tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime) override;
	virtual bool manageCollisionEntitee(Entitee* e) override;
	virtual bool manageCollision(Vector2f pos, Vector2f size) override;


protected:
	bool old_Active = false;	//Etat de la plaque dans la derniere frame

};