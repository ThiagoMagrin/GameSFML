#pragma once

#include "Fase1.h"
#include "Fase2.h"

using namespace Fases;

class Jogo : public Ente {
    private:
        Fase1 objFase1;
        Fase2 objFase2;

    public:
        Jogo();
        ~Jogo();
        void executar();
        void imprimir();
};
