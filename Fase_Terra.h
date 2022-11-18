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
        Fase_Terra();
        ~Fase_Terra();

        void setNumEnts();

        void inicializaBG();
        void inicializaObjetos();
        void executar();
        void imprimir() {};

        void criarEsqueletos();
        void criarEspinhos();
    };
}
