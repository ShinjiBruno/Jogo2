#pragma once
#include <SFML\Graphics.hpp>
#include "Personagem.h"


class Jogador : public Personagem
{
private:


public:
	Jogador();
	~Jogador();

	void move();
	void executa();
};

