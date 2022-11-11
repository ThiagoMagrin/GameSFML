#pragma once

#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            class Chefao : public Inimigo {
                public:
                    Chefao();
                    ~Chefao();

                    void inicializar(Jogador* pJ);
            };
        }
    }
}

