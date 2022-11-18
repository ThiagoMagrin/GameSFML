#include "Dragao.h"
#include "math.h"

#define VIDA_DRAGAO 250
#define DANO_DRAGAO 3

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            Dragao::Dragao() : Inimigo(nullptr), esquerdaB(false) {}
            Dragao::~Dragao() {}

            void Dragao::inicializar(Jogador* pJ, BolaDeFogo* pBola){
                setJogador(pJ);

                pBolaDeFogo = pBola;
                setVida(VIDA_DRAGAO);
                setDano(DANO_DRAGAO);

                //posicao = sf::Vector2f(350.0f, 505.0f);
                posicao = sf::Vector2f(posicaoAleatoria().x,posicaoAleatoria().y - 30);
                velocidade = sf::Vector2f(30.0f, 30.0f);

                textura = pGraf->carregarTextura("images/Dragao.png");
                corpo.setTexture(textura, true);
                corpo.setPosition(posicao);
            }

            void Dragao::movimento(){
                sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
                sf::Vector2f posInimigo = corpo.getPosition();

                if (chao == false) {
					cair(0.07f);
				}

                if ((fabs(posJogador.x - posInimigo.x) <= 500)) {

                    if (pBolaDeFogo->getLancado() == false) {
                        if (posJogador.x - posInimigo.x > 0) {
                            esquerda = true;
                        }
                        else{
                            esquerda = false;
                        }

                        pBolaDeFogo->resetar(corpo.getPosition());
                    }

                    if(pBolaDeFogo->getAtingiu() == false){
                        perseguirJogador(posJogador, posInimigo);
                    }

                    else{
                        pBolaDeFogo->apagar();
                        pBolaDeFogo->setLancado(false);
                        pBolaDeFogo->setAtingiu(false);
                    }
                }

                else{
                    movimentoEspecifico();
                    pBolaDeFogo->apagar();
                    pBolaDeFogo->setLancado(false);
                    pBolaDeFogo->setAtingiu(false);
                }


            }

            void Dragao::perseguirJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo) {
                if ((posJogador.x - posInimigo.x > 0)) {
                    corpo.move(0.08, 0);
                }
                else {
                    corpo.move(-0.08, 0);
                }
                pBolaDeFogo->lancar(esquerda);
            }
        }
    }
}
