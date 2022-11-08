#pragma once
#include "SFML/Graphics.hpp"

class Grafico {
private:
	sf::RenderWindow* window;

public:
	Grafico();
	~Grafico();

	void setWindow(sf::RenderWindow* w) { window = w; }
	sf::RenderWindow* getWindow() { return window; }
};