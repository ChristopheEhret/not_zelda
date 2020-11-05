#pragma once
#include "Carte.h"
#include "InculdeObjets.h"
#include "IncludeEntitees.h"

using namespace sf;
class Salle {

public:
	Salle();

	Carte carte;

	void draw(RenderWindow* w);
	void tick(int deltaTime);

	void tick(Objet* objetATick, int deltaTime); //Tick un objet en particulier

	bool manageCollisionEntitee(Entitee* e);
	bool manageCollision(Vector2f pos, Vector2f size);

	//Accesseurs et mutateurs
	Objet* getObjet(int index) { if (index >= 0 && index < 400) return listeObjets[index]; return nullptr; }
	Objet* getObjet(int posX, int posY);
	int getIndexObjet(Objet* o);
	void addObjet(Objet* nObjet);
	bool removeObjet(int posX, int posY);	//Enlève l'objet à la positionsaud si c'est la sortie; retourne false si c'est la sortie
	
	Entitee* getEntitee(int index) { if (index >= 0 && index < 30) return listeEntitees[index]; return nullptr; }
	Entitee* getEntitee(int posX, int posY);
	void addEntitee(Entitee* nEntitee);
	void removeEntitee(int posX, int posY);

	Joueur* joueur;
	Sortie* sortie;

//Fonctions de sauvegarde et de chargement de la salle
	void save(std::ofstream* fluxSave);
	void load(std::ifstream* fluxLoad);

//Fonction de reset de la salle
	void reset();

protected:

	std::array<Objet*, 400> listeObjets;		//liste des objets dans la salle, avant le jeu
	int nbObjets = 0;							//nb d'objets dans la liste

	std::array<Entitee*, 30> listeEntitees;		//liste des entitées présentes dans la salle
	int nbEntitees = 1;							//nb d'entitées dans la liste

};