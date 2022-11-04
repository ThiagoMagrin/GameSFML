#pragma once

#include <SFML/Graphics.hpp>

class Menu {
private:
    int pos;
    bool pressed, theSelect;

    sf::RenderWindow* window;
    sf::RectangleShape* winClose;
    sf::Font* font;
    sf::Texture* image;
    sf::Sprite* bg;

    sf::Vector2i pos_mouse;
    sf::Vector2f coord_mouse;

    std::vector<const char*> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;

protected:
    void set_values();
    void loop_events();
    void draw_all();

public:
    Menu();
    ~Menu();
    void run_menu();
};

