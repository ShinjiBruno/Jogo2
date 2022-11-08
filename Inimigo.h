#pragma once
#include <SFML\Graphics.hpp>
#include "Personagem.h"

class Inimigo: public Personagem
{
private:
	int direc;

public:
	Inimigo();
	~Inimigo();

	void setDirec(int n) { direc = n; }
	void move();
	void executa();
};

