#pragma once

#include <iostream>
#include "Ente.h"
#include "Entidade.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Inimigo1.h"
#include "Inimigo2.h"

using namespace std;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigo;

class Jogo : public Ente {
    private:
        GerenciadorGrafico* pGrafico;
        Jogador jogador;
        Inimigo1 inimigo1;
        Inimigo2 inimigo2;

    public:
        Jogo();
        ~Jogo();
        void executar();
};
