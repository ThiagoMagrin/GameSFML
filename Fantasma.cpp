#include "Fantasma.h"

#define VIDA_FANTASMA 100
#define DANO_FANTASMA 1
#define VEL_FANTASMA 0.05f
namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            Fantasma::Fantasma() : Inimigo(nullptr), assombracao(0){}
            Fantasma::~Fantasma() {}

            void Fantasma::inicializar(Jogador* pJ, Jogador* pJ2) {
                setJogador(pJ, pJ2);

                assombracao =  + rand() % 4;
                setVida(VIDA_FANTASMA);
                setDano(DANO_FANTASMA * assombracao);
                setTamanho({70.0f, 70.0f});
                posicao = sf::Vector2f(posicaoAleatoria(1));
                setVelocidade({VEL_FANTASMA,VEL_FANTASMA });
                textura = pGraf->carregarTextura("images/Fantasma.png");
                corpo.setTexture(textura, true);
                corpo.setPosition(posicao);

                
                std::cout << "nivel assombracao = " << assombracao << std::endl;
            }

            void Fantasma::movimentoEspecifico(){
                int aleatorio = rand() % 100;
                if (aleatorio >= 50 && direita == true) {
                    corpo.move(0.1f, 0);
                }
                else {
                    direita = true;
                }

                if (aleatorio < 50 && esquerda == true) {
                    corpo.move(-0.1f, 0);
                }
                else {
                    esquerda = true;
                }

                if (aleatorio == 0) {// fantasma pode mover rapidamente  
                    aleatorio = rand() % 5 - 10;
                    corpo.move(aleatorio, 0);
                }

            }

            void Fantasma::assombrar(bool a)
            { //pode aumentar o dano e a velocidade a cada execucao
                int aleatorio;
                if (a == false) {
                    aleatorio = rand() % 500;
                } else {aleatorio = 0; }
                if (aleatorio == 0) {
                    setDano( assombracao);
                    setVelocidade({ assombracao/10,0  });
                    //std::cout << "\nAssombracao!!!!! - vel = "<< getVelocidade().x;
                }
            }

            void Fantasma::tratarColisao(Entidade* outraEntidade)
            {
                      if (outraEntidade->getId() == 1 && !getMorrer())  {
                           // std::cout << "colisao com jogador!\n";
                            danar(outraEntidade);
                            assombrar(true); // asombrar sempre que colidir com o jogador  
                          
                            if (outraEntidade->getPosicao().x > posicao.x) {
                                setDireita(false);
                            }
                            else {
                                setDireita(true);
                            }

                            if (outraEntidade->getPosicao().x < posicao.x) {
                                setEsquerda(false);
                            }
                            else {
                                setEsquerda(true);
                            }

                            if (outraEntidade->getPosicao().y - 110 > posicao.y) {
                                setDireita(true);
                                setEsquerda(true);
                                setChao(true);
                            }
                        }
                        else
                            if (outraEntidade->getId() == 2) {
                                if (outraEntidade->getPosicao().x > posicao.x) {
                                    setDireita(false);
                                }
                                else {
                                    setDireita(true);
                                }

                                if (outraEntidade->getPosicao().x < posicao.x) {
                                    setEsquerda(false);
                                }
                                else {
                                    setEsquerda(true);
                                }

                                if (outraEntidade->getPosicao().y - 110 > posicao.y) {
                                    setDireita(true);
                                    setEsquerda(true);
                                    setChao(true);
                                }
                            }

                            else if (outraEntidade->getId() == 3) {
                                if (outraEntidade->getPosicao().x > posicao.x) {
                                    setDireita(false);
                                }

                                else {
                                    setEsquerda(false);
                                }

                                if (outraEntidade->getPosicao().y - 110 > posicao.y) {
                                    setDireita(true);
                                    setEsquerda(true);
                                    setChao(true);
                                }
                            }

                            else if (outraEntidade->getId() == 4) {
                                if (outraEntidade->getPosicao().y - 110 > posicao.y) {
                                    chao = true;
                                }
                            }
                     
            }

            void Fantasma::executar()
            {
                if (getVida() <= 0) {

                    setMorrer(true);
                }
               
                assombrar();
                posicao = corpo.getPosition();

                if (posicao.y >= 530.0f) {
                    chao = true;
                }

                movimento();
            }
            
        }
    }
}
