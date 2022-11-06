#include "Fase1.h"

namespace Fases{
    Fase1::Fase1(): Fase(){
        pJogador = new Jogador();
        pInimigo1 = new Inimigo1();
        pInimigo2 = new Inimigo2();

        inicializaObjetos();
    }

    Fase1::~Fase1(){
    }

    void Fase1::inicializaObjetos(){
        pJogador->inicializar();
        pInimigo1->inicializar(pJogador);
        pInimigo2->inicializar(pJogador);

        executar();
    }

    void Fase1::imprimir(){
        pJogador->executar();
        pJogador->imprimir();

        pInimigo1->executar();
        pInimigo1->imprimir();

        pInimigo2->executar();
        pInimigo2->imprimir();
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
                imprimir();
                pGrafico->mostrarJanela();
            }
        }
    }
}
