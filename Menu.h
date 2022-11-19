

#pragma once

//baseado no tutorial: https://www.youtube.com/watch?v=h8-Q4eu3Qt4

#include "SFML/Graphics.hpp"
#include "Jogo.h"
#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include <iostream>

class Menu : public Ente {
    
        int pos;
        bool pressed, theselect;
        sf::Font* font;
        sf::Texture* image;
        sf::Sprite* bg;

        std::vector<const char*> options;
        std::vector<sf::Vector2f> coords;
        std::vector<sf::Text> texts;
        std::vector<std::size_t> sizes;

        Jogo *obgJogo;

    protected:
        void inicializar();
        void selecao();
        void desenhar();

    public:
        Menu();
        ~Menu();
        void run_menu();
    
};
