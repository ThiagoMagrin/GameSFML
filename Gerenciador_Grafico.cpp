#include "Gerenciador_Grafico.h"
#include <iostream>

#define PATH_FONT "Teste/fonts/times new roman.ttf"

namespace Gerenciadores{

    GerenciadorGrafico::GerenciadorGrafico() :window(new sf::RenderWindow(sf::VideoMode(1200, 600), "JOGO"))
    {
        std::cout << "Gerenciador Grafico criado\n";
    }

    GerenciadorGrafico::~GerenciadorGrafico()
    {
        if (window != nullptr)
        {
            delete(window);
            window = nullptr;
        }
    }

    GerenciadorGrafico* GerenciadorGrafico::pGrafico = nullptr;

    GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
    {

        if (pGrafico == nullptr) {
            pGrafico = new GerenciadorGrafico();
        }

        return pGrafico;
    }

    sf::RenderWindow* GerenciadorGrafico::getWindow()
    {
        return window;
    }

    void GerenciadorGrafico::limpaJanela() {
       if (window->isOpen()) {
            window->clear();
        }
    }

    void GerenciadorGrafico::fecharJanela() {
        if (window->isOpen()) {
            window->close();
        }
    }

    void GerenciadorGrafico::mostrarJanela() {
        if (window->isOpen()) {
            window->display();
        }
    }

    const bool GerenciadorGrafico::verificaJanelaAberta() const {
        return window->isOpen();
    }

    void GerenciadorGrafico::desenhaElemento(const sf::RectangleShape corpo) {
        window->draw(corpo);
    }

    void GerenciadorGrafico::escreveTexto(sf::Text* texto) {
        window->draw(*texto);
    }

    void GerenciadorGrafico::desenhaBackground(sf::Sprite background) {
        window->draw(background);
    }
}
