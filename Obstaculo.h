#pragma once
#include "Entidade.h"

namespace Entidades{
    namespace Obstaculos{
        class Obstaculo : public Entidade{
        public:
            Obstaculo();
            virtual ~Obstaculo();
            virtual void inicializar() = 0;
        };
    }
}
