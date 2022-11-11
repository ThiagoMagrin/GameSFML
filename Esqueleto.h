#pragma once

#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            class Esqueleto : public Inimigo {
                public:
                    Esqueleto();
                    ~Esqueleto();

                    void inicializar(Jogador* pJ);
            };
        }
    }
}

