#pragma once
#include "Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        class Tronco : public Obstaculo{
        public:
            Tronco();
            ~Tronco();

            void inicializar();
        };
    }
}
