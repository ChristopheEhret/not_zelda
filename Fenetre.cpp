#include "stdafx.h"
#include "Fenetre.h"

Fenetre::Fenetre() {
}

void Fenetre::initialisation() {

	timer = Clock();
	salle = Salle();

	clavier = Clavier();

	RenderWindow w(VideoMode(640, 704), "Hey!"); //Crée la fenetre
	window = &w;

	menuEditeur = MenuEditeur(&salle.carte);

	police = Font();
	police.loadFromFile("Font/police.ttf");

	manage();
}

void Fenetre::manage() {
	if (window != nullptr) {
		//Boucle tant que la fenetre est ouverte
		while (window->isOpen()) {
			//Ferme la fenetre si besoin
			Event event;
			while (window->pollEvent(event))
			{
				if (event.type == Event::Closed)
					window->close();
			}
			if (window->hasFocus()) {
				tick();
				draw();
			}

		}
	}

	fin = true;
}

void Fenetre::tick() { //Appellée à chaque frame

	time = timer.getElapsedTime().asMilliseconds();
	deltaTime = time - memTime;

	if (deltaTime < 7) //Frame >= 10 ms
		return;

	if (menu.getGamemode() == GAMEMODE_JEU) {
		if (oldGamemode == GAMEMODE_MENU) {
			std::ifstream load("Save/carte.txt");
			salle.load(&load);
		}

		salle.tick(deltaTime);
		manageJoueur();

		if (salle.sortie->getFin())
			menu.retourneMenuPrincipal();
	}

	if (menu.getGamemode() == GAMEMODE_MENU) {
		if (oldGamemode == GAMEMODE_EDITEUR) {
			std::ofstream save("Save/carte.txt");
			salle.save(&save);
		}
		resetMenu();
	}

	if (menu.getGamemode() == GAMEMODE_EDITEUR) {
		if (oldGamemode == GAMEMODE_MENU) {
			std::ifstream load("Save/carte.txt");
			salle.load(&load);	
		}
		manageEditeur();
	}

	oldGamemode = menu.getGamemode();
	menu.tick(window);

	clavier.update();

	memTime = timer.getElapsedTime().asMilliseconds();

	window->setSize(Vector2u(640, 704)); //Force la taille de la fenetre

	LMBUtiliseDerniereFrame = Mouse::isButtonPressed(Mouse::Left);
	RMBUtiliseDerniereFrame = Mouse::isButtonPressed(Mouse::Right);
}

void Fenetre::draw() {
	// Clear screen
	window->clear();

	//Appelle les différents draws
	salle.draw(window);
	menu.draw(window);

	if (menu.getGamemode() == GAMEMODE_EDITEUR) {
		menuEditeur.draw(window);

		drawEditeur(window);
	}

	
	window->display();
	
}

void Fenetre::resetMenu() {
	salle.joueur->setPos(Vector2f(32, 64));
	salle.joueur->setDirection(BAS);
}

