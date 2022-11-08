#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "listaEntidades.h"
#include "ListaPersonagens.h"
#include "Inimigo.h"
#include "Colisor.h"
#include "Plataforma.h"

class Fase
{
private:
	sf::RenderWindow* window;
	Jogador* jogador;
	Inimigo* inim;
	Plataforma* plat;

	Colisor gerenciaCol;

	ListaEntidades* lisEnt;
	ListaPersonagem* lisPerso;

public:
	Fase(Jogador* jog, sf::RenderWindow* w);
	~Fase();

	void gerenciaColisao();
	void gravidade();
	void criaListas();
	void drawFase();
	void executa();
};

