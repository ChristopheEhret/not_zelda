#pragma once
#include "stdafx.h"
#include "ObjetActivable.h"

class ObstacleActivable : public ObjetActivable {
public:

	ObstacleActivable();
	ObstacleActivable(Vector2f pos);

	virtual void tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime) override;

	virtual bool manageCollisionEntitee(Entitee* e) override;
};