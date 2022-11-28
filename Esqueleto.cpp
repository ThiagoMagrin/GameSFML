#include "Esqueleto.h"

#define VIDA_ESQUELETO 100
#define DANO_ESQUELETO 10
#define VEL_ESQUELETO 0.05
namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            Esqueleto::Esqueleto() : Inimigo(nullptr), decomposicao(0) {}
            Esqueleto::~Esqueleto() {}

            void Esqueleto::inicializar(Jogador *pJ, Jogador *pJ2)
            {
                setJogador(pJ, pJ2);
                decomposicao = 0; // rand() % 4; // 0-3
                setVida(VIDA_ESQUELETO);
                setDano(DANO_ESQUELETO - decomposicao);
                posicao = sf::Vector2f(posicaoAleatoria(1));
                setVelocidade({VEL_ESQUELETO, VEL_ESQUELETO});
                textura = pGraf->carregarTextura("images/Esqueleto.png");
                corpo.setTexture(textura, true);
                corpo.setPosition(posicao);
            }

            void Esqueleto::executar()
            {
                if (getVida() <= 0)
                {
                    setMorreu(true);
                }
                posicao = corpo.getPosition();

                if (posicao.y >= 530.0f)
                {
                    chao = true;
                }

                movimento();
                chao = false;
            }

            void Esqueleto::apodrecer()
            {
                setDano(decomposicao);
                setVelocidade({-decomposicao / 10, 0});
                // std::cout << "Apodrecer!!!!!\n";
            }

            void Esqueleto::movimentoEspecifico()
            {
                int aleatorio = rand() % 1000;
                if (aleatorio >= 500 && direita == true)
                {
                    corpo.move(0.1f, 0);
                }
                else
                {
                    direita = true;
                }

                if (getPosicao().x > 0 && getPosicao().x <= 1150)
                {
                    if (aleatorio < 500 && esquerda == true)
                    {
                        corpo.move(-0.1f, 0);
                    }
                    else
                    {
                        esquerda = true;
                    }

                    if (aleatorio == 0)
                    { // esqueleto pode pular
                        if (chao == true)
                        {
                            aleatorio = rand() % 10 + 1;
                            pular(aleatorio);
                            chao = false;
                        }
                    }
                }
            }

            void Esqueleto::tratarColisao(Entidade *outraEntidade)
            {
                if (outraEntidade->getMorreu() == false)
                {
                    if (outraEntidade->getId() == 1 && !getMorreu())
                    {
                        // std::cout << "colisao com jogador!\n";
                        danar(outraEntidade);
                        apodrecer();

                        if (outraEntidade->getPosicao().x > posicao.x)
                        {
                            setDireita(false);
                        }
                        else
                        {
                            setDireita(true);
                        }

                        if (outraEntidade->getPosicao().x < posicao.x)
                        {
                            setEsquerda(false);
                        }
                        else
                        {
                            setEsquerda(true);
                        }

                        if (outraEntidade->getPosicao().y - 110 > posicao.y)
                        {
                            setDireita(true);
                            setEsquerda(true);
                            setChao(true);
                        }
                    }
                    else if (outraEntidade->getId() == 2)
                    {
                        if (outraEntidade->getPosicao().x > posicao.x)
                        {
                            setDireita(false);
                        }
                        else
                        {
                            setDireita(true);
                        }

                        if (outraEntidade->getPosicao().x < posicao.x)
                        {
                            setEsquerda(false);
                        }
                        else
                        {
                            setEsquerda(true);
                        }

                        if (outraEntidade->getPosicao().y - 110 > posicao.y)
                        {
                            setDireita(true);
                            setEsquerda(true);
                            setChao(true);
                        }
                    }

                    else if (outraEntidade->getId() == 3)
                    {
                        if (outraEntidade->getPosicao().x > posicao.x)
                        {
                            setDireita(false);
                        }

                        else
                        {
                            setEsquerda(false);
                        }

                        if (outraEntidade->getPosicao().y - 110 > posicao.y)
                        {
                            setDireita(true);
                            setEsquerda(true);
                            setChao(true);
                        }
                    }

                    else if (outraEntidade->getId() == 4)
                    {
                        if (outraEntidade->getPosicao().y > posicao.y)
                        {
                            chao = true;
                        }
                    }
                }
            }
        }
    }
}
