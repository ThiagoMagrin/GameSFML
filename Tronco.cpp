#include "Tronco.h"

#define DANO_TRONCO 0

namespace Entidades
{
    namespace Obstaculos
    {
        Tronco::Tronco() : Obstaculo(), apodrecer(0) {}
        Tronco::~Tronco() {}

        void Tronco::inicializar()
        {
            setDano(DANO_TRONCO);
            apodrecer = rand() % 3 + 1;

            tamanho = sf::Vector2f(70.0f, 15.0f);
            setTamanho(tamanho);
            float posicao_y = posicaoAleatoria(0).y + getTamanho().y;
            posicao = sf::Vector2f(posicaoAleatoria(0).x, posicao_y - 40);
            textura = pGraf->carregarTextura("images/tronco.png");
            corpo.setTexture(textura, true);
            corpo.setPosition(posicao);
        }

        void Tronco::obstacular(Entidade *outraEntidade)
        {
            // cada vez que o tronco encosta no jogador, o jogador tem sua velocidade diminuida ate um certo limite

            if (outraEntidade->getVelocidade().x > 0.3f)
            {
                outraEntidade->setVelocidade({-0.1f * apodrecer, 0.0f});
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
