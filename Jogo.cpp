#include "Jogo.h"

Jogo::Jogo() {
	window = new sf::RenderWindow(sf::VideoMode(1300, 800), "Jogo");
	view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 1000.0f));
	menu = new Menu(window);
	jogador = new Jogador();
	jogador->setWindow(window);
	fase = new Fase(jogador, window);
	this->loopPrincipal();
}

Jogo::~Jogo() {
	delete window;
}

void Jogo::Redimensiona(sf::RenderWindow* window, sf::View* v)
{
	float proporcao = float(window->getSize().x) / float(window->getSize().y);
	v->setSize(VIEW_HEIGHT * proporcao, VIEW_HEIGHT);
}

void Jogo::loopPrincipal()
{
    while (window->isOpen()) {

		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			if (sf::Event::Resized) {
				Redimensiona(window, view);
				break;
			}
		}

		this->execute();
    }
}
void Jogo::pause()
{
        menu->ativa(true);
        menu->pause();
}

void Jogo::execute() {

    if (menu->estaAtivo()){
        window->clear();
        menu->execute();
        window->display();
    }
    else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
            pause();
        }
        view->setCenter(jogador->getShape()->getPosition());

        window->clear();
        fase->executa();

        window->setView(*view);
        window->display();
    }
}
