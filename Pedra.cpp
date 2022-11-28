#include "Pedra.h"

#define DANO_PEDRA 1

namespace Entidades
{
    namespace Obstaculos
    {
        Pedra::Pedra() : Obstaculo(), pontiaguda(false)
        {
        }
        Pedra::~Pedra() {}

        void Pedra::inicializar()
        {
            if (rand() % 2 == 1)
            {
                pontiaguda = true;
            }

            if (pontiaguda == true)
            {
                tamanho = sf::Vector2f(70.0f, 20.0f);
                causaDano = true;
                setDano(DANO_PEDRA);
                textura = pGraf->carregarTextura("images/pedraPontiaguda.png");
            }
            else
            {
                causaDano = false;
                tamanho = sf::Vector2f(70.0f, 40.0f);
                setDano(0);
                textura = pGraf->carregarTextura("images/pedra.png");
            }

            setTamanho(tamanho);
            float posicao_y = posicaoAleatoria(0).y + getTamanho().y;
            posicao = sf::Vector2f(posicaoAleatoria(0).x, posicao_y);
            corpo.setTexture(textura, true);
            corpo.setPosition(posicao);
        }

        void Pedra::obstacular(Entidade *outraEntidade)
        {
            if (!causaDano)
            {
                if (outraEntidade->getVelocidade().x < 1)
                {
                    outraEntidade->setVelocidade({0.1f, 0});
                }
            }

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
