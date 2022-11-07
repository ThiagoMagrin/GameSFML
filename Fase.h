#pragma once

#include "Jogador.h"
#include "Inimigo1.h"
#include "Inimigo2.h"
#include "Inimigo3.h"
#include "Obstaculo1.h"
#include "Obstaculo2.h"
#include "Obstaculo3.h"

using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;
using namespace Obstaculos;

namespace Fases{
    class Fase: public Ente{
        protected:
            Jogador* pJogador;
            Inimigo1* pInimigo1;
            Inimigo2* pInimigo2;
            Inimigo3* pInimigo3;
            Obstaculo1* pObstaculo1;
            Obstaculo2* pObstaculo2;
            Obstaculo3* pObstaculo3;

        public:
            Fase();
            virtual ~Fase();

            virtual void inicializaObjetos() = 0;
            virtual void executar() = 0;
            virtual void imprimir() = 0;
    };
}
