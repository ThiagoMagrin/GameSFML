#pragma once

#include <SFML/Graphics.hpp>

namespace Gerenciadores{
    class GerenciadorGrafico{
        private:
            sf::RenderWindow* window;
            static GerenciadorGrafico* pGrafico;

            GerenciadorGrafico();
        public:
            ~GerenciadorGrafico();
            sf::RenderWindow* getWindow();
            static GerenciadorGrafico* getGerenciadorGrafico();
            static void deletarGerenciadorGrafico();
            void limpaJanela();
            void fecharJanela();
            void mostrarJanela();
            const bool verificaJanelaAberta() const;
            void desenhaElemento(const sf::Sprite corpo);
            void desenhaBackground(const sf::Sprite background);
            void escreveTexto(sf::Text* texto);
            sf::Font* carregarFonte();
            sf::Texture carregarTextura(const char* caminhoTextura);
    };

   // GerenciadorGrafico* GerenciadorGrafico::pGrafico = 0;
}

