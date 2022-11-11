#pragma once
#include "Fase.h"

namespace Fases{
    class Fase_Terra : public Fase{
        public:
            Fase_Terra();
            ~Fase_Terra();

            void inicializaObjetos();
            void executar();
            void imprimir() {};
    };
}
