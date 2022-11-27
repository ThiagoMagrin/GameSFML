#pragma once

#include "Jogador.h"
#include "Fantasma.h"
#include "Pedra.h"

#include "Gerenciador_Colisao.h"
#include "ListaEntidades.h"
#include "Plataforma.h"

#include <string>
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
            Jogador* pJogador2;
            Plataforma* pPlataforma;
            Fantasma* pFantasma;
            Pedra* pPedra;
            ListaEntidade* pListaDinamica;
            ListaEntidade* pListaEstatica;
            GerenciadorColisao* pColisao;
            sf::Texture texturaBG;
            sf::Sprite background;
            sf::Font fonte;
            sf::Text textoVida, textoVida2, textoPause;

            int numEnt;

            bool pausado, doisJogadores;
        public:
            Fase(bool doisjogadores);
            virtual ~Fase();

            virtual void inicializaObjetos() = 0;
            virtual void executar() = 0;
            virtual void imprimir() = 0;
            void criarFantasmas();
            void criarPedras();
            void sorteiaNumEnt();
            void atualizaTexto();

            const bool getSobreviveram(){
                return pListaDinamica->getTodosMortos();
            }

            Jogador getJogador(){ return *pJogador; }
            Jogador getJogador2() { return *pJogador2; }


            void GravarPontuacao(int pts = 0);

            void setdoisJogadores(bool j) { doisJogadores = j; }
            const bool getdoisJogadores() { return doisJogadores; }

            void criarJogador2();

    };
}
