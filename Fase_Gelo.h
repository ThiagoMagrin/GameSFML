#pragma once
#include "Fase.h"
#include "Dragao.h"
#include "Tronco.h"

namespace Fases
{
    class Fase_Gelo : public Fase
    {
    private:
        Dragao *pDragao;
        BolaDeFogo *pBolaDeFogo;
        Tronco *pTronco;

    public:
        Fase_Gelo();
        Fase_Gelo(bool doisJogadores = false);

        ~Fase_Gelo();

        void inicializaSegundoJogador();
        void inicializaObjetos();
        void inicializaBG();
        void executar(int J1pts, int J2pts, int J1vida, int J2vida);
        void executar() {}
        void imprimir(){};

        void criarDragoes();
        void criarTronco();
    };
}