void Fenetre::manageJoueur() {
	//Ajoute les inputs du joueur
	if (clavier.toucheEstEllePressee(avant)) {
		salle.joueur->addInput(INPUT_AVANT);
	}
	if (clavier.toucheEstEllePressee(arriere)) {
		salle.joueur->addInput(INPUT_ARRIERE);
	}
	if (clavier.toucheEstEllePressee(gauche)) {
		salle.joueur->addInput(INPUT_GAUCHE);
	}
	if (clavier.toucheEstEllePressee(droite)) {
		salle.joueur->addInput(INPUT_DROITE);
	}

	/*joueur.tick();


	float deplacement = 0.f;
	//Bouge le joueur et verifie les collision
	if (joueur.getVitesseDroite() != 0 && joueur.getVitesseHaut() != 0) {
		//Si le joueur bouge en diagonales, on reduit les vitesses individuelles afin de faire un vitesse globale equivalente 
		deplacement = sqrt(pow(((joueur.getVitesse() * deltaTime) / 16), 2.f) / 2);
	}
	else {
		deplacement = (joueur.getVitesse() * deltaTime) / 16;
	}

	float deplacementDroite = deplacement;
	float deplacementHaut = deplacement;

	Vector2f newPosJoueur = joueur.getPos();

	//Bouge le joueur en verifiant les collisions pixel par pixel
	while (deplacementDroite > 0 && joueur.getVitesseDroite() != 0) {
		
		if (deplacementDroite >= 1) {
			newPosJoueur.x += joueur.getVitesseDroite();
			joueur.setPos(newPosJoueur);
			deplacementDroite--;
			if (!salle.manageCollisionEntitee(&joueur) || joueur.getPos().x < salle.carte.getPos().x || joueur.getPos().x + joueur.getSize().x > salle.carte.getPos().x + 640) {
				deplacementDroite = 0;
				newPosJoueur.x -= joueur.getVitesseDroite();
				joueur.setPos(newPosJoueur);
			}
		}
		else {
			newPosJoueur.x += deplacementDroite * joueur.getVitesseDroite();
			joueur.setPos(newPosJoueur);
			if (!salle.manageCollisionEntitee(&joueur) || joueur.getPos().x < salle.carte.getPos().x || joueur.getPos().x + joueur.getSize().x > salle.carte.getPos().x + 640) {
				newPosJoueur.x -= deplacementDroite * joueur.getVitesseDroite();
				joueur.setPos(newPosJoueur);
				deplacementDroite = 0;
			}
			deplacementDroite--;
		}
	}
	
	joueur.setVitesseDroite(0);

	while (deplacementHaut > 0 &&  joueur.getVitesseHaut() != 0) {
		if (deplacementHaut >= 1) {
			newPosJoueur.y -= joueur.getVitesseHaut();
			joueur.setPos(newPosJoueur);
			deplacementHaut--;
			if (!salle.manageCollisionEntitee(&joueur) || joueur.getPos().y < salle.carte.getPos().y || joueur.getPos().y + joueur.getSize().y > salle.carte.getPos().y + 640) {
				deplacementHaut = 0;
				newPosJoueur.y += joueur.getVitesseHaut();
				joueur.setPos(newPosJoueur);
			}
		}
		else {
			newPosJoueur.y -= deplacementHaut * joueur.getVitesseHaut();
			joueur.setPos(newPosJoueur);
			if (!salle.manageCollisionEntitee(&joueur) || joueur.getPos().y < salle.carte.getPos().y || joueur.getPos().y + joueur.getSize().y > salle.carte.getPos().y + 640) {
				newPosJoueur.y += deplacementHaut * joueur.getVitesseHaut();
				joueur.setPos(newPosJoueur);
				deplacementHaut = 0;
			}
			deplacementHaut--;
		}
	}

	joueur.setVitesseHaut(0);

	joueur.setPos(newPosJoueur);*/
}

