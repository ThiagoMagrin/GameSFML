#include "Fase_Gelo.h"
#include "Jogo.h"

namespace Fases{
    Fase_Gelo::Fase_Gelo(bool doisJogadores): Fase(doisJogadores), pDragao(nullptr), pBolaDeFogo(nullptr){
        inicializaObjetos();
        inicializaBG();
    }

    Fase_Gelo::~Fase_Gelo(){
        if(pJogador){
            delete (pJogador);
        }
        pJogador = nullptr;

        if (pJogador2) {
            delete (pJogador2);
        }
        pJogador2 = nullptr;

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
        pJogador->inicializar({20.0f, 490.0f});

        criarDragoes();
        criarTronco();

        std::cout << "Lista personagens criada, tamanho:" << pListaDinamica->getTamanho() << std::endl;
        std::cout << "Lista obstaculos criada, tamanho:" << pListaEstatica->getTamanho() << std::endl;
    }

    void Fase_Gelo::criarDragoes(){
        for (int i = 0; i < 3; i++) {
            pDragao = new Dragao();
            pBolaDeFogo = new BolaDeFogo();

            pDragao->inicializar(pJogador, pJogador2, pBolaDeFogo);
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

    void Fase_Gelo::executar(int J1pts, int J2pts){
        sf::Event evento;
        bool continuarJogando = true;
        bool press = false;

        pJogador->setPontuacao(J1pts);
        if(pJogador2 != nullptr){
            pJogador2->setPontuacao(J2pts);
        }

        while (pGraf->verificaJanelaAberta() && continuarJogando == true){
            while (pGraf->getWindow()->pollEvent(evento) || continuarJogando == true) {
                if (evento.type == sf::Event::Closed) {
                    pGraf->fecharJanela();
                    continuarJogando = false;
                }

                if(pJogador->getMorrer() == true){
                    if(pJogador2 != nullptr){
                        if(pJogador2->getMorrer() == true){
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
                    std::cout << "Todos os inimigos estao mortos! \nPARABENS!" << std::endl;

                    continuarJogando = false;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && press == false){
                    press = true;
                    if (pausado == false) {
                        pausado = true;

                        for (int a = 0; a < 60000; a++)
                            for (int b = 0; b < 1000; b++);

                        std::cout << "PAUSAR" << std::endl;
                    }
                    else{
                        pausado = false;

                        for (int a = 0; a < 60000; a++)
                            for (int b = 0; b < 1000; b++);

                        std::cout << "VOLTAR" << std::endl;
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
                    textoPause.setPosition(500, 300);

                    pGraf->escreveTexto(&textoPause);
                    pGraf->mostrarJanela();
                   // GravarPontuacao();
                }
            }
        }

        std::cout << "PONTUACAO J1: " << pJogador->getPontuacao() << std::endl;

        if (pJogador2 != nullptr) {
            std::cout << "PONTUACAO J2: " << pJogador2->getPontuacao() << std::endl;
        }
    }
}
