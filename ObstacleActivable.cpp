#include "stdafx.h"
#include "ObstacleActivable.h"

using namespace sf;

ObstacleActivable::ObstacleActivable() {
	pathTexture = "Images/Objets/Obstacle_Activable/Obstacle_Activable.png";
	textObjet.loadFromFile(pathTexture);

	description = "Obstacle Activable : Objet activable, bloque le passage ou non selon son état";
	taille = Vector2f(32, 32);

	niveauJoueur = true;

	idType = 69;
}

ObstacleActivable::ObstacleActivable(Vector2f pos) {
	position = pos;

	pathTexture = "Images/Objets/Obstacle_Activable/Obstacle_Activable.png";
	textObjet.loadFromFile(pathTexture);

	description = "Obstacle Activable : Objet activable, bloque le passage ou non selon son état";
	taille = Vector2f(32, 32);

	niveauJoueur = true;

	idType = 69;
}

void ObstacleActivable::tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime) {

	//Change la texture de la lumiere lorsqu'elle est activée
	if (old_actif != actif)
		if (actif) {

			//Si l'obstacle est baissé, il n'est pas au niveau du joueur
			textObjet.loadFromFile("Images/Objets/Obstacle_Activable/Obstacle_Activable_Bas.png");
			niveauJoueur = false;
		}
		else {

			//Verifie si rien n'est sur l'obstacle avant de se ferme
			for (int i = 0; i < listeEntitees->size(); i++) {
				if (listeEntitees->at(i) != nullptr) {
					Entitee* e = listeEntitees->at(i);
					if (e->getPos().x + e->getSize().x > position.x && e->getPos().x < position.x + taille.x && e->getPos().y + e->getSize().y > position.y && e->getPos().y < position.y + taille.y)
						actif = true;
				}
			}

			if (!actif)
				for (int i = 0; i < listeObjets->size(); i++) {
					if (listeObjets->at(i) != nullptr && listeObjets->at(i) != this) {
						Objet* o = listeObjets->at(i);
						if (o->getPos().x + o->getSize().x > position.x && o->getPos().x < position.x + taille.x && o->getPos().y + o->getSize().y > position.y && o->getPos().y < position.y + taille.y)
							actif = true;
					}
				}

			//Si l'obstacle est levé, il est au niveau du joueur
			if (!actif) {
				textObjet.loadFromFile("Images/Objets/Obstacle_Activable/Obstacle_Activable.png");
				niveauJoueur = true;
			}
		}

	ObjetActivable::tick(c, listeEntitees, listeObjets, deltaTime);
}

bool ObstacleActivable::manageCollisionEntitee(Entitee* e) {

	if (e->getPos().x + e->getSize().x > position.x && e->getPos().x < position.x + taille.x && e->getPos().y + e->getSize().y > position.y && e->getPos().y < position.y + taille.y)
		return false;

	return true;
}