#pragma once
#include "stdafx.h"
#include "Objet.h"

using namespace sf;
class Sortie : public Objet{
public: 

	Sortie();
	Sortie(Vector2f pos);

	virtual bool manageCollisionEntitee(Entitee* e) override;

	bool getFin() { return fin; }

protected:

	bool fin = false;
};