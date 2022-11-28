#include "Espinho.h"

#define DANO_ESPINHO 1

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho() : Obstaculo(), forcaEspinhos(0) {}
        Espinho::~Espinho() {}

        void Espinho::inicializar()
        {
            setCausaDano(true);

            forcaEspinhos = rand() % 4;
            setDano(DANO_ESPINHO + forcaEspinhos);
            tamanho = sf::Vector2f(70.0f, 15.0f);
            setTamanho(tamanho);
            float posicao_y = posicaoAleatoria(0).y + getTamanho().y;
            posicao = sf::Vector2f(posicaoAleatoria(0).x, posicao_y);
            textura = pGraf->carregarTextura("images/Espinho.png");
            corpo.setTexture(textura, true);
            corpo.setPosition(posicao);
        }

        void Espinho::obstacular(Entidade *outraEntidade)
        {
            if (outraEntidade->getPosicao().x < posicao.x)
            {
                outraEntidade->setDireita(false);
            }
            else if (outraEntidade->getPosicao().x > posicao.x)
            {
                outraEntidade->setEsquerda(false);
            }
            else
            {
                outraEntidade->setDireita(true);
                outraEntidade->setEsquerda(true);
            }

            if (getPosicao().y - 110 > outraEntidade->getPosicao().y)
            {
                outraEntidade->setDireita(true);
                outraEntidade->setEsquerda(true);
                outraEntidade->setChao(true);
            }
        }
    }
}
