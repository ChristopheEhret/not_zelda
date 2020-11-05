#include "stdafx.h"
#include "Salle.h"

using namespace sf;
Salle::Salle() {
	joueur = nullptr;
	sortie = nullptr;

	reset();
}

void Salle::draw(RenderWindow* w) {
	//Draw d'abord la carte
	carte.draw(w);

	//Puis les objets au niveau du sol
	for (int i = 0; i < nbObjets; i++) {
		if (listeObjets[i] != nullptr)
			if (!listeObjets[i]->isNiveauJoueur())
				listeObjets[i]->draw(w);
	}

	//Puis les objets au niveau du joueur
	for (int i = 0; i < nbObjets; i++) {
		if (listeObjets[i] != nullptr)
			if (listeObjets[i]->isNiveauJoueur())
				listeObjets[i]->draw(w);
	}

	//Puis les entitées
	for (int i = 0; i < nbEntitees; i++) {
		if (listeEntitees[i] != nullptr)
			listeEntitees[i]->draw(w);
	}
}

void Salle::tick(int deltaTime) {
	for (int i = 0; i < nbObjets; i++) {
		if (listeObjets[i] != nullptr)
			listeObjets[i]->tick(&carte, &listeEntitees, &listeObjets, deltaTime);
	}

	for (int i = 0; i < nbEntitees; i++) {
		if (listeEntitees[i] != nullptr) {
			Entitee* entiteeTick = listeEntitees[i];
			entiteeTick->tick();

			if (entiteeTick->getVitesseDroite() != 0 || entiteeTick->getVitesseHaut() != 0) {
				float deplacement = 0.f;
				//Bouge le joueur et verifie les collision
				if (entiteeTick->getVitesseDroite() != 0 && entiteeTick->getVitesseHaut() != 0) {
					//Si le joueur bouge en diagonales, on reduit les vitesses individuelles afin de faire un vitesse globale equivalente 
					deplacement = sqrt(pow(((entiteeTick->getVitesse() * deltaTime) / 16), 2.f) / 2);
				}
				else {
					deplacement = (entiteeTick->getVitesse() * deltaTime) / 16;
				}

				float deplacementDroite = deplacement;
				float deplacementHaut = deplacement;

				Vector2f newPosEntitee = entiteeTick->getPos();

				//Bouge l'entitée en verifiant les collisions pixel par pixel
				while (deplacementDroite > 0) {

					if (deplacementDroite >= 1) {
						newPosEntitee.x += entiteeTick->getVitesseDroite();
						entiteeTick->setPos(newPosEntitee);
						deplacementDroite--;
						if (!manageCollisionEntitee(entiteeTick) || entiteeTick->getPos().x < carte.getPos().x || entiteeTick->getPos().x + entiteeTick->getSize().x > carte.getPos().x + 640) {
							deplacementDroite = 0;
							newPosEntitee.x -= entiteeTick->getVitesseDroite();
							entiteeTick->setPos(newPosEntitee);
						}
					}
					else {
						newPosEntitee.x += deplacementDroite * entiteeTick->getVitesseDroite();
						entiteeTick->setPos(newPosEntitee);
						if (!manageCollisionEntitee(entiteeTick) || entiteeTick->getPos().x < carte.getPos().x || entiteeTick->getPos().x + entiteeTick->getSize().x > carte.getPos().x + 640) {
							newPosEntitee.x -= deplacementDroite * entiteeTick->getVitesseDroite();
							entiteeTick->setPos(newPosEntitee);
							deplacementDroite = 0;
						}
						deplacementDroite--;
					}
				}

				entiteeTick->setVitesseDroite(0);

				while (deplacementHaut > 0) {
					if (deplacementHaut >= 1) {
						newPosEntitee.y -= entiteeTick->getVitesseHaut();
						entiteeTick->setPos(newPosEntitee);
						deplacementHaut--;
						if (!manageCollisionEntitee(entiteeTick) || entiteeTick->getPos().y < carte.getPos().y || entiteeTick->getPos().y + entiteeTick->getSize().y > carte.getPos().y + 640) {
							deplacementHaut = 0;
							newPosEntitee.y += entiteeTick->getVitesseHaut();
							entiteeTick->setPos(newPosEntitee);
						}
					}
					else {
						newPosEntitee.y -= deplacementHaut * entiteeTick->getVitesseHaut();
						entiteeTick->setPos(newPosEntitee);
						if (!manageCollisionEntitee(entiteeTick) || entiteeTick->getPos().y < carte.getPos().y || entiteeTick->getPos().y + entiteeTick->getSize().y > carte.getPos().y + 640) {
							newPosEntitee.y += deplacementHaut * entiteeTick->getVitesseHaut();
							entiteeTick->setPos(newPosEntitee);
							deplacementHaut = 0;
						}
						deplacementHaut--;
					}
				}

				entiteeTick->setVitesseHaut(0);

				entiteeTick->setPos(newPosEntitee);
			}
		}
	}
}

