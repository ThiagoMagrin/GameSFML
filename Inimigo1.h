#pragma once

#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigo {
            class Inimigo1 : public Inimigo {
            public:
                Inimigo1();
                Inimigo1(sf::Vector2f posInicio, Jogador* Jogador);
                ~Inimigo1();

                void inicializar();
                void renderizar();
                void executar();
            };
        }
    }
}

