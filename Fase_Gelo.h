#pragma once
#include "Fase.h"
#include "Dragao.h"
#include "Tronco.h"

namespace Fases{
    class Fase_Gelo : public Fase{
        private:
            Dragao* pDragao;
            Tronco* pTronco;
            BolaDeFogo* pBolaDeFogo;

        public:
            Fase_Gelo();
            ~Fase_Gelo();

            void inicializaObjetos();
            void inicializaBG();
            void executar();
            void imprimir() {};

            void criarDragoes();
            void criarTronco();
    };
}