void Salle::tick(Objet * objetATick, int deltaTime) {
	
	objetATick->tick(&carte, &listeEntitees, &listeObjets, deltaTime);
}

bool Salle::manageCollisionEntitee(Entitee* e) {
	//Retourne false si l'entitee doit etre stoppée

	if (!carte.verifCollision(e->getPos(), e->getSize()))
		return false;

	for (int i = 0; i < nbObjets; i++) {
		if (listeObjets[i] != nullptr)
			if (listeObjets[i]->isNiveauJoueur())
				if (!listeObjets[i]->manageCollisionEntitee(e))
					return false;
	}

	for (int i = 0; i < nbEntitees; i++) {
		if (listeEntitees[i] != nullptr && e != listeEntitees[i])
			if (e->getPos().x + e->getSize().x > listeEntitees[i]->getPos().x && e->getPos().x < listeEntitees[i]->getPos().x + listeEntitees[i]->getSize().x && e->getPos().y + e->getSize().y > listeEntitees[i]->getPos().y && e->getPos().y < listeEntitees[i]->getPos().y + listeEntitees[i]->getSize().y)
				return false;
	}

	return true;
}

bool Salle::manageCollision(Vector2f pos, Vector2f size) {
	//Retourne false si il y a collision (non c'est pas logique)

	if (!carte.verifCollision(pos, size))
		return false;

	for (int i = 0; i < nbObjets; i++) {
		if (listeObjets[i] != nullptr)
			if (listeObjets[i]->isNiveauJoueur())
				if (!listeObjets[i]->manageCollision(pos, size))
					return false;
	}

	for (int i = 0; i < nbEntitees; i++) {
		if (listeEntitees[i] != nullptr)
			if (pos.x + size.x > listeEntitees[i]->getPos().x && pos.x < listeEntitees[i]->getPos().x + listeEntitees[i]->getSize().x && pos.y + size.y > listeEntitees[i]->getPos().y && pos.y < listeEntitees[i]->getPos().y + listeEntitees[i]->getSize().y)
				return false;
	}

	return true;
}

Objet* Salle::getObjet(int posX, int posY) {
	for (int i = 0; i < nbObjets; i++) {
		if (listeObjets[i] != nullptr)
			if (listeObjets[i]->getPos().x >= posX && listeObjets[i]->getPos().x < posX + 32 && listeObjets[i]->getPos().y >= posY && listeObjets[i]->getPos().y < posY + 32) 
				return listeObjets[i];
	}

	return nullptr;
}

int Salle::getIndexObjet(Objet* o) {
	if (o != nullptr) {
		for (int i = 0; i < nbObjets; i++) {
			if (listeObjets[i] == o)
				return i;
		}
	}

	return -1;
}

void Salle::addObjet(Objet* nObjet) {
	if (nObjet != nullptr) {
		if (typeid(*nObjet) != typeid(Sortie)) {
			int posX = nObjet->getPos().x / 32; posX *= 32;
			int posY = nObjet->getPos().y / 32; posY *= 32;

			if (removeObjet(posX, posY)) { //On enlève l'objet à la même position, et on ajoute le nouveau si il n'est pas au dessus de la sortie
				if (nbObjets <= 399) {
					listeObjets[nbObjets] = nObjet;
					nbObjets++;
				}
			}
		}
		else {
			sortie->setPos(nObjet->getPos());
			sortie->setRotation(nObjet->getRotation());
		}
	}
		
}

