#include "Fase2.h"

namespace Fases{
    Fase2::Fase2(): Fase(){
        pInimigo3 = new Inimigo3();

        inicializaObjetos();
    }

    Fase2::~Fase2(){
    }

    void Fase2::inicializaObjetos(){
        pJogador->inicializar();
        pInimigo3->inicializar(pJogador);
        pInimigo2->inicializar(pJogador);

        executar();
    }

    void Fase2::imprimir(){
        pJogador->executar();
        pJogador->imprimir();

        pInimigo3->executar();
        pInimigo3->imprimir();

        pInimigo2->executar();
        pInimigo2->imprimir();
    }

    void Fase2::executar(){
        sf::Event evento;
        bool continuar_jogando = true;

        sf::Texture fundo;
        fundo.loadFromFile("images/fase_dois.png");
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
