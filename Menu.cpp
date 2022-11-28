#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu() : Ente(0), pos(0), numTexto(0), selected(false), pressed(false)
{
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    inicializarTexturas();
}

Menu::~Menu()
{
    delete font;
    delete image;
    delete bg;
}

void Menu::inicializarTexturas()
{
    font->loadFromFile("times new roman.ttf");
    image->loadFromFile("images/menu.png");
    bg->setTexture(*image);
}

void Menu::limpar()
{
    for (int i = 0; i < numTexto; i++)
    {
        texts[i].setOutlineThickness(0);
    }
    pos = 1;
    texts[pos].setOutlineThickness(4);
}

void Menu::loopMenu()
{
    sf::Event event;

    pressed = false;
    selected = false;

    while (pGraf->getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            pGraf->fecharJanela();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed)
        {
            if (pos < numTexto - 1)
            {
                ++pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                selected = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed)
        {
            if (pos > 1 || (numTexto == 2 && pos == 1))
            {
                --pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                selected = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !selected)
        {
            selected = true;
            tratarEscolha(pos);
            selected = false;
        }
    }
}

void Menu::desenhar()
{
    pGraf->limpaJanela();
    pGraf->desenhaBackground(*bg);
    for (auto &t : texts)
    {
        pGraf->escreveTexto(&t);
    }
    pGraf->mostrarJanela();
}

void Menu::executar()
{
    loopMenu();
    desenhar();
}