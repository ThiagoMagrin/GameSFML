#include "Fase_Terra.h"

namespace Fases{
    Fase_Terra::Fase_Terra(): Fase(){
        pJogador = new Jogador();
        pEsqueleto = new Esqueleto();
        pChefao = new Chefao();
        pPedra = new Pedra();
        pEspinho = new Espinho();

        pListaDinamica = new ListaEntidade();
        pListaEstatica = new ListaEntidade();

        pColisao = new GerenciadorColisao(pListaEstatica, pListaDinamica);

        inicializaObjetos();

        Entidades::Entidade* jogador = static_cast<Entidades::Entidade*> (pJogador);
        Entidades::Entidade* Esqueleto = static_cast<Entidades::Entidade*> (pEsqueleto);
        Entidades::Entidade* Chefao = static_cast<Entidades::Entidade*> (pChefao);
        Entidades::Entidade* Pedra = static_cast<Entidades::Entidade*> (pPedra);
        Entidades::Entidade* Espinho = static_cast<Entidades::Entidade*> (pEspinho);

        pListaDinamica->adicionarEntidade(jogador);
        pListaDinamica->adicionarEntidade(Esqueleto);
        pListaDinamica->adicionarEntidade(Chefao);

        pListaEstatica->adicionarEntidade(Pedra);
        pListaEstatica->adicionarEntidade(Espinho);

        std::cout << "Lista personagens criada, tamanho:" << pListaDinamica->getTamanho() << std::endl;
        std::cout << "Lista obstaculos criada, tamanho:" << pListaEstatica->getTamanho() << std::endl;

        executar();
    }

    Fase_Terra::~Fase_Terra(){}

    void Fase_Terra::inicializaObjetos(){
        pJogador->inicializar();
        pEsqueleto->inicializar(pJogador);
        pChefao->inicializar(pJogador);
        pPedra->inicializar();
        pEspinho->inicializar();
    }

    void Fase_Terra::executar(){
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
                pListaEstatica->executar();
                pListaDinamica->executar();
                pColisao->executar();
                pGrafico->mostrarJanela();
            }
        }
    }
}
