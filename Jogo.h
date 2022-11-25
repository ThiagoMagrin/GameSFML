#pragma once

#include "Ente.h"
#include "Fase_Terra.h"
#include "Fase_Gelo.h"
#include "Menu.h"

#include <string>
using namespace Fases;

class Jogo : public Ente {
    private:
        Menu menu;
        Fase_Terra* objFase_Terra;
        Fase_Gelo* objFase_Gelo;

        bool dois_jogadores;

    public:
        Jogo();
        ~Jogo();

        void executar();
        void executarFase1(bool doisJ = false);
        void executarFase2(bool doisJ = false, int p1 = 0, int p2 = 0);

        void imprimir() {}

        void InformarPontuacao();
};
