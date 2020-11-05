#pragma once
#include "stdafx.h"
#include "Objet.h"

using namespace sf;
class SensUnique : public Objet {
public:

	SensUnique();
	SensUnique(Vector2f pos);

	virtual bool manageCollisionEntitee(Entitee* e) override;
	virtual bool manageCollision(Vector2f pos, Vector2f size) override;
};