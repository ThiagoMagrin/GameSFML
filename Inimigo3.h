#pragma once

#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            class Inimigo3 : public Inimigo {
                public:
                    Inimigo3();
                    ~Inimigo3();

                    void inicializar(Jogador* pJ);
            };
        }
    }
}

