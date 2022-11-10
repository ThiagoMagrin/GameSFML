#include "Fase1.h"

namespace Fases{
    Fase1::Fase1(): Fase(){
        pJogador = new Jogador();
        pInimigo1 = new Inimigo1();
        pInimigo2 = new Inimigo2();
        pObstaculo1 = new Obstaculo1();
        pObstaculo2 = new Obstaculo2();

        pListaDinamica = new ListaEntidade();
        pListaEstatica = new ListaEntidade();

        pColisao = new GerenciadorColisao(pListaEstatica, pListaDinamica);

        inicializaObjetos();

        Entidades::Entidade* jogador = static_cast<Entidades::Entidade*> (pJogador);
        Entidades::Entidade* inimigo1 = static_cast<Entidades::Entidade*> (pInimigo1);
        Entidades::Entidade* inimigo2 = static_cast<Entidades::Entidade*> (pInimigo2);
        Entidades::Entidade* obstaculo1 = static_cast<Entidades::Entidade*> (pObstaculo1);
        Entidades::Entidade* obstaculo2 = static_cast<Entidades::Entidade*> (pObstaculo2);

        pListaDinamica->adicionarEntidade(jogador);
        pListaDinamica->adicionarEntidade(inimigo1);
        pListaDinamica->adicionarEntidade(inimigo2);

        pListaEstatica->adicionarEntidade(obstaculo1);
        pListaEstatica->adicionarEntidade(obstaculo2);

        std::cout << "Lista personagens criada, tamanho:" << pListaDinamica->getTamanho() << std::endl;
        std::cout << "Lista obstaculos criada, tamanho:" << pListaEstatica->getTamanho() << std::endl;

        executar();
    }

    Fase1::~Fase1(){}

    void Fase1::inicializaObjetos(){
        pJogador->inicializar();
        pInimigo1->inicializar(pJogador);
        pInimigo2->inicializar(pJogador);
        pObstaculo1->inicializar();
        pObstaculo2->inicializar();
    }

    void Fase1::imprimir(){
        pListaDinamica->executar();
        pListaEstatica->executar();
    }

    void Fase1::executar(){
        sf::Event evento;
        bool continuar_jogando = true;

        sf::Texture fundo;
        fundo.loadFromFile("images/fase_um.png");
        sf::Sprite background(fundo);

        while (pGrafico->verificaJanelaAberta() && continuar_jogando == true){
            while (pGrafico->getWindow()->pollEvent(evento)){
                if (evento.type == sf::Event::Closed){
                    continuar_jogando = false;
                }

                else if (evento.type == sf::Event::KeyPressed) {
                    if (evento.key.code == sf::Keyboard::Escape){
                        continuar_jogando = false;
                    }
                }

                pGrafico->limpaJanela();
                pGrafico->desenhaBackground(background);
                pColisao->executar();
                imprimir();
                pGrafico->mostrarJanela();
            }
        }
    }
}
