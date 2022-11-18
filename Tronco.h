#pragma once
#include "Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        class Tronco : public Obstaculo{
        private:
            int apodrecer; // NAO IMPLEMENTADO
        public:
            Tronco();
            ~Tronco();

            void inicializar();
        };
    }
}
