// Jeu Test.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include "Fenetre.h"

int main()
{
	Fenetre fenetre = Fenetre();

	//Lance les threads
	std::thread fen(&Fenetre::initialisation, &fenetre);

	fen.join();

    return 0;
}

