#include "stdafx.h"
#include "Lumiere.h"

using namespace sf;
Lumiere::Lumiere() {
	pathTexture = "Images/Objets/Lumiere/Lumiere_Eteinte.png";
	textObjet.loadFromFile(pathTexture);

	description = "Lumiere : Objet activable qui s'allume";
	
	taille = Vector2f(32, 32);

	niveauJoueur = true;

	idType = 70;
}

Lumiere::Lumiere(Vector2f pos) {
	position = pos;

	pathTexture = "Images/Objets/Lumiere/Lumiere_Eteinte.png";
	textObjet.loadFromFile(pathTexture);
	
	description = "Lumiere : Objet activable qui s'allume";

	taille = Vector2f(32, 32);

	niveauJoueur = true;

	idType = 70;
}

void Lumiere::tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime) {

	//Change la texture de la lumiere lorsqu'elle est activée
	if(old_actif != actif)
		if (actif)
			textObjet.loadFromFile("Images/Objets/Lumiere/Lumiere_Allumee.png");
		else 
			textObjet.loadFromFile("Images/Objets/Lumiere/Lumiere_Eteinte.png");

	ObjetActivable::tick(c, listeEntitees, listeObjets, deltaTime);
}