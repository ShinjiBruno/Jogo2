#include "Menu.h"

Menu::Menu(sf::RenderWindow* w)
{
    window = w;

    if (!font.loadFromFile("font.ttf")){
        cout<<"Erro ao carregar a fonte do menu"<<endl;
    }

    ativo = true;
    MenuSelecionado = -1;
    clock.restart();
    set_values();
}

Menu::~Menu()
{

}

void Menu::set_values()
{
    //PLAY
   texto[0].setFont(font);
   texto[0].setFillColor(sf::Color::White);
   texto[0].setString("Play");
   texto[0].setCharacterSize(75);
   texto[0].setPosition(400, 200);

   //OPTIONS
   texto[1].setFont(font);
   texto[1].setFillColor(sf::Color::White);
   texto[1].setString("Options");
   texto[1].setCharacterSize(75);
   texto[1].setPosition(400, 300);

   //SALVE
   texto[2].setFont(font);
   texto[2].setFillColor(sf::Color::White);
   texto[2].setString("Save");
   texto[2].setCharacterSize(75);
   texto[2].setPosition(400, 400);

   //QUIT
   texto[3].setFont(font);
   texto[3].setFillColor(sf::Color::White);
   texto[3].setString("Quit");
   texto[3].setCharacterSize(75);
   texto[3].setPosition(400, 500);
}

void Menu::draw()
{
    for(int i=0; i<MaxMenu; i++){
        window->draw(texto[i]);
    }
}

void Menu::moveUp()
{
    if(MenuSelecionado > -1)
        texto[MenuSelecionado].setFillColor(sf::Color::White);

    MenuSelecionado--;
    if (MenuSelecionado == -1){
        MenuSelecionado = 3;
    }

    texto[MenuSelecionado].setFillColor(sf::Color::Magenta);
}

void Menu::moveDown()
{
    if (MenuSelecionado > -1)
        texto[MenuSelecionado].setFillColor(sf::Color::White);

    MenuSelecionado++;
    if (MenuSelecionado == 4){
        MenuSelecionado = 0;
    }

    texto[MenuSelecionado].setFillColor(sf::Color::Magenta);
}

void Menu::Seleciona()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && clock.getElapsedTime().asMilliseconds() >= 175){
        this->moveDown();
        clock.restart();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&  clock.getElapsedTime().asMilliseconds() >= 175){
        this->moveUp();
        clock.restart();
    }

    this->Selecionado();
}

void Menu::Selecionado()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        switch (MenuSelecionado) {
            case 0:
                ativo = false;
                break;
            case 3:
                window->close();
                break;
            }
    }
}

void Menu::pause()
{
    texto[0].setString("Resume");
}

void Menu::execute()
{
    Seleciona();
    draw();
}
