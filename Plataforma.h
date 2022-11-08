#pragma once
#include <SFML\Graphics.hpp>
#include "Entidade.h"


class Plataforma: public Entidade
{
protected:


public:
	Plataforma();
	~Plataforma();

	void configuraPlataforma(sf::Vector2f size, sf::Vector2f position);
};

