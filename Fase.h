#pragma once

#include "Jogador.h"
#include "Fantasma.h"
#include "Pedra.h"

#include "Gerenciador_Colisao.h"
#include "ListaEntidades.h"
#include "Plataforma.h"

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
            Plataforma* pPlataforma;
            Fantasma* pFantasma;
            Pedra* pPedra;
            ListaEntidade* pListaDinamica;
            ListaEntidade* pListaEstatica;
            GerenciadorColisao* pColisao;
            sf::Texture texturaBG;
            sf::Sprite background;
            sf::Font fonte;
            sf::Text textoVida;

            int numEnt;

            bool pausado;

        public:
            Fase();
            virtual ~Fase();

            virtual void inicializaObjetos() = 0;
            virtual void executar() = 0;
            virtual void imprimir() = 0;
            void criarFantasmas();
            void criarPedras();
            void sorteiaNumEnt();
            void atualizaTexto();
    };
}
