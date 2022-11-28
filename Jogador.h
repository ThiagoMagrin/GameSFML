#pragma once
#include "Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
        private:
            int pontuacao;
            bool segundoJogador;

        public:
            Jogador();
            ~Jogador();

            void setPontuacao(int p);
            const int getPontuacao() const;
            void setSegundoJogador(bool b);
            void operator++();
            void movimento();
            void inicializar(sf::Vector2f pos);
            void executar();
            void tratarColisao(Entidade *outraEntidade);
        };
    }
}
