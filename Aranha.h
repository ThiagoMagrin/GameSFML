#pragma once

#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            class Aranha : public Inimigo {
                public:
                    Aranha();
                    ~Aranha();

                    void inicializar(Jogador* pJ);
            };
        }
    }
}