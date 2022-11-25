#include "Dragao.h"
#include "math.h"

#define VIDA_DRAGAO 250
#define DANO_DRAGAO 3

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            Dragao::Dragao() : Inimigo(nullptr), esquerdaB(false) {}
            Dragao::~Dragao(){}

            void Dragao::inicializar(Jogador* pJ, Jogador* pJ2, BolaDeFogo* pBola){
                setJogador(pJ, pJ2);
                pBolaDeFogo = pBola;
                setVida(VIDA_DRAGAO);
                setDano(DANO_DRAGAO);

                //posicao = sf::Vector2f(350.0f, 505.0f);
                posicao = sf::Vector2f(posicaoAleatoria(1).x, posicaoAleatoria(1).y);
                velocidade = sf::Vector2f(30.0f, 30.0f);

                textura = pGraf->carregarTextura("images/Dragao.png");
                corpo.setTexture(textura, true);
                corpo.setPosition(posicao);
            }

            void Dragao::configuraBolaDeFogo(sf::Vector2f posJogador, sf::Vector2f posInimigo){
                    if (pBolaDeFogo->getLancado() == false) {
                        if (posJogador.x - posInimigo.x > 0) {
                            esquerdaB = true;
                        }
                        else{
                            esquerdaB = false;
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

            void Dragao::movimento(){
                sf::Vector2f posJogador = pJogador->getCorpo().getPosition();



                sf::Vector2f posJogador2;
                if (pJogador2 != nullptr) {
                    posJogador2 = pJogador2->getCorpo().getPosition();
                }
                else {
                    posJogador2 = { 0,0 };
                }
                sf::Vector2f posInimigo = corpo.getPosition();

                if (chao == false) {
					cair(0.07f);
				}

                if ((fabs(posJogador.x - posInimigo.x) <= 500)) {
                    configuraBolaDeFogo(posJogador, posInimigo);
                }
                else if ((fabs(posJogador2.x - posInimigo.x) <= 500)) {
                    configuraBolaDeFogo(posJogador2, posInimigo);
                }
                else{
                    movimentoEspecifico();
                    pBolaDeFogo->apagar();
                    pBolaDeFogo->setLancado(false);
                    pBolaDeFogo->setAtingiu(false);
                }


            }

            void Dragao::perseguirJogador(){
                perseguirJogador(pJogador->getPosicao(), getPosicao());
                if(pJogador2 != nullptr){
                    perseguirJogador(pJogador2->getPosicao(), getPosicao());
                }
            }

            void Dragao::perseguirJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo) {
                if ((posJogador.x - posInimigo.x > 0)){
                    if(direita == true){
                        corpo.move(0.05, 0);
                    }
                    else{
                        direita = true;
                    }
                }
                else {
                    if(esquerda == true){
                        corpo.move(-0.05, 0);
                    }
                    else{
                        esquerda = true;
                    }
                }

                pBolaDeFogo->lancar(esquerdaB);
            }

            BolaDeFogo* Dragao::getProjetil(){
                return pBolaDeFogo;
            }
        }
    }
}
