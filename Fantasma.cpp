#include "Fantasma.h"

#define VIDA_FANTASMA 100
#define DANO_FANTASMA 2
#define VEL_FANTASMA 0.08f
namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            Fantasma::Fantasma() : Inimigo(nullptr), assombracao(0)
            {
                chao = false;
            }
            Fantasma::~Fantasma() {}

            void Fantasma::inicializar(Jogador *pJ, Jogador *pJ2)
            {
                setJogador(pJ, pJ2);
                assombracao = +rand() % 4;
                setVida(VIDA_FANTASMA);
                setDano(DANO_FANTASMA * assombracao);
                setVelocidade({VEL_FANTASMA, VEL_FANTASMA});
                textura = pGraf->carregarTextura("images/Fantasma.png");
                corpo.setTexture(textura, true);
                posicao = sf::Vector2f(posicaoAleatoria(1));
                corpo.setPosition({posicao.x, posicao.y});
            }

            void Fantasma::movimentoEspecifico()
            {
                int aleatorio = rand() % 100;
                if (aleatorio >= 50 && direita == true)
                {
                    corpo.move(0.1f, 0);
                }
                else
                {
                    direita = true;
                }
                if (getPosicao().x > 0 && getPosicao().x <= 1150)
                {

                    if (aleatorio < 50 && esquerda == true)
                    {
                        corpo.move(-0.1f, 0);
                    }
                    else
                    {
                        esquerda = true;
                    }

                    if (aleatorio == 0)
                    { // fantasma pode mover rapidamente
                        float a = rand() % 10 - 5;
                        corpo.move(a, 0);
                    }
                }
            }

            void Fantasma::assombrar(bool a)
            { // pode aumentar o dano e a velocidade a cada execucao
                int aleatorio;
                if (a == false)
                {
                    aleatorio = rand() % 500;
                }
                else
                {
                    aleatorio = 0;
                }
                if (aleatorio == 0)
                {
                    setDano(assombracao);
                    setVelocidade({assombracao / 10, 0});
                }
            }

            void Fantasma::tratarColisao(Entidade *outraEntidade)
            {
                if (outraEntidade->getMorreu() == false)
                {
                    if (outraEntidade->getId() == 1 && !getMorreu())
                    {
                        // std::cout << "colisao com jogador!\n";
                        danar(outraEntidade);

                        assombrar(true); // asombrar sempre que colidir com o jogador

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
                        // std::cout << "CHAO";
                        if (outraEntidade->getPosicao().y > posicao.y)
                        {
                            chao = true;
                            // std::cout << "P";
                        }
                        else
                        { /* chao = false;*/
                        }
                    }
                }
            }

            void Fantasma::executar()
            {
                posicao = corpo.getPosition();
                if ((posicao.y >= 530.0f))
                {
                    chao = true;
                }
                if (getVida() <= 0)
                {

                    setMorreu(true);
                }

                assombrar();
                if (chao == false)
                {
                    //  std::cout << "caindo";
                    cair(0.07f);
                }

                movimento();

                chao = false;
            }

        }
    }
}
