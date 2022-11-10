#pragma once
#include <iostream>
#include "Gerenciador_Grafico.h"

using namespace Gerenciadores;

class Ente {
    protected:
        int id;
        GerenciadorGrafico* pGrafico;

    public:
        Ente();
        Ente(int id);
        ~Ente();
        const int getId() const;
        void setId(int i);

        virtual void imprimir() = 0;
};
