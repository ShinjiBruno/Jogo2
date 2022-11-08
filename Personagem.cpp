#include "Personagem.h"
#include <iostream>
using namespace std;
Personagem::Personagem()
{
	shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
	impulso = -10;
	jump = false;
	personagem = true;
}

Personagem::~Personagem()
{

}

void Personagem::pula()
{
        shape.move(0.0f, impulso);

        if (impulso < 20)
        impulso += 0.2;

}