bool Salle::removeObjet(int posX, int posY) {
	for (int i = 0; i < nbObjets; i++) {
		if (listeObjets[i] != nullptr)
			if (listeObjets[i]->getPos().x >= posX && listeObjets[i]->getPos().x < posX + 32 && listeObjets[i]->getPos().y >= posY && listeObjets[i]->getPos().y < posY + 32) {
				if (typeid(*listeObjets[i]) != typeid(Sortie)) {
					Objet* objetASupprimer = listeObjets[i];
					bool isObjetActivable = (dynamic_cast<ObjetActivable*>(objetASupprimer));

					//Si l'objet à enlever est activable, on le retire des objets activants
					listeObjets[i] = nullptr;
					for (int j = 0; j < nbObjets; j++) {
						if (j >= i && j < 399)
							listeObjets[j] = listeObjets[j + 1];
						else if (j == 399)
							listeObjets[j] = nullptr;

						if (isObjetActivable && dynamic_cast<ObjetActivant*>(listeObjets[j]))	//Si l'objet à enlever est activable, on le deconnecte des objets activants
							dynamic_cast<ObjetActivant*>(listeObjets[j])->removeObjetAActiver(dynamic_cast<ObjetActivable*>(objetASupprimer));
					}

					delete objetASupprimer;
					nbObjets--;
					return true;
				}
				else {
					return false; //retourne false si on essaie d'enlever la sortie
				}
			}
	}

	return true;
}

Entitee* Salle::getEntitee(int posX, int posY) {
	for (int i = 0; i < nbEntitees; i++) {
		if (listeEntitees[i] != nullptr) 
			if (listeEntitees[i]->getPos().x >= posX && listeEntitees[i]->getPos().x <= posX + 32 && listeEntitees[i]->getPos().y >= posY && listeEntitees[i]->getPos().y + 32)
				return listeEntitees[i];
	}

	return nullptr;
}

void Salle::addEntitee(Entitee* nEntitee) {
	if (nEntitee != nullptr) {
		int posX = nEntitee->getPos().x / 32; posX *= 32;
		int posY = nEntitee->getPos().y / 32; posY *= 32;

		//Si il y a deja une entitée à cette position, on l'enlève
		removeEntitee(posX, posY);

		if (nbEntitees <= 29) {
			listeEntitees[nbEntitees] = nEntitee;
			nbEntitees++;
		}
	}
}

void Salle::removeEntitee(int posX, int posY) {
	for (int i = 0; i < nbEntitees; i++) {
		if (listeEntitees[i] != nullptr) {
			if (listeEntitees[i]->getPos().x >= posX && listeEntitees[i]->getPos().x <= posX + 32 && listeEntitees[i]->getPos().y >= posY && listeEntitees[i]->getPos().y + 32) {
				listeEntitees[i] = nullptr;

				for (int j = i; j < nbEntitees; j++) {
					if (j <= 28)
						listeEntitees[j] = listeEntitees[j + 1];
					else if (j == 29)
						listeEntitees[j] = nullptr;
				}
				
				nbEntitees--;
				return;
			}
		}
	}
}

void Salle::save(std::ofstream* fluxSave) {

	if (*fluxSave) {
		//On save la carte
		*fluxSave << "< ";		//Identificateur de la carte
		carte.save(fluxSave);
		*fluxSave << std::endl;

		//Puis les objets
		for (int i = 0; i < nbObjets; i++) {
			if (listeObjets[i] != nullptr) {
				listeObjets[i]->save(fluxSave);
				*fluxSave << std::endl;
			}
		}

		//Puis les connections entre les objets activants et activables
		for (int i = 0; i < nbObjets; i++) {
			if (listeObjets[i] != nullptr) 
				if (dynamic_cast<ObjetActivant*>(listeObjets[i])) {
					ObjetActivant* obj = dynamic_cast<ObjetActivant*>(listeObjets[i]);

					int iObj = getIndexObjet(obj);
					if (iObj != -1) {
						*fluxSave << "> ";			//Identificateur de la connection entre objets
						*fluxSave << iObj << " ";

						for (int i = 0; i < obj->getListeObjetsAActiver()->size(); i++) {
							int index = getIndexObjet(obj->getObjetAActiver(i));
							if (index != -1)
								*fluxSave << index << " ";
						}

						*fluxSave << iObj << " ";	//Pour marquer la fin de la connection
						*fluxSave << std::endl;
					}
				}
		}
		
		//Puis les entitées
		for (int i = 0; i < nbEntitees; i++) {
			if (listeEntitees[i] != nullptr && listeEntitees[i] != joueur) {
				listeEntitees[i]->save(fluxSave);
				*fluxSave << std::endl;
			}
		}

		*fluxSave << "; " << std::endl; //Marque la fin de la save
	}
	else {
		std::cout << "Salle : Impossible de créer le fichier" << std::endl;
	}
}

