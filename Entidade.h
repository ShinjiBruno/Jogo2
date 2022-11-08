#pragma once
#include <SFML/Graphics.hpp>

class Entidade
{
protected:
	sf::RectangleShape shape;
	sf::RenderWindow* window;
	bool plataforma;
	bool personagem;

public:
	Entidade();
	~Entidade();

	sf::RectangleShape* getShape() { return &shape; }
	void setWindow(sf::RenderWindow* w) { window = w;  }
	void drawEntidade() { window->draw(shape); }
	bool EhPersonagem() { return personagem; }
	bool EhPlataforma() {return plataforma;}

};
