#include "Fase.h"
#include "Jogador.h"
#include <time.h>
#include <string>

namespace Fases{
    Fase::Fase() : Ente(0), pFantasma(nullptr), pPedra(nullptr), texturaBG(), background(), pausado(false) {
        sorteiaNumEnt();

        fonte.loadFromFile("times new roman.ttf");
        textoVida.setFont(fonte);
        //textoVida.setColor();
        textoVida.setPosition(0, 0);

        pJogador = new Jogador();
        pPlataforma = new Plataforma({280.0f, 350.0f});

        pListaDinamica = new ListaEntidade();
        pListaEstatica = new ListaEntidade();

        pColisao = new GerenciadorColisao(pListaEstatica, pListaDinamica);

        Entidades::Entidade* jogador = static_cast<Entidades::Entidade*> (pJogador);
        Entidades::Entidade* plataforma = static_cast<Entidades::Entidade*> (pPlataforma);

        pListaDinamica->adicionarEntidade(jogador);
        pListaEstatica->adicionarEntidade(plataforma);

        criarFantasmas();
        criarPedras();
    }

    Fase::~Fase(){}

    void Fase::sorteiaNumEnt(){
        numEnt = rand()%2 + 3;
    }

    void Fase::atualizaTexto(){
        std::string text = "Vida: ";
        text += std::to_string(pJogador->getVida());
        textoVida.setString(text);
    }

    void Fase::criarFantasmas(){
        for (int i = 0; i < numEnt; i++) {
            pFantasma = new Fantasma();

            pFantasma->inicializar(pJogador);
            Entidades::Entidade* fantasma = static_cast<Entidades::Entidade*> (pFantasma);
            pListaDinamica->adicionarEntidade(fantasma);
        }
        std::cout << "FANTASMAS CRIADAS!\n";
    }

    void Fase::criarPedras(){
        for (int i = 0; i < numEnt; i++) {
            pPedra = new Pedra();

            pPedra->inicializar();
            Entidades::Entidade* Pedra = static_cast<Entidades::Entidade*> (pPedra);
            pListaEstatica->adicionarEntidade(Pedra);
        }
        std::cout << "PEDRAS CRIADAS!\n";
    }
}
