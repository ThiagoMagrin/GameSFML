#pragma once

#include "SFML/Graphics.hpp"
#include "Personagem.h"
#include "Jogador.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigo {
            class Inimigo : public Personagem {
                protected:
                    Jogador* pJogador;
                    const sf::Vector2f distanciaJogador;

                public:
                    Inimigo();
                    Inimigo(Jogador* pJogador, sf::Vector2f distanciaJogador);
                    ~Inimigo();

                    void setJogador(Jogador* pJ);
                    void perseguirJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
                    virtual void atualizar();
            };
        }
    }
}
