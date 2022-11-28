#pragma once

#include "Ente.h"
#include "Fase_Terra.h"
#include "Fase_Gelo.h"
#include "MenuPrincipal.h"
#include "MenuDoisJogadores.h"

#include <string>
using namespace Fases;

class Jogo : public Ente
{
private:
    MenuPrincipal menuP;
    MenuDoisJogadores menuD;
    Fase_Terra *objFase_Terra;
    Fase_Gelo *objFase_Gelo;

    bool dois_jogadores;

public:
    Jogo();
    ~Jogo();

    void executar();
    void executarFase1();
    void executarFase2(int p1 = 0, int p2 = 0, int v1 = 3000, int v2 = 3000);
    void imprimir() {}
    void InformarPontuacao();
};
