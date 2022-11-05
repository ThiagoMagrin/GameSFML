#pragma once
#include <iostream>
#include "Gerenciador_Grafico.h"

class Ente {
    protected:
        int id;
        GerenciadorGrafico* pGrafico;

    public:
        Ente();
        Ente(int id);
        ~Ente();

        virtual void imprimir() = 0;
};
