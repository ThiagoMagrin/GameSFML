#pragma once

#include "Jogador.h"
#include "Inimigo1.h"
#include "Inimigo2.h"
#include "Inimigo3.h"

using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

namespace Fases{
    class Fase: public Ente{
        protected:
            Jogador* pJogador;
            Inimigo1* pInimigo1;
            Inimigo2* pInimigo2;
            Inimigo3* pInimigo3;

        public:
            Fase();
            virtual ~Fase();

            virtual void inicializaObjetos() = 0;
            virtual void executar() = 0;
            virtual void imprimir() = 0;
    };
}
