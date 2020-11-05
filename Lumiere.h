#pragma once
#include "stdafx.h"
#include "ObjetActivable.h"

using namespace sf;
class Lumiere : public ObjetActivable {
public:
	
	Lumiere();
	Lumiere(Vector2f pos);

	virtual void tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime) override;
};