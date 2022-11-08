#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
#define MaxMenu 4


class Menu {

private:
    int MenuSelecionado;
    bool ativo;

    sf::String nome;

    sf::RenderWindow* window;
    sf::Text texto[MaxMenu];
    sf::Font font;
    sf::Clock clock;

public:
    Menu(sf::RenderWindow* w);
    ~Menu();

    void ativa(bool a) { ativo = a; }
    bool estaAtivo() { return ativo; }

    void pause();

    void set_values();
    void moveUp();
    void moveDown();
    void Seleciona();
    void Selecionado();
    void draw();

    void execute();
};
