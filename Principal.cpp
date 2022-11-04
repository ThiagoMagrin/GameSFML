#include "Jogo.h"

Jogo::Jogo() :
    pGrafico(pGrafico->getGerenciadorGrafico()),
    //entidade(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f)),
    //personagem(sf::Vector2f(150.0f, 150.0f), sf::Vector2f(50.0f, 50.0f)),
    jogador(sf::Vector2f(500.0f, 500.0f), sf::Vector2f(50.0f, 50.0f))
    //inimigo(sf::Vector2f(100.0f,100.0f),sf::Vector2f(20.0f,20.0f))*/
{
    //inimigo.setJogador(&jogador);
    executar();
}


Jogo::~Jogo()
{
}

void Jogo::executar()
{

    sf::Event evento;
    while (pGrafico->verificaJanelaAberta())
    {
        while (pGrafico->getWindow()->pollEvent(evento))//SE SE EXISTE UM EVENTO
        {
            if (evento.type == sf::Event::Closed) //SE O EVENTO FOR O CLICK NO BOTAO CLOSE
            {
                //pGrafico->getWindow()->close();
                pGrafico->fecharJanela();
            }
            else if (evento.type == sf::Event::KeyPressed) {
                if (evento.key.code == sf::Keyboard::Escape)
                   // pGrafico->getWindow()->close();
                pGrafico->fecharJanela();
            }

            //pGrafico->getWindow()->clear();
            pGrafico->limpaJanela();
            jogador.movimento();
            //inimigo.movimento();

            //pGrafico->getWindow()->draw(jogador.getCorpo());
            //pGrafico->desenhaElemento(jogador.getCorpo());
            pGrafico->desenhaElemento(jogador.getCorpo());
            pGrafico->desenhaElemento(entidade.getCorpo());
            pGrafico->desenhaElemento(personagem.getCorpo());
            //pGrafico->getWindow()->draw(entidade.getCorpo());
            //pGrafico->getWindow()->draw(personagem.getCorpo());
            // pGrafico->getWindow()->draw(inimigo.getCorpo());
            pGrafico->mostrarJanela();
           // pGrafico->getWindow()->display();//mostra
            //std::cout<<"passou aqui!";
        }

    }
    pGrafico->fecharJanela();

};
