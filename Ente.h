#pragma once
#include <iostream>

#include "Gerenciador_Grafico.h"
using namespace Gerenciadores;

// Cada elemento possui um ID
// Vazio = 0
// Jogador = 1
// Inimigo = 2
// Obstaculo = 3
// Plataforma = 4
// Projetil = 5

class Ente {
    protected:
        int id;
        static GerenciadorGrafico* pGraf;

    public:
        Ente(int id = 0);
        ~Ente();

        const int getId() const;
        void setID(const int i);

        static void setGraf(GerenciadorGrafico* pGg);

        //virtual void imprimir() {}
};


