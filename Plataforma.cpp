#include "Plataforma.h"

Plataforma::Plataforma()
{
	plataforma = true;

}

Plataforma::~Plataforma()
{

}

void Plataforma::configuraPlataforma(sf::Vector2f size, sf::Vector2f position)
{
	shape.setSize(size);
	shape.setPosition(position);
	shape.setOrigin(sf::Vector2f(shape.getSize().x / 2, shape.getSize().y / 2));
}
