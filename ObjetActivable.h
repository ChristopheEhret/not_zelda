#pragma once
#include "Objet.h"

class ObjetActivable : public Objet {
public: 
	
	ObjetActivable();
	ObjetActivable(Vector2f pos);

	virtual void tick(Carte* c, std::array<Entitee*, 30>* listeEntitees, std::array<Objet*, 400>* listeObjets, int deltaTime) override;

	virtual void toggleActif();						//Change si l'objet est actif
	
	//Accesseurs et mutateurs
	void setActifBase(bool nActifBase) { actif_base = nActifBase; actif = actif_base; }
	void toggleActifBase() { actif_base = !actif_base; actif = actif_base; }
	virtual void active() { actif = !actif_base; }
	bool isActif() { return actif; }

	virtual void save(std::ofstream* fluxSave) override;
	virtual void load(std::ifstream* fluxLoad) override;

protected:
	bool actif_base = false;	//Bool qui definit l'etat de base de l'objet
	bool actif = false;			//True si l'objet a été activé
	bool old_actif = false;		//Etat de l'objet à la dernière frame
};