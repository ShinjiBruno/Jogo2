#pragma once
#include "Jogador.h"
#include "Fase.h"
#include "Menu.h"

static const float VIEW_HEIGHT = 1000.0f;

class Jogo
{
private:
	Jogador* jogador;

	sf::RenderWindow* window;
	sf::View* view;
	sf::Event event;
	Fase* fase;
	Menu* menu;

public:
	Jogo();
	~Jogo();

	void Redimensiona( sf::RenderWindow* window, sf::View* v);
	void seleciona();
	void pause();
	void loopPrincipal();
	void execute();
};

