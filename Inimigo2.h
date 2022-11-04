#pragma once

#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigo {
            class Inimigo2 : public Inimigo {
            public:
                Inimigo2();
                Inimigo2(sf::Vector2f posInicio, Jogador* Jogador);
                ~Inimigo2();

                void inicializar();
                void renderizar();
                void executar();
            };
        }
    }
}
