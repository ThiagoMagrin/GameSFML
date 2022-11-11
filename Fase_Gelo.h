#pragma once
#include "Fase.h"

namespace Fases{
    class Fase_Gelo : public Fase{
        public:
            Fase_Gelo();
            ~Fase_Gelo();

            void inicializaObjetos();
            void executar();
            void imprimir() {};
    };
}
