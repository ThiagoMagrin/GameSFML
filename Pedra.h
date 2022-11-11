#pragma once
#include "Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        class Pedra : public Obstaculo{
        public:
            Pedra();
            ~Pedra();

            void inicializar();
        };
    }
}
