#pragma once

#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            class Esqueleto : public Inimigo {
            private:
                float decomposicao;
            public:
                Esqueleto();
                ~Esqueleto();

                void inicializar(Jogador* pJ, Jogador* pJ2);
                void executar();
                void apodrecer();
                void movimentoEspecifico();
                void tratarColisao(Entidade* outraEntidade);
            };
        }
    }
}

