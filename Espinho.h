#pragma once
#include "Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        class Espinho : public Obstaculo{
        private:
            int forcaEspinhos;
        public:
            Espinho();
            ~Espinho();

            void inicializar();
        };
    }
}
