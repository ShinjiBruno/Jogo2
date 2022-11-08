#include "Jogador.h"

Jogador::Jogador()
{
	shape.setSize(sf::Vector2f(50, 70));
	shape.setPosition(sf::Vector2f(100, 400));
	shape.setOrigin(sf::Vector2f(shape.getSize().x / 2, shape.getSize().y / 2));
	shape.setFillColor(sf::Color::Red);
	visao.setRadius(100.0f);
	visao.setPosition(shape.getPosition());
	veloc = 0.7f;
}

Jogador::~Jogador() {
}

void Jogador::move() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && jump == false) {
        jump = true;
        impulso = -10;
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		shape.move(0, veloc);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		shape.move(-veloc, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		shape.move(veloc, 0);
	}

	if (jump)
        this->pula();

	visao.setPosition(shape.getPosition());
}


void Jogador::executa() {

	this->move();

}
