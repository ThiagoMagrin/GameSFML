#pragma once
#include "Fase.h"
#include "Esqueleto.h"
#include "Espinho.h"

namespace Fases{
    class Fase_Terra : public Fase{
    private:
        Esqueleto* pEsqueleto;
        Espinho* pEspinho;

    public:
        Fase_Terra(bool doisJogadores = false);
        ~Fase_Terra();

        void inicializaBG();
        void inicializaObjetos();
        void executar();
        void imprimir() {};

        void criarEsqueletos();
        void criarEspinhos();
    };
}
