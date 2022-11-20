#pragma once

#include "Ente.h"
#include "Fase_Terra.h"
#include "Fase_Gelo.h"

using namespace Fases;

class Jogo : public Ente {
    private:
        Fase_Terra* objFase_Terra;
        Fase_Gelo* objFase_Gelo;

    public:
        Jogo();
        ~Jogo();

      //  void executar();
        void executarFase1();
        void executarFase2();

        void imprimir() {}
};
