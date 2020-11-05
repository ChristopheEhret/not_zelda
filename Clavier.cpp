#include "stdafx.h"
#include "Clavier.h"

using namespace sf;

Clavier::Clavier() {

}

void Clavier::update() {
	std::array<Touche, 101> newListeTouches;
	int newNbTouches = 0;

	//Ajoute les touches utilisées à la liste
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		newListeTouches[newNbTouches] = Touche("A", Keyboard::A, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::B)) {
		newListeTouches[newNbTouches] = Touche("B", Keyboard::B, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::C)) {
		newListeTouches[newNbTouches] = Touche("C", Keyboard::C, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		newListeTouches[newNbTouches] = Touche("D", Keyboard::D, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::E)) {
		newListeTouches[newNbTouches] = Touche("E", Keyboard::E, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F)) {
		newListeTouches[newNbTouches] = Touche("F", Keyboard::F, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::G)) {
		newListeTouches[newNbTouches] = Touche("G", Keyboard::G, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::H)) {
		newListeTouches[newNbTouches] = Touche("H", Keyboard::H, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::I)) {
		newListeTouches[newNbTouches] = Touche("I", Keyboard::I, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::J)) {
		newListeTouches[newNbTouches] = Touche("J", Keyboard::J, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::K)) {
		newListeTouches[newNbTouches] = Touche("K", Keyboard::K, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::L)) {
		newListeTouches[newNbTouches] = Touche("L", Keyboard::L, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::M)) {
		newListeTouches[newNbTouches] = Touche("M", Keyboard::M, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::N)) {
		newListeTouches[newNbTouches] = Touche("N", Keyboard::N, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}


	if (Keyboard::isKeyPressed(Keyboard::O)) {
		newListeTouches[newNbTouches] = Touche("O", Keyboard::O, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::P)) {
		newListeTouches[newNbTouches] = Touche("P", Keyboard::P, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Q)) {
		newListeTouches[newNbTouches] = Touche("Q", Keyboard::Q, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::R)) {
		newListeTouches[newNbTouches] = Touche("R", Keyboard::R, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		newListeTouches[newNbTouches] = Touche("S", Keyboard::S, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::T)) {
		newListeTouches[newNbTouches] = Touche("T", Keyboard::T, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::U)) {
		newListeTouches[newNbTouches] = Touche("U", Keyboard::U, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::V)) {
		newListeTouches[newNbTouches] = Touche("V", Keyboard::V, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		newListeTouches[newNbTouches] = Touche("W", Keyboard::W, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::X)) {
		newListeTouches[newNbTouches] = Touche("X", Keyboard::X, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Y)) {
		newListeTouches[newNbTouches] = Touche("Y", Keyboard::Y, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Z)) {
		newListeTouches[newNbTouches] = Touche("Z", Keyboard::Z, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Num0)) {
		newListeTouches[newNbTouches] = Touche("0", Keyboard::Num0, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Num1)) {
		newListeTouches[newNbTouches] = Touche("1", Keyboard::Num1, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Num2)) {
		newListeTouches[newNbTouches] = Touche("2", Keyboard::Num2, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Num3)) {
		newListeTouches[newNbTouches] = Touche("3", Keyboard::Num3, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Num4)) {
		newListeTouches[newNbTouches] = Touche("4", Keyboard::Num4, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Num5)) {
		newListeTouches[newNbTouches] = Touche("5", Keyboard::Num5, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Num6)) {
		newListeTouches[newNbTouches] = Touche("6", Keyboard::Num6, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Num7)) {
		newListeTouches[newNbTouches] = Touche("7", Keyboard::Num7, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Num8)) {
		newListeTouches[newNbTouches] = Touche("8", Keyboard::Num8, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Num9)) {
		newListeTouches[newNbTouches] = Touche("9", Keyboard::Num9, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		newListeTouches[newNbTouches] = Touche("Esc", Keyboard::Escape, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::LControl)) {
		newListeTouches[newNbTouches] = Touche("LCtrl", Keyboard::LControl, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::LShift)) {
		newListeTouches[newNbTouches] = Touche("LShift", Keyboard::LShift, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::LAlt)) {
		newListeTouches[newNbTouches] = Touche("LAlt", Keyboard::LAlt, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::LSystem)) {
		newListeTouches[newNbTouches] = Touche("LWin", Keyboard::LSystem, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::RControl)) {
		newListeTouches[newNbTouches] = Touche("RCtrl", Keyboard::RControl, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::RShift)) {
		newListeTouches[newNbTouches] = Touche("RShift", Keyboard::RShift, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::RAlt)) {
		newListeTouches[newNbTouches] = Touche("RAlt", Keyboard::RAlt, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::RSystem)) {
		newListeTouches[newNbTouches] = Touche("RWin", Keyboard::RSystem, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Menu)) {
		newListeTouches[newNbTouches] = Touche("Menu", Keyboard::Menu, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::RBracket)) {
		newListeTouches[newNbTouches] = Touche("]", Keyboard::RBracket, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::LBracket)) {
		newListeTouches[newNbTouches] = Touche("[", Keyboard::LBracket, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::SemiColon)) {
		newListeTouches[newNbTouches] = Touche(";", Keyboard::SemiColon, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Comma)) {
		newListeTouches[newNbTouches] = Touche(",", Keyboard::Comma, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Period)) {
		newListeTouches[newNbTouches] = Touche(".", Keyboard::Period, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Quote)) {
		newListeTouches[newNbTouches] = Touche("''", Keyboard::Quote, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Slash)) {
		newListeTouches[newNbTouches] = Touche("/", Keyboard::Slash, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::BackSlash)) {
		newListeTouches[newNbTouches] = Touche("'\'", Keyboard::BackSlash, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Tilde)) {
		newListeTouches[newNbTouches] = Touche("~", Keyboard::Tilde, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Equal)) {
		newListeTouches[newNbTouches] = Touche("=", Keyboard::Equal, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Dash)) {
		newListeTouches[newNbTouches] = Touche("-", Keyboard::Dash, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		newListeTouches[newNbTouches] = Touche(" ", Keyboard::Space, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Return)) {
		newListeTouches[newNbTouches] = Touche("Ret Arr", Keyboard::Return, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
		newListeTouches[newNbTouches] = Touche("BackSpace", Keyboard::BackSpace);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Tab)) {
		newListeTouches[newNbTouches] = Touche("Tab", Keyboard::Tab, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::PageUp)) {
		newListeTouches[newNbTouches] = Touche("PageUp", Keyboard::PageUp, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::PageDown)) {
		newListeTouches[newNbTouches] = Touche("PageDown", Keyboard::PageDown, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::End)) {
		newListeTouches[newNbTouches] = Touche("Fin", Keyboard::End, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Home)) {
		newListeTouches[newNbTouches] = Touche("Home", Keyboard::Home, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Insert)) {
		newListeTouches[newNbTouches] = Touche("Insert", Keyboard::Insert, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Delete)) {
		newListeTouches[newNbTouches] = Touche("Del", Keyboard::Delete, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Add)) {
		newListeTouches[newNbTouches] = Touche("+", Keyboard::Add, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Subtract)) {
		newListeTouches[newNbTouches] = Touche("-", Keyboard::Subtract, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Multiply)) {
		newListeTouches[newNbTouches] = Touche("*", Keyboard::Multiply, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Divide)) {
		newListeTouches[newNbTouches] = Touche("/", Keyboard::Divide, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		newListeTouches[newNbTouches] = Touche("Gauche", Keyboard::Left, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		newListeTouches[newNbTouches] = Touche("Droite", Keyboard::Right, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		newListeTouches[newNbTouches] = Touche("Haut", Keyboard::Up, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		newListeTouches[newNbTouches] = Touche("Bas", Keyboard::Down, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Numpad0)) {
		newListeTouches[newNbTouches] = Touche("Num0", Keyboard::Numpad0, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Numpad1)) {
		newListeTouches[newNbTouches] = Touche("Num1", Keyboard::Numpad1, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Numpad2)) {
		newListeTouches[newNbTouches] = Touche("Num2", Keyboard::Numpad2, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Numpad3)) {
		newListeTouches[newNbTouches] = Touche("Num3", Keyboard::Numpad3, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Numpad4)) {
		newListeTouches[newNbTouches] = Touche("Num4", Keyboard::Numpad4, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Numpad5)) {
		newListeTouches[newNbTouches] = Touche("Num5", Keyboard::Numpad5, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Numpad6)) {
		newListeTouches[newNbTouches] = Touche("Num6", Keyboard::Numpad6, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Numpad7)) {
		newListeTouches[newNbTouches] = Touche("Num7", Keyboard::Numpad7, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Numpad8)) {
		newListeTouches[newNbTouches] = Touche("Num8", Keyboard::Numpad8, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Numpad9)) {
		newListeTouches[newNbTouches] = Touche("Num9", Keyboard::Numpad9, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F1)) {
		newListeTouches[newNbTouches] = Touche("F1", Keyboard::F1, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F2)) {
		newListeTouches[newNbTouches] = Touche("F2", Keyboard::F2, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F3)) {
		newListeTouches[newNbTouches] = Touche("F3", Keyboard::F3, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F5)) {
		newListeTouches[newNbTouches] = Touche("F5", Keyboard::F5, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F4)) {
		newListeTouches[newNbTouches] = Touche("F4", Keyboard::F4, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F6)) {
		newListeTouches[newNbTouches] = Touche("F6", Keyboard::F6, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F7)) {
		newListeTouches[newNbTouches] = Touche("F7", Keyboard::F7, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F8)) {
		newListeTouches[newNbTouches] = Touche("F8", Keyboard::F8, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F9)) {
		newListeTouches[newNbTouches] = Touche("F9", Keyboard::F9, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F10)) {
		newListeTouches[newNbTouches] = Touche("F10", Keyboard::F10, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F11)) {
		newListeTouches[newNbTouches] = Touche("F11", Keyboard::F11, true);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (Keyboard::isKeyPressed(Keyboard::F12)) {
		newListeTouches[newNbTouches] = Touche("F12", Keyboard::F12);
		newListeTouches[newNbTouches].setHeld(toucheEstEllePressee(newListeTouches[newNbTouches]));
		newNbTouches++;
	}

	if (newNbTouches != 0)
		derniereTouche = &newListeTouches[0];
	else
		derniereTouche = nullptr;

	nbTouches = newNbTouches;
	listeDernieresTouches = newListeTouches;

}

bool Clavier::toucheEstEllePressee(Touche t) {
	for (int i = 0; i < nbTouches; i++) {
		//Verifie grâce à l'id et au nom de la touche
		if (listeDernieresTouches[i].getId() == t.getId() && listeDernieresTouches[i].getName() == t.getName())
			return true;
	}
	return false;
}