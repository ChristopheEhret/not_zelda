#include "stdafx.h"
#include "Touche.h"

Touche::Touche() {

}

Touche::Touche(std::string n, int id, bool press , bool hold, bool release) {
	nom = n;
	this->id = id;

	pressed = press;
	held = hold;
	released = release;
}