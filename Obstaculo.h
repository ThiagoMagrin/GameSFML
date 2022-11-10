#pragma once
#include "Entidade.h"

namespace Entidades{
    namespace Obstaculos{
        class Obstaculo : public Entidade{
        public:
            Obstaculo();
            virtual ~Obstaculo();
            virtual void inicializar() = 0;
            virtual void executar() { }

            virtual void setVida(int v);
            virtual const int getVida() const;

            virtual void setDano(int d);
            virtual const int getDano() const;
        };
    }
}
