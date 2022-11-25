#pragma once

#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            class Fantasma : public Inimigo {
            private:
                int assombracao;
            public:
                Fantasma();
                ~Fantasma();

                void inicializar(Jogador* pJ, Jogador* pJ2);
                //void movimentoEspecifico();
            };
        }
    }
}
