#include "Fase_Gelo.h"

namespace Fases{
    Fase_Gelo::Fase_Gelo(): Fase(){
        pJogador = new Jogador();
        pChefao = new Chefao();
        pAranha = new Aranha();
        pPedra = new Pedra();
        pTronco = new Tronco();

        pListaDinamica = new ListaEntidade();
        pListaEstatica = new ListaEntidade();

        pColisao = new GerenciadorColisao(pListaEstatica, pListaDinamica);

        inicializaObjetos();

        Entidades::Entidade* jogador = static_cast<Entidades::Entidade*> (pJogador);
        Entidades::Entidade* Chefao = static_cast<Entidades::Entidade*> (pChefao);
        Entidades::Entidade* Aranha = static_cast<Entidades::Entidade*> (pAranha);
        Entidades::Entidade* Pedra = static_cast<Entidades::Entidade*> (pPedra);
        Entidades::Entidade* Tronco = static_cast<Entidades::Entidade*> (pTronco);

        pListaDinamica->adicionarEntidade(jogador);
        pListaDinamica->adicionarEntidade(Chefao);
        pListaDinamica->adicionarEntidade(Aranha);

        pListaEstatica->adicionarEntidade(Pedra);
        pListaEstatica->adicionarEntidade(Tronco);

        std::cout << "Lista personagens criada, tamanho:" << pListaDinamica->getTamanho() << std::endl;
        std::cout << "Lista obstaculos criada, tamanho:" << pListaEstatica->getTamanho() << std::endl;

        executar();
    }

    Fase_Gelo::~Fase_Gelo(){}

    void Fase_Gelo::inicializaObjetos(){
        pJogador->inicializar();
        pChefao->inicializar(pJogador);
        pAranha->inicializar(pJogador);
        pPedra->inicializar();
        pTronco->inicializar();
    }

    void Fase_Gelo::executar(){
        sf::Event evento;
        sf::Texture fundo;
        fundo.loadFromFile("images/fase_dois.png");
        sf::Sprite background(fundo);

        while (pGrafico->verificaJanelaAberta()){
            while (pGrafico->getWindow()->pollEvent(evento)){
                if (evento.type == sf::Event::Closed){
                    pGrafico->fecharJanela();
                }

                else if (evento.type == sf::Event::KeyPressed) {
                    if (evento.key.code == sf::Keyboard::Escape){
                        pGrafico->fecharJanela();
                    }
                }

                pGrafico->limpaJanela();
                pGrafico->desenhaBackground(background);
                pListaEstatica->executar();
                pListaDinamica->executar();
                pColisao->executar();
                pGrafico->mostrarJanela();
            }
        }
    }
}