void Fenetre::manageEditeur() {
	menuEditeur.tick(window);

	//Position de la souris par rapport à la position de la fenetre
	Vector2f posRelativeSouris(Mouse::getPosition().x - (window->getPosition().x + 9), Mouse::getPosition().y - (window->getPosition().y + 39));
	int posXSouris = posRelativeSouris.x / 32; posXSouris *= 32;
	int posYSouris = posRelativeSouris.y / 32; posYSouris *= 32;

	//Position de la case pointée par la souris (multiple de 32)
	Vector2f posSourisEditeur = Vector2f(posXSouris, posYSouris);

	//Si la souris est hors de la carte, on sort de la fonction
	if (posRelativeSouris.x >= 640 + salle.carte.getPos().x || posRelativeSouris.y >= 640 + salle.carte.getPos().y || posRelativeSouris.x < salle.carte.getPos().x || posRelativeSouris.y < salle.carte.getPos().y)
		return;

	if (menuEditeur.isExtendChoix())
		return;

	if (!editeurConnecte) {
		//Si le joueur clique (conditions supplémentaires pour éviter de temps placer un item)	
		if (Mouse::isButtonPressed(Mouse::Left) && (posSourisEditeur != oldPosSourisEditeur || !LMBUtiliseDerniereFrame)) {
			if (menuEditeur.getObjetChoisi() != nullptr) {	//Si l'utilisateur a choisi un objet
					IncludeObjets i = IncludeObjets();		//On crée un objet du meme type que l'objet choisi
					Objet* nObjet = i.creeNouvelObjet(menuEditeur.getObjetChoisi());

					if (nObjet == nullptr)
						return;

					//Place l'objet au centre de l'endroit cliqué
					int posX = posRelativeSouris.x / 32;
					posX = posX * 32 + (16 - nObjet->getSize().x / 2);
					int posY = posRelativeSouris.y / 32;
					posY = posY * 32 + (16 - nObjet->getSize().y / 2);
					
					nObjet->setPos(Vector2f(posX, posY));
					nObjet->setRotation(rotationObjetEditeur);

					if (typeid(*nObjet) != typeid(Effaceur))
						salle.addObjet(nObjet);										//Place l'objet
					else {
						salle.removeObjet(nObjet->getPos().x, nObjet->getPos().y);	//Efface si l'objet est l'effaceur
						delete nObjet;
					}
					rotationObjetEditeur = HAUT;	
			}
			else if (menuEditeur.getTileChoisi() != -1) {	//Si l'utilisateur a choisi un tile
				int posX = (posRelativeSouris.x - salle.carte.getPos().x) / 32;
				int posY = (posRelativeSouris.y - salle.carte.getPos().y) / 32;
				
				salle.carte.setTile(menuEditeur.getTileChoisi(), posX, posY);	//On le place sur la carte
				
			}
		}
	}
	else {
		//Si on connecte un objet activant
		if (LMBUtiliseDerniereFrame && !Mouse::isButtonPressed(Mouse::Left)) { //lorsqu'on relache le clique
			int posX = posRelativeSouris.x / 32; posX *= 32;
			int posY = posRelativeSouris.y / 32; posY *= 32;

			Objet* objetActivableAConnecter = salle.getObjet(posX, posY);
			if (objetActivableAConnecter != nullptr) {
				if (dynamic_cast<ObjetActivable*>(objetActivableAConnecter))	//Si l'objet est un objet activable
					if (!objetAConnecter->removeObjetAActiver(dynamic_cast<ObjetActivable*>(objetActivableAConnecter)))  //On déconnecte l'objet à connecter. Si il n'etait pas connecté :
						objetAConnecter->addObjetAActiver(dynamic_cast<ObjetActivable*>(objetActivableAConnecter));		 //On le connecte
			}
			editeurConnecte = false;
		}

	}
	//Si l'utilisateur clique droit
	if (RMBUtiliseDerniereFrame && !Mouse::isButtonPressed(Mouse::Right)) {
		int posX = posRelativeSouris.x / 32; posX *= 32;
		int posY = posRelativeSouris.y / 32; posY *= 32;

		Objet* objetSelectionne = salle.getObjet(posX, posY);
		if (objetSelectionne != nullptr) {
			if (dynamic_cast<ObjetActivant*>(objetSelectionne)) { //Si la souris survole un objet activable
				editeurConnecte = true;
				//On entre en mode connection
				objetAConnecter = dynamic_cast<ObjetActivant*>(objetSelectionne);
			}
			else if (dynamic_cast<ObjetActivable*>(objetSelectionne)) {	//Si la souris survole un objet activable

				dynamic_cast<ObjetActivable*>(objetSelectionne)->toggleActifBase();	//On change son etat de base
				salle.tick(objetSelectionne, deltaTime);
			}
		}
	}

	//Rotate l'objet si l'utilisateur le veut
	if(clavier.getDerniereTouche() != nullptr)
		if (clavier.getDerniereTouche()->getId() == rotationEditeurDroite.getId() && !clavier.getDerniereTouche()->isHeld()) {
			++rotationObjetEditeur;
			if (rotationObjetEditeur > GAUCHE)
				rotationObjetEditeur = HAUT;
		} else 	if (clavier.getDerniereTouche()->getId() == rotationEditeurGauche.getId() && !clavier.getDerniereTouche()->isHeld()) {
			--rotationObjetEditeur;
			if (rotationObjetEditeur < HAUT)
				rotationObjetEditeur = GAUCHE;
		}

	if (menuEditeur.getTileChoisi() != -1)
		rotationObjetEditeur = HAUT;

	oldPosSourisEditeur = posSourisEditeur;
}

