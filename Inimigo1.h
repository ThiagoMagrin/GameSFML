#pragma once

#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            class Inimigo1 : public Inimigo {
                public:
                    Inimigo1();
                    ~Inimigo1();

                    void inicializar(Jogador* pJ);
            };
        }
    }
}

