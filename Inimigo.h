#pragma once

#include "SFML/Graphics.hpp"
#include "Personagem.h"
#include "Jogador.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            class Inimigo : public Personagem {
                protected:
                    Jogador* pJogador;

                public:
                    Inimigo();
                    Inimigo(Jogador* pJogador);
                    ~Inimigo();

                    void setJogador(Jogador* pJ);

                    void perseguirJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
                    void movimento();
                    void cair();

                    void executar();
            };
        }
    }
}