void Fenetre::drawEditeur(RenderWindow* w) {
	Vector2f posRelativeSouris(Mouse::getPosition().x - (window->getPosition().x + 9), Mouse::getPosition().y - (window->getPosition().y + 39));

	if (posRelativeSouris.x >= 640 + salle.carte.getPos().x || posRelativeSouris.y >= 640 + salle.carte.getPos().y|| posRelativeSouris.x < salle.carte.getPos().x || posRelativeSouris.y < salle.carte.getPos().y)
		return;

	if (menuEditeur.isExtendChoix())
		return;

	int posX = posRelativeSouris.x / 32; posX *= 32;
	int posY = posRelativeSouris.y / 32; posY *= 32;

	Objet* objetSurvole = salle.getObjet(posX, posY);
	//String qui contient les infos affichée en haut à droite
	String infos = "";

	if (!editeurConnecte) {
		if (objetSurvole == nullptr || dynamic_cast<Effaceur*>(menuEditeur.getObjetChoisi())) { //Si on ne survole rien ou que l'effaceur est séléctionné
			//On affiche une prévisualisation de l'item à la position de la souris
			Texture textPrevisualisation;
			Vector2f posSprite = Vector2f(posX, posY);

			if (menuEditeur.getTileChoisi() != -1) {
				textPrevisualisation.loadFromFile(salle.carte.getTile(menuEditeur.getTileChoisi())->texturePath + "_previsualisation.png");
			}
			else if (menuEditeur.getObjetChoisi() != nullptr) {
				textPrevisualisation.loadFromFile(menuEditeur.getObjetChoisi()->getPathTexture() + "_previsualisation.png");

				//Centre la prévisualisation en fonction de la taille de l'objet
				posSprite.x = posX + 16 - (menuEditeur.getObjetChoisi()->getSize().x / 2);
				posSprite.y = posY + 16 - (menuEditeur.getObjetChoisi()->getSize().y / 2);
			}

			Sprite spritePrevisualisation = Sprite(textPrevisualisation);
			spritePrevisualisation.move(posSprite);

			if (menuEditeur.getObjetChoisi() != nullptr && menuEditeur.getTileChoisi() == -1)
				if (typeid(*menuEditeur.getObjetChoisi()) != typeid(Effaceur)) {
					switch (rotationObjetEditeur)
					{
					case GAUCHE:
						spritePrevisualisation.move(Vector2f(0, menuEditeur.getObjetChoisi()->getSize().y));
						break;
					case DROITE:
						spritePrevisualisation.move(Vector2f(menuEditeur.getObjetChoisi()->getSize().x, 0));
						break;
					case BAS:
						spritePrevisualisation.move(Vector2f(menuEditeur.getObjetChoisi()->getSize().x, menuEditeur.getObjetChoisi()->getSize().y));
						break;
					}

					spritePrevisualisation.rotate(rotationObjetEditeur * 90);
				}

			w->draw(spritePrevisualisation);
		}
		else {
			//Sinon, on affiche des infos à propos de l'objet survolé
			if (dynamic_cast<ObjetActivable*>(objetSurvole)) {
				infos = "Click droit pour changer l'état de base";
			}
			else if (dynamic_cast<ObjetActivant*>(objetSurvole)) {
				infos = "Click droit pour connecter à un objet activable";

				ObjetActivant* objetActivant = dynamic_cast<ObjetActivant*>(objetSurvole); //Si l'objet survolé est un objet activant, on affiche les connections
				for (int i = 0; i < objetActivant->getListeObjetsAActiver()->size(); i++) {
					if (objetActivant->getListeObjetsAActiver()->at(i) != nullptr) {
						ObjetActivable* objetConnecte = objetActivant->getListeObjetsAActiver()->at(i);

						//on trace une ligne entre l'objet activant et l'objet connecté
						Vertex ligne[] = {
							Vertex(Vector2f(objetActivant->getPos().x + (objetActivant->getSize().x / 2), objetActivant->getPos().y + (objetActivant->getSize().y / 2)), Color::Green),
							Vertex(Vector2f(objetConnecte->getPos().x + (objetConnecte->getSize().x / 2), objetConnecte->getPos().y + (objetConnecte->getSize().y / 2)), Color::Green)
						};

						w->draw(ligne, 2, Lines);

					}
				}

			}
		}
	}
	else {
		//Si on est en phase de connection
		if (objetAConnecter != nullptr) {
			Color couleur = Color::Black;

			if (objetSurvole != nullptr && dynamic_cast<ObjetActivable*>(objetSurvole)) //Si la souris survole un objet activable
				if (objetAConnecter->removeObjetAActiver(dynamic_cast<ObjetActivable*>(objetSurvole))) {	//Si il est déja connecté à l'objet activant
					objetAConnecter->addObjetAActiver(dynamic_cast<ObjetActivable*>(objetSurvole));
					couleur = Color::Red; //La ligne va etre rouge

					infos = "Click gauche pour déconnecter";
				}
				else {
					couleur = Color::Green;	//Sinon, la ligne va etre verte

					infos = "Click gauche pour connecter";
				}

			//Trace la ligne entre l'objet activant et l'objet survolé
			Vertex ligne[] = {
				Vertex(Vector2f(objetAConnecter->getPos().x + (objetAConnecter->getSize().x / 2), objetAConnecter->getPos().y + (objetAConnecter->getSize().y / 2)), couleur),
				Vertex(posRelativeSouris, couleur)
			};

			w->draw(ligne, 2, Lines);
		}
		else
			editeurConnecte = false;
	}

	//"Dessine" l'info en haut de l'écran
	Text texteInfo = Text(infos, police, 15);
	texteInfo.setFillColor(Color::White);
	texteInfo.move(320 - (texteInfo.getLocalBounds().width / 2), 16 - (texteInfo.getLocalBounds().height / 2));

	w->draw(texteInfo);

}