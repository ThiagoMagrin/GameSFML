#pragma once
#include "Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        class Pedra : public Obstaculo{
        private:
            bool ponteaguda;
        public:
            Pedra();
            ~Pedra();

            void inicializar();
        };
    }
}
