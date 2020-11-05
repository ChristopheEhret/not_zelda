#include "stdafx.h"
#include "Plaque.h"

Plaque::Plaque() {
	pathTexture = String("Images/Objets/Plaque/Plaque.png");
	textObjet.loadFromFile("Images/Objets/Plaque/Plaque.png");

	description = "Bouton: Peut activer des objet si on positionne un poids dessus";
	
	taille = Vector2f(30, 30);

	niveauJoueur = false; 

	idType = 67;
}

Plaque::Plaque(Vector2f pos) {
	position = pos;

	pathTexture = String("Images/Objets/Plaque/Plaque.png");
	textObjet.loadFromFile("Images/Objets/Plaque/Plaque.png");

	description = "Le bouton peut activer des objet si on positionne un poids dessus";

	taille = Vector2f(30, 30);

	niveauJoueur = false;

	idType = 67;
}

void Plaque::tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime) {
	//Verifie si le joueur ou un cube est dessus
	bool active = false;

	for (int i = 0; i < listeEntitees->size(); i++){
		if (listeEntitees->at(i) != nullptr) {
			Entitee* e = listeEntitees->at(i);
			if (e->getPos().x + e->getSize().x > position.x && e->getPos().x < position.x + taille.x && e->getPos().y + e->getSize().y > position.y && e->getPos().y < position.y + taille.y)
				active = true;
		}
	}

	if(!active)
		for (int i = 0; i < listeObjets->size(); i++) {
			if (listeObjets->at(i) != nullptr) {
				if (typeid(Cube) == typeid(*listeObjets->at(i)))
					if (listeObjets->at(i)->getPos().x + listeObjets->at(i)->getSize().x > position.x && listeObjets->at(i)->getPos().x < position.x + taille.x && listeObjets->at(i)->getPos().y + listeObjets->at(i)->getSize().y > position.y && listeObjets->at(i)->getPos().y < position.y + taille.y)
						active = true;
			}
		}

	if(active)
		for (int i = 0; i < nbObjetsAActiver; i++) {
			if (listeObjetsAActiver[i] != nullptr)
				listeObjetsAActiver[i]->active();
		}
	

	if(old_Active != active)
		if(active)
			textObjet.loadFromFile("Images/Objets/Plaque/Plaque_Active.png");
		else 
			textObjet.loadFromFile("Images/Objets/Plaque/Plaque.png");

	old_Active = active;
}

bool Plaque::manageCollisionEntitee(Entitee * e)
{
	//Les entitees peuvent aller dessus
	return true;
}

bool Plaque::manageCollision(Vector2f pos, Vector2f size)
{

	return true;
}