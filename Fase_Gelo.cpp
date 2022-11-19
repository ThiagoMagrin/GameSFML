#include "Fase_Gelo.h"

namespace Fases{
    Fase_Gelo::Fase_Gelo(): Fase(), pDragao(nullptr), pBolaDeFogo(nullptr){
        inicializaObjetos();
        inicializaBG();
    }

    Fase_Gelo::~Fase_Gelo(){
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

        if(pDragao){
            delete (pDragao);
        }
        pDragao = nullptr;

        if(pBolaDeFogo){
            delete (pBolaDeFogo);
        }
        pBolaDeFogo = nullptr;
    }

    void Fase_Gelo::inicializaBG(){
        texturaBG.loadFromFile("images/fase_dois.png");
        background.setTexture(texturaBG);
    }

    void Fase_Gelo::inicializaObjetos(){
        pJogador->inicializar();
        criarDragoes();
        criarTronco();

        std::cout << "Lista personagens criada, tamanho:" << pListaDinamica->getTamanho() << std::endl;
        std::cout << "Lista obstaculos criada, tamanho:" << pListaEstatica->getTamanho() << std::endl;
    }

    void Fase_Gelo::criarDragoes(){
        for (int i = 0; i < 3; i++) {
            pDragao = new Dragao();
            pBolaDeFogo = new BolaDeFogo();

            pDragao->inicializar(pJogador,pBolaDeFogo);
            pBolaDeFogo->inicializar();

            Entidades::Entidade* chefao = static_cast<Entidades::Entidade*> (pDragao);
            Entidades::Entidade* bolaDeFogo = static_cast<Entidades::Entidade*> (pBolaDeFogo);

            pListaDinamica->adicionarEntidade(chefao);
            pListaDinamica->adicionarEntidade(bolaDeFogo);
        }
        std::cout << "Dragoes CRIADOS!\n";
    }

    void Fase_Gelo::criarTronco(){
        for (int i = 0; i<numEnt; i++) {
            pTronco = new Tronco();

            pTronco->inicializar();
            Entidades::Entidade* Tronco = static_cast<Entidades::Entidade*> (pTronco);
            pListaEstatica->adicionarEntidade(Tronco);
        }
        std::cout << "ESPINHOS CRIADOS!\n";
    }

    void Fase_Gelo::executar(){
        sf::Event evento;
        bool continuarJogando = true;

        while (pGraf->verificaJanelaAberta()){
            while (pGraf->getWindow()->pollEvent(evento) || continuarJogando == true) {
                    if (pJogador->getMorrer() == true) {
                        std::cout << "JOGADOR MORREU! GAME OVER";
                        pGraf->fecharJanela();
                        continuarJogando = false;
                    }

                    if (pListaDinamica->getTodosMortos() == true) {
                        std::cout << "Todos os inimigos estao mortos! Iniciando fase 2";
                        continuarJogando = false;
                    }

                    if (evento.type == sf::Event::Closed) {
                        pGraf->fecharJanela();
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
