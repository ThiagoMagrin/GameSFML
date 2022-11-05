#pragma once

#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            class Inimigo2 : public Inimigo {
                public:
                    Inimigo2();
                    ~Inimigo2();

                    void inicializar(Jogador* pJ);
            };
        }
    }
}

