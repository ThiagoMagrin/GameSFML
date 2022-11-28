#pragma once
#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Tronco : public Obstaculo
        {
        private:
            int apodrecer;

        public:
            Tronco();
            ~Tronco();

            void inicializar();
            void obstacular(Entidade *outraEntidade);
        };
    }
}
