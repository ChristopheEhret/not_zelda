#pragma once
#include "stdafx.h"
#include "Objet.h"

//Objet uniquement destiné à l'éditeur, pour indiquer que l'on veut effacer un aurte objet
class Effaceur : public Objet {
public:
	Effaceur();
	Effaceur(Vector2f pos);
};