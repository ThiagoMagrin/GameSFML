#pragma once

#include <SFML/Graphics.hpp>

class GerenciadorGrafico{
    private:
        sf::RenderWindow* window;
        static GerenciadorGrafico* pGrafico;

        GerenciadorGrafico();
    public:
        ~GerenciadorGrafico();
        sf::RenderWindow* getWindow();
        static GerenciadorGrafico* getGerenciadorGrafico();
        void limpaJanela();
        void fecharJanela();
        void mostrarJanela();
        const bool verificaJanelaAberta() const;
        void desenhaElemento(const sf::RectangleShape corpo);
        void desenhaBackground(const sf::Sprite background);
        void escreveTexto(sf::Text* texto);
        sf::Font* carregarFonte();
        sf::Texture* carregarTextura();
};
