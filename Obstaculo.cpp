#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo() : Entidade(), causaDano(false)
        {
            setID(3);
            chao = false;
        }
        Obstaculo::~Obstaculo() {}
        void Obstaculo::setCausaDano(bool b)
        {
            causaDano = b;
        }
        const bool Obstaculo::getCausaDano()
        {
            return causaDano;
        }

        void Obstaculo::tratarColisao(Entidade *outraEntidade)
        {
            if (outraEntidade->getId() == 1)
            {
                if (!outraEntidade->getMorreu())
                {
                    if (causaDano)
                    {
                        danar(outraEntidade);
                    }
                    obstacular(outraEntidade);
                }
            }
            else
            {
                if (outraEntidade->getId() == 4)
                {
                    // std::cout << "\n COLISAO COM A PLATAFORMA!"<< outraEntidade->getId();
                    if (outraEntidade->getPosicao().y > posicao.y)
                    {
                        chao = true;
                    }
                    else
                    {
                        chao = false;
                    }
                }
            }
        }

        void Obstaculo::executar()
        {
            posicao = corpo.getPosition();
            if ((posicao.y >= 550.0f))
            {
                chao = true;
            }

            if (chao == false)
            {
                cair(0.07f);
            }
        }
    }
}