void Salle::load(std::ifstream* fluxLoad) {
	reset();	

	if (*fluxLoad) {
		bool carteLoad = false;
		bool objetsload = false;
		bool connectionsLoad = false;
		bool entiteesLoad = false;

		bool successLoad = true;
		bool end = false;

		char op = ' ';
		while (fluxLoad->get(op) && successLoad) {
			if (op == '<') { //Identificateur Carte
				if (!carteLoad && !objetsload && !connectionsLoad && !entiteesLoad && !end) {
					//La carte est load en premier
					carte.load(fluxLoad);
					carteLoad = true;
				}
				else
					successLoad = false;
			}

			else if (op > 65 && op <= 95) {
				if (!connectionsLoad && !entiteesLoad && !end) {
					//Puis les objets
					IncludeObjets io = IncludeObjets();
					Objet* nObjet = io.getObjetById(op);

					if (nObjet != nullptr)
						nObjet->load(fluxLoad);

					if (dynamic_cast<Sortie*>(nObjet)) {
						sortie->setPos(nObjet->getPos());
						sortie->setRotation(nObjet->getRotation());

						delete nObjet;
						nObjet = nullptr;
					}


					listeObjets[nbObjets] = nObjet;
					nbObjets++;

					objetsload = true;
				}
				else 
					successLoad = false;
			}

			else if (op == '>') {
				if (!entiteesLoad && !end) {
					//Puis les connections
					int idObjetActivant = -1;

					*fluxLoad >> idObjetActivant;

					if (idObjetActivant != -1) {
						if (dynamic_cast<ObjetActivant*>(getObjet(idObjetActivant))) {
							ObjetActivant* objetActivant = dynamic_cast<ObjetActivant*>(getObjet(idObjetActivant));

							int idObjetAActiver = -1;
							while (idObjetAActiver != idObjetActivant) {
								idObjetAActiver = -1;
								*fluxLoad >> idObjetAActiver;

								if (idObjetAActiver != -1 && idObjetAActiver != idObjetActivant) {
									if (dynamic_cast<ObjetActivable*>(getObjet(idObjetAActiver))) {
										ObjetActivable* objetAActiver = dynamic_cast<ObjetActivable*>(getObjet(idObjetAActiver));
										objetActivant->addObjetAActiver(objetAActiver);
									}
								}
							}
						}
					}

					connectionsLoad = true;
				}
				else
					successLoad = false;
			}

			else if (op > 97 && op <= 117) {
				if (!end) {
					//Puis les entitées
					IncludeEntitees ie = IncludeEntitees();
					Entitee* nEntitee = ie.getEntiteeById(op);

					if (nEntitee != nullptr)
						nEntitee->load(fluxLoad);

					listeEntitees[nbEntitees] = nEntitee;
					nbEntitees++;

					entiteesLoad = true;
				}
				else
					successLoad = false;
			}

			else if (op == ';') {
				if (!end)
					//Puis la fin
					end = true;
				else
					successLoad = false;
			}

		}

		if (!successLoad || !end) {
			//Si les chargements n'ont pas étés fait dans l'ordre ou si la fin n'a pas été détectée
			//On reset à caused'un erreur de chargement
			reset();

			std::cout << "Erreur de chargement" << std::endl;
		}

		this->tick(0);

	}
	else {
		std::cout << "Salle : Impossible de lire le fichier" << std::endl;
	}
}

void Salle::reset() {
	//On reset les listes
	listeObjets.fill(nullptr);
	nbObjets = 1;

	listeEntitees.fill(nullptr);
	nbEntitees = 1;

	//On reset la carte
	carte = Carte();
	carte.setPos(Vector2f(0, 32));

	//On reset le joueur
	if (joueur != nullptr)
		delete joueur;
	joueur = new Joueur();
	joueur->setPos(Vector2f(32, 64));
	listeEntitees[0] = joueur;

	if (sortie != nullptr)
		delete sortie;
	sortie = new Sortie(Vector2f(576, 640));
	listeObjets[0] = sortie;
}