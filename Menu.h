#pragma once

#include "SFML/Graphics.hpp"
#include "Gerenciador_Grafico.h"
#include "Ente.h"

class Menu : public Ente
{
protected:
    int pos, numTexto;
    bool selected, pressed;

    sf::Font *font;
    sf::Texture *image;
    sf::Sprite *bg;

    std::vector<std::string> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;

public:
    Menu();
    ~Menu();

    void inicializarTexturas();
    void desenhar();
    void loopMenu();
    void limpar();
    virtual void executar();

    virtual void inicializar() = 0;
    virtual void tratarEscolha(int escolha) = 0;
};