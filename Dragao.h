#pragma once
#include "BolaDeFogo.h"
#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            class Dragao : public Inimigo {
            private:
                BolaDeFogo* pBolaDeFogo;
                bool esquerdaB;

            public:
                Dragao();
                ~Dragao();

                void inicializar(Jogador* pJ, BolaDeFogo* pBola);
                void perseguirJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
                void movimento();
            };
        }
    }
}

