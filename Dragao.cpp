#include "Dragao.h"
#include "math.h"

#define VIDA_DRAGAO 250
#define DANO_DRAGAO 30

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            Dragao::Dragao() : Inimigo(nullptr), esquerdaB(false) {}
            Dragao::~Dragao() {}

            void Dragao::inicializar(Jogador *pJ, Jogador *pJ2, BolaDeFogo *pBola)
            {
                setJogador(pJ, pJ2);
                pBolaDeFogo = pBola;
                setVida(VIDA_DRAGAO);
                setDano(DANO_DRAGAO);

                // posicao = sf::Vector2f(350.0f, 505.0f);
                posicao = sf::Vector2f(posicaoAleatoria(1).x, posicaoAleatoria(1).y);
                velocidade = sf::Vector2f(30.0f, 30.0f);

                textura = pGraf->carregarTextura("images/Dragao.png");
                corpo.setTexture(textura, true);
                corpo.setPosition(posicao);
            }

            void Dragao::configuraBolaDeFogo(sf::Vector2f posJogador, sf::Vector2f posInimigo)
            {
                if (pBolaDeFogo->getLancado() == false)
                {
                    if (posJogador.x - posInimigo.x > 0)
                    {
                        esquerdaB = true;
                    }
                    else
                    {
                        esquerdaB = false;
                    }

                    pBolaDeFogo->resetar(corpo.getPosition());
                }

                if (pBolaDeFogo->getAtingiu() == false)
                {
                    perseguirJogador(posJogador, posInimigo);
                }

                else
                {
                    pBolaDeFogo->apagar();
                    pBolaDeFogo->setLancado(false);
                    pBolaDeFogo->setAtingiu(false);
                }
            }

            void Dragao::movimento()
            {
                sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
                sf::Vector2f posJogador2;
                if (pJogador2 != nullptr)
                {
                    posJogador2 = pJogador2->getCorpo().getPosition();
                }
                else
                {
                    posJogador2 = {0, 0};
                }
                sf::Vector2f posInimigo = corpo.getPosition();

                if (chao == false)
                {
                    cair(0.07f);
                }

                if ((fabs(posJogador.x - posInimigo.x) <= 500))
                {
                    configuraBolaDeFogo(posJogador, posInimigo);
                }
                else if ((fabs(posJogador2.x - posInimigo.x) <= 500))
                {
                    configuraBolaDeFogo(posJogador2, posInimigo);
                }
                else
                {
                    movimentoEspecifico();
                    pBolaDeFogo->apagar();
                    pBolaDeFogo->setLancado(false);
                    pBolaDeFogo->setAtingiu(false);
                }
            }

            void Dragao::tratarColisao(Entidade *outraEntidade)
            {

                if (getVida() <= 0)
                {
                    getProjetil()->apagar();
                    setMorreu(true);
                }
                if (outraEntidade->getId() == 1 && !getMorreu())
                {
                    // std::cout << "colisao com jogador!\n";
                    danar(outraEntidade);

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
                    if (outraEntidade->getPosicao().y - 110 > posicao.y)
                    {
                        chao = true;
                    }
                }
            }

            void Dragao::movimentoEspecifico()
            {

                int aleatorio = rand() % 2;
                if (getPosicao().x > 0 && getPosicao().x <= 1150)
                {
                    if (aleatorio == 0 && direita == true)
                    {
                        corpo.move(0.1f, 0);
                    }
                    else
                    {
                        direita = true;
                    }

                    if (aleatorio == 1 && esquerda == true)
                    {
                        corpo.move(-0.1f, 0);
                    }
                    else
                    {
                        esquerda = true;
                    }
                }
            }

            void Dragao::perseguirJogador()
            {
                perseguirJogador(pJogador->getPosicao(), getPosicao());
                if (pJogador2 != nullptr)
                {
                    perseguirJogador(pJogador2->getPosicao(), getPosicao());
                }
            }

            void Dragao::perseguirJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
            {
                if ((posJogador.x - posInimigo.x > 0))
                {
                    if (direita == true)
                    {
                        corpo.move(0.05, 0);
                    }
                    else
                    {
                        direita = true;
                    }
                }
                else
                {
                    if (esquerda == true)
                    {
                        corpo.move(-0.05, 0);
                    }
                    else
                    {
                        esquerda = true;
                    }
                }

                pBolaDeFogo->lancar(esquerdaB);
            }

            BolaDeFogo *Dragao::getProjetil()
            {
                return pBolaDeFogo;
            }
        }
    }
}
