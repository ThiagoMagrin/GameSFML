#include "Fase_Terra.h"

namespace Fases{
    Fase_Terra::Fase_Terra(): Fase(), pEsqueleto(nullptr){
        inicializaBG();
        inicializaObjetos();
    }

    Fase_Terra::~Fase_Terra(){
        if(pJogador){
            delete (pJogador);
        }
        pJogador = nullptr;

        if(pPlataforma){
            delete (pPlataforma);
        }
        pPlataforma = nullptr;

        if(pFantasma){
            delete (pFantasma);
        }
        pFantasma = nullptr;

        if(pListaDinamica){
            delete (pListaDinamica);
        }
        pListaDinamica = nullptr;

        if(pListaEstatica){
            delete (pListaEstatica);
        }
        pListaEstatica = nullptr;

        if(pColisao){
            delete (pColisao);
        }
        pColisao = nullptr;

        if(pEsqueleto){
            delete (pEsqueleto);
        }
        pEsqueleto = nullptr;
    }

    void Fase_Terra::inicializaBG(){
        texturaBG.loadFromFile("images/fase_um.png");
        background.setTexture(texturaBG);
    }

    void Fase_Terra::inicializaObjetos(){
        pJogador->inicializar();
        criarEsqueletos();
        criarEspinhos();

        std::cout << "Lista personagens criada, tamanho:" << pListaDinamica->getTamanho() << std::endl;
        std::cout << "Lista obstaculos criada, tamanho:" << pListaEstatica->getTamanho() << std::endl;
    }

    void Fase_Terra::criarEsqueletos()
    {
        for (int i = 0; i < numEnt; i++) {
            pEsqueleto = new Esqueleto();

            pEsqueleto->inicializar(pJogador);
            Entidades::Entidade* Esqueleto = static_cast<Entidades::Entidade*> (pEsqueleto);
            pListaDinamica->adicionarEntidade(Esqueleto);
        }
        std::cout << "ESQUELETOS CRIADOS!\n";
    }

    void Fase_Terra::criarEspinhos(){
        for (int i = 0; i < numEnt; i++) {
            pEspinho = new Espinho();

            pEspinho->inicializar();
            Entidades::Entidade* Espinho = static_cast<Entidades::Entidade*> (pEspinho);
            pListaEstatica->adicionarEntidade(Espinho);
        }
        std::cout << "ESPINHOS CRIADOS!\n";
    }

    void Fase_Terra::executar(){
        sf::Event evento;
        bool continuarJogando = true;

        while (pGraf->verificaJanelaAberta() && continuarJogando){
            while (pGraf->getWindow()->pollEvent(evento) || continuarJogando ){
                if(pJogador->getMorrer() == true){
                    std::cout << "JOGADOR MORREU! GAME OVER\n\n";
                    continuarJogando = false;
                }

                if (pListaDinamica->getTodosMortos() == true) {
                    std::cout << "Todos os inimigos estao mortos! Iniciando fase 2\n\n";
                    continuarJogando = false;
                }

                if (evento.type == sf::Event::Closed  ){
                    continuarJogando = false;
                }

                pGraf->limpaJanela();
                pGraf->desenhaBackground(background);
                atualizaTexto();
                pGraf->escreveTexto(&textoVida);
                pListaEstatica->executar();
                pListaDinamica->executar();
                pColisao->executar();
                pGraf->mostrarJanela();
            }
        }
    }
}
