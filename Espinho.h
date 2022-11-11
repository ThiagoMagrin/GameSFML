#pragma once
#include "Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        class Espinho : public Obstaculo{
        public:
            Espinho();
            ~Espinho();

            void inicializar();
        };
    }
}
