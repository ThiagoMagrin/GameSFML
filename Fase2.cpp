#include "Fase2.h"

namespace Fases{
    Fase2::Fase2(): Fase(){
        pJogador = new Jogador();
        pInimigo2 = new Inimigo2();
        pInimigo3 = new Inimigo3();
        pObstaculo1 = new Obstaculo1();
        pObstaculo3 = new Obstaculo3();

        pListaDinamica = new ListaEntidade();
        pListaEstatica = new ListaEntidade();

        pColisao = new GerenciadorColisao(pListaEstatica, pListaDinamica);

        inicializaObjetos();

        Entidades::Entidade* jogador = static_cast<Entidades::Entidade*> (pJogador);
        Entidades::Entidade* inimigo2 = static_cast<Entidades::Entidade*> (pInimigo2);
        Entidades::Entidade* inimigo3 = static_cast<Entidades::Entidade*> (pInimigo3);
        Entidades::Entidade* obstaculo1 = static_cast<Entidades::Entidade*> (pObstaculo1);
        Entidades::Entidade* obstaculo3 = static_cast<Entidades::Entidade*> (pObstaculo3);

        pListaDinamica->adicionarEntidade(jogador);
        pListaDinamica->adicionarEntidade(inimigo2);
        pListaDinamica->adicionarEntidade(inimigo3);

        pListaEstatica->adicionarEntidade(obstaculo1);
        pListaEstatica->adicionarEntidade(obstaculo3);

        std::cout << "Lista personagens criada, tamanho:" << pListaDinamica->getTamanho() << std::endl;
        std::cout << "Lista obstaculos criada, tamanho:" << pListaEstatica->getTamanho() << std::endl;

        executar();
    }

    Fase2::~Fase2(){}

    void Fase2::inicializaObjetos(){
        pJogador->inicializar();
        pInimigo2->inicializar(pJogador);
        pInimigo3->inicializar(pJogador);
        pObstaculo1->inicializar();
        pObstaculo3->inicializar();
    }

    void Fase2::imprimir(){
        pListaDinamica->executar();
        pListaEstatica->executar();
    }

    void Fase2::executar(){
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
                pColisao->executar();
                imprimir();
                pGrafico->mostrarJanela();
            }
        }
    }
}
