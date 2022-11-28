#pragma once
#include "BolaDeFogo.h"
#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            class Dragao : public Inimigo
            {
            private:
                BolaDeFogo *pBolaDeFogo;
                bool esquerdaB;

            public:
                Dragao();
                ~Dragao();

                void configuraBolaDeFogo(sf::Vector2f posJogador, sf::Vector2f posInimigo);
                void inicializar(Jogador *pJ, Jogador *pJ2, BolaDeFogo *pBola);
                void perseguirJogador();
                void perseguirJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
                void movimento();
                void tratarColisao(Entidade *outraEntidade);
                void movimentoEspecifico();

                BolaDeFogo *getProjetil();
            };
        }
    }
}
