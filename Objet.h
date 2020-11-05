#pragma once
#include "stdafx.h"
#include "Joueur.h"
#include "Carte.h"

using namespace sf;
class Objet {
public:

	Objet();
	Objet(Vector2f pos);

	virtual void draw(RenderWindow* w);
	virtual void tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime);

	//Retourne false si l'entitée doit etre bloquée
	virtual bool manageCollisionEntitee(Entitee* e);
	virtual bool manageCollision(Vector2f pos, Vector2f size);
	
	//Accesseurs et mutateurs
	Vector2f getPos() { return position; }
	Vector2f getSize() { return taille; }
	void setPos(Vector2f nPos) { position = nPos; }
	void setSize(Vector2f nSize) { taille = nSize; }

	bool isNiveauJoueur() { return niveauJoueur; }
	int getRotation() { return rotation; }
	void setNiveauJoueur(bool nNiveauJoueur) { niveauJoueur = nNiveauJoueur; }
	void setRotation(int nRotation) { while (nRotation > 3) --nRotation; while (nRotation < 0) ++nRotation; rotation = nRotation; }
	void addRotation() { ++rotation; if (rotation > DROITE) rotation = HAUT; }
	void minRotation() { --rotation; if (rotation < HAUT) rotation = GAUCHE; }

	String getPathTexture() { return pathTexture; }
	String getDescription() { return description; }

//Fonction de sauvegarde et de chargement de l'objet
	virtual void save(std::ofstream* fluxSave);
	virtual void load(std::ifstream* fluxLoad);

protected:

	Vector2f position;			//Position dans la fenetre
	Vector2f taille;			//Taille de la collision de l'objet

	Texture textObjet;			//Texture de l'objet

	bool niveauJoueur = true;	//True si l'objet peut entrer en collision avec le joueur (et les entitées)
	int rotation = 0;			//Rotation de l'objet (entre 0 et 3)

	String pathTexture = "null";				//Chemin vers la texture de l'objet
	String description = "Unexpected object";	//Description de l'objet

	char idType = 65;							//De 65 à 95 (65 = Objet invalide)
												//Id de chaque classe d'objet (Utilisé pour la sauvegarde de l'objet)
};