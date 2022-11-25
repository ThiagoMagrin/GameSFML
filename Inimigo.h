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
                    Jogador* pJogador2;

                public:
                    Inimigo();
                    Inimigo(Jogador* pJogador);
                    Inimigo(Jogador* pJogador, Jogador* pJogador2);
                    ~Inimigo();

                    void setJogador(Jogador* pJ, Jogador* pJ2);

                    void perseguirJogador();
                    void perseguirJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
                    virtual void movimento();
                    virtual void movimentoEspecifico();
                    void tratarColisao(Entidade* outraEntidade);
                    void executar();
            };
        }
    }
}
