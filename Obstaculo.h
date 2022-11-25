#pragma once
#include "Entidade.h"
#include "Personagem.h"

namespace Entidades{
    namespace Obstaculos{
        class Obstaculo : public Entidade{
        protected:
            int vida, dano;
            bool causaDano;
        public:
            Obstaculo();
            virtual ~Obstaculo();
            virtual void inicializar() = 0;
            virtual void executar() { }
            void setCausaDano(bool b);
            const bool getCausaDano();
        };
    }
}
