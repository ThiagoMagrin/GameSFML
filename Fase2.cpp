#include "Fase2.h"

namespace Fases{
    Fase2::Fase2(): Fase(){
        pJogador = new Jogador();
        pInimigo2 = new Inimigo2();
        pInimigo3 = new Inimigo3();

        inicializar();
    }

    Fase2::~Fase2(){
    }

    void Fase2::inicializar(){
        pJogador->inicializar();
        pInimigo2->inicializar(pJogador);
        pInimigo3->inicializar(pJogador);
        executar();
    }

    void Fase2::imprimir(){
    }

    void Fase2::executar(){
        sf::Event evento;

        sf::Texture fundo;
        fundo.loadFromFile("images/fase_dois.png");
        sf::Sprite background(fundo);

        while (pGrafico->verificaJanelaAberta())
        {
            while (pGrafico->getWindow()->pollEvent(evento))
            {
                if (evento.type == sf::Event::Closed){
                    pGrafico->fecharJanela();
                }

                else if (evento.type == sf::Event::KeyPressed) {
                    if (evento.key.code == sf::Keyboard::Escape)
                        pGrafico->fecharJanela();
                }

                pGrafico->limpaJanela();

                pGrafico->desenhaBackground(background);

                pJogador->executar();
                pJogador->imprimir();

                pInimigo2->executar();
                pInimigo2->imprimir();

                pInimigo3->executar();
                pInimigo3->imprimir();

                pGrafico->mostrarJanela();
            }
        }
        pGrafico->fecharJanela();
    }
}
