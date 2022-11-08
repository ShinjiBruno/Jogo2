#include "Inimigo.h"

Inimigo::Inimigo() {

	direc = 0;
	shape.setSize(sf::Vector2f(50.0f, 70.0f));
	shape.setPosition(600, 400);
	shape.setOrigin(sf::Vector2f(shape.getSize().x/2, shape.getSize().y/2));
	shape.setFillColor(sf::Color::Green);
	visao.setRadius(300.0f);
	visao.setPosition(shape.getPosition());

	veloc = 0.2f;
}


Inimigo::~Inimigo() {}

void Inimigo::move() {

	if (direc == 1) {
		shape.move(-veloc, 0.0f);
	}

	if(direc == 2) {
		shape.move(veloc, 0.0f);
	}
	visao.setPosition(shape.getPosition());

}

void Inimigo::executa() {
	this->move();

}

