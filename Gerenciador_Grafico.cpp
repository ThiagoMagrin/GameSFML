#include "Gerenciador_Grafico.h"



#include <iostream>

#define PATH_FONT "Teste/fonts/times new roman.ttf"

GerenciadorGrafico::GerenciadorGrafico() :window(new sf::RenderWindow(sf::VideoMode(1100, 600), "JOGO")), fonte(new sf::Font())
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

sf::Font* GerenciadorGrafico::carregarFonte() {
    if (!fonte) {
        fonte = new sf::Font();
        fonte->loadFromFile(PATH_FONT);
        if (!fonte->loadFromFile(PATH_FONT)) {
            std::cout << "ERRO: Nao foi possivel carregar a fonte!" << std::endl;
            exit(1);
        }
    }
    
    return fonte;
}