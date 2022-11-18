#pragma once

#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            class Fantasma : public Inimigo {
            private:
                bool lado;
                int assombracao;
            public:
                Fantasma();
                ~Fantasma();

                void inicializar(Jogador* pJ);
                //void movimentoEspecifico();
            };
        }
    }
}
