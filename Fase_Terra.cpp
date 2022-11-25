#include "Fase_Terra.h"
#include <iostream>

using namespace std;

namespace Fases {
    Fase_Terra::Fase_Terra(bool doisJogadores) : Fase(doisJogadores), pEsqueleto(nullptr) {
        inicializaBG();
        
        inicializaObjetos();
    }

    Fase_Terra::~Fase_Terra() {
        if (pJogador) {
            delete (pJogador);
        }
        pJogador = nullptr;

        if (pJogador2) {
            delete (pJogador2);
        }
        pJogador2 = nullptr;

        if (pPlataforma) {
            delete (pPlataforma);
        }
        pPlataforma = nullptr;

        if (pFantasma) {
            delete (pFantasma);
        }
        pFantasma = nullptr;

        if (pListaDinamica) {
            delete (pListaDinamica);
        }
        pListaDinamica = nullptr;

        if (pListaEstatica) {
            delete (pListaEstatica);
        }
        pListaEstatica = nullptr;

        if (pColisao) {
            delete (pColisao);
        }
        pColisao = nullptr;

        if (pEsqueleto) {
            delete (pEsqueleto);
        }
        pEsqueleto = nullptr;
    }

    void Fase_Terra::inicializaBG() {
        texturaBG.loadFromFile("images/fase_um.png");
        background.setTexture(texturaBG);
    }

    void Fase_Terra::inicializaObjetos() {
        pJogador->inicializar({20.0f, 490.0f});

        criarEsqueletos();
        criarEspinhos();

        std::cout << "Lista personagens criada, tamanho:" << pListaDinamica->getTamanho() << std::endl;
        std::cout << "Lista obstaculos criada, tamanho:" << pListaEstatica->getTamanho() << std::endl;
    }

    void Fase_Terra::criarEsqueletos()
    {
        for (int i = 0; i < numEnt; i++) {
            pEsqueleto = new Esqueleto();

            pEsqueleto->inicializar(pJogador, pJogador2);
            Entidades::Entidade* Esqueleto = static_cast<Entidades::Entidade*> (pEsqueleto);
            pListaDinamica->adicionarEntidade(Esqueleto);
        }
        std::cout << "ESQUELETOS CRIADOS!\n";
    }

    void Fase_Terra::criarEspinhos() {
        for (int i = 0; i < numEnt; i++) {
            pEspinho = new Espinho();

            pEspinho->inicializar();
            Entidades::Entidade* Espinho = static_cast<Entidades::Entidade*> (pEspinho);
            pListaEstatica->adicionarEntidade(Espinho);
        }
        std::cout << "ESPINHOS CRIADOS!\n";
    }

    void Fase_Terra::executar() {
        sf::Event evento;
        bool continuarJogando = true;
        bool press = false;

        while (pGraf->verificaJanelaAberta() && continuarJogando) {
            while (pGraf->getWindow()->pollEvent(evento) || continuarJogando) {
                if (evento.type == sf::Event::Closed) {
                    continuarJogando = false;
                }

                if (pJogador->getMorrer() == true) {
                    if (pJogador2 != nullptr) {
                        if (pJogador2->getMorrer() == true) {
                            std::cout << "JOGADORES MORRERAM! GAME OVER\n\n";
                            continuarJogando = false;
                        }
                    }
                    else{
                        std::cout << "JOGADOR MORREU! GAME OVER\n\n";
                        continuarJogando = false;
                    }
                }

                if (pListaDinamica->getTodosMortos() == true) {
                    std::cout << "Todos os inimigos estao mortos! Iniciando fase 2\n\n";

                    continuarJogando = false;
                }


                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && press == false){
                    press = true;
                    if (pausado == false) {
                        pausado = true;

                        for (int a = 0; a < 60000; a++)
                            for (int b = 0; b < 1000; b++);

                        std::cout << "PAUSAR";
                    }
                    else{
                        pausado = false;

                        for (int a = 0; a < 60000; a++)
                            for (int b = 0; b < 1000; b++);

                        std::cout << "VOLTAR";
                    }
                    press = false;
                }

                if (pausado == false) {
                    pGraf->limpaJanela();
                    pGraf->desenhaBackground(background);
                    atualizaTexto();
                    pGraf->escreveTexto(&textoVida);
                    pGraf->escreveTexto(&textoVida2);
                    pListaEstatica->executar();
                    pListaDinamica->executar();
                    pColisao->executar();
                    pGraf->mostrarJanela();
                }

                else{
                    std::string text;
                    text = "PAUSE";
                    pGraf->limpaJanela();
                    pGraf->desenhaBackground(background);
                    textoPause.setString(text);
                    textoPause.setPosition(500,300);
                    
                    pGraf->escreveTexto(&textoPause);
                    pGraf->mostrarJanela();

                   // GravarPontuacao();
                }
            }
        }
    }
}
