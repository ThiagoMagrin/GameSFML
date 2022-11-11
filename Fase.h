#pragma once

#include "Jogador.h"
#include "Esqueleto.h"
#include "Chefao.h"
#include "Aranha.h"
#include "Pedra.h"
#include "Espinho.h"
#include "Tronco.h"
#include "Gerenciador_Colisao.h"
#include "ListaEntidades.h"

using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;
using namespace Obstaculos;
using namespace Listas;
using namespace Gerenciadores;

namespace Fases{
    class Fase: public Ente{
        protected:
            Jogador* pJogador;
            Esqueleto* pEsqueleto;
            Chefao* pChefao;
            Aranha* pAranha;
            Pedra* pPedra;
            Espinho* pEspinho;
            Tronco* pTronco;
            ListaEntidade* pListaDinamica;
            ListaEntidade* pListaEstatica;
            GerenciadorColisao* pColisao;


        public:
            Fase();
            virtual ~Fase();

            virtual void inicializaObjetos() = 0;
            virtual void executar() = 0;
            virtual void imprimir() = 0;
    };
}
