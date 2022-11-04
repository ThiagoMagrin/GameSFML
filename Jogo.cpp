#include "Jogo.h"


Jogo::Jogo() :
    pGrafico(pGrafico->getGerenciadorGrafico()),
    jogador(sf::Vector2f(200.0f, 500.0f), sf::Vector2f(50.0f, 70.0f)),
    inimigo1(sf::Vector2f(400.0f, 500.0f), &jogador),
    inimigo2(sf::Vector2f(700.0f, 540.0f), &jogador)
{
    executar();
}

Jogo::~Jogo(){
}

void Jogo::executar(){
    sf::Event evento;
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
            jogador.atualizar();
            inimigo1.atualizar();
            inimigo2.atualizar();

            pGrafico->desenhaElemento(inimigo1.getCorpo());
            pGrafico->desenhaElemento(inimigo2.getCorpo());
            pGrafico->desenhaElemento(jogador.getCorpo());

            pGrafico->mostrarJanela();
        }

    }
    pGrafico->fecharJanela();
};
