#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"

#define GRAVIDADE 998.f

namespace Entidades {
    class Entidade : public Ente {
        protected:
            sf::Vector2f posicao, velocidade;
            sf::RectangleShape corpo;

            int vida, dano;
        public:
            Entidade();
            virtual ~Entidade();

            void setPosicao(sf::Vector2f pos);
            const sf::Vector2f getPosicao() const;

            void setVelocidade(sf::Vector2f vel);
            const sf::Vector2f getVelocidade() const;

            sf::RectangleShape getCorpo() ;

            void imprimir();

            virtual void executar();

            virtual void setVida(int v) = 0;
            virtual const int getVida() const = 0;

            virtual void setDano(int d) = 0;
            virtual const int getDano() const = 0;
        };
}
