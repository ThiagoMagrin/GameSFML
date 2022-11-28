#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "Entidade.h"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem : public Entidade
        {
        protected:
            sf::Vector2f velocidade;
            bool direita, esquerda;

        public:
            Personagem();
            ~Personagem();

            void setVelocidade(sf::Vector2f vel);
            const sf::Vector2f getVelocidade() const;

            virtual void setPontuacao(int p) {}
            virtual const int getPontuacao() const { return 0; }

            // void setChao(bool b);
            void setDireita(bool b);
            void setEsquerda(bool b);

            void pular(float pulo);

            virtual void tratarColisao(Entidade *outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) {}
            virtual void executar() = 0;
        };
    }
}
