#pragma once
#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Pedra : public Obstaculo
        {
        private:
            bool pontiaguda;

        public:
            Pedra();
            ~Pedra();
            void inicializar();
            void obstacular(Entidade *outraEntidade);
        };
    }
}
