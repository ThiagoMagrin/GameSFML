#include "Menu.h"
#include "Gerenciador_Grafico.h"
#include <iostream>
Menu::Menu() {
    window = new sf::RenderWindow();
    winClose = new sf::RectangleShape();
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    set_values();
}

Menu::~Menu() {
    delete window;
    delete winClose;
    delete font;
    delete image;
    delete bg;
}

#define PATH_FONT "fonts/timesnewroman.ttf" 
void Menu::set_values() {
    window->create(sf::VideoMode(1280, 511), "Menu SFML", sf::Style::Titlebar | sf::Style::Close);
    window->setPosition(sf::Vector2i(0, 0));

    pressed = theSelect = false;

    if (!font->loadFromFile(PATH_FONT)) {
        std::cout << "ERRO";
        exit(1);
    }
 

    image->loadFromFile("background.png");
    bg->setTexture(*image);

    pos_mouse = { 0,0 };
    coord_mouse = { 0,0 };

    options = { "PLAY", "SCORE", "ABOUT", "QUIT" };
    texts.resize(4);
    coords = { {595, 163}, {588, 235}, {585, 305}, {595, 375} };
    sizes = { 24, 24, 24, 24 };

    for (std::size_t i{}; i < texts.size(); i++) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::White);
        texts[i].setPosition(coords[i]);
    }

    texts[0].setOutlineThickness(1);
    pos = 0;
}

void Menu::loop_events() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
            if (pos < 3) {
                pos++;
                pressed = true;
                texts[pos].setOutlineThickness(1);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theSelect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
            if (pos > 0) {
                pos--;
                pressed = true;
                texts[pos].setOutlineThickness(1);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theSelect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theSelect) {
            theSelect = true;
            if (pos == 3) {
                window->close();
            }
        }
    }
}

void Menu::draw_all() {
    window->clear();
    window->draw(*bg);
    for (auto t : texts) {
        window->draw(t);
    }
    window->display();
}

void Menu::run_menu() {
    while (window->isOpen()) {
        loop_events();
        draw_all();
    }
}
