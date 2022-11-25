#include "Inimigo.h"
#include <math.h>

namespace Entidades {
	namespace Personagens {
		namespace Inimigos{
			Inimigo::Inimigo() : Personagem(), pJogador(nullptr), pJogador2(nullptr){
                    setID(0);
				}

			Inimigo::Inimigo(Jogador* pJogador) :
				Personagem(), pJogador(pJogador), pJogador2(nullptr){
                    setID(2);
				}

            Inimigo::Inimigo(Jogador* pJogador, Jogador* pJogador2) :
				Personagem(), pJogador(pJogador), pJogador2(pJogador2){
                    setID(2);
				}

			Inimigo::~Inimigo() {
				pJogador = nullptr;
				pJogador2 = nullptr;
			}

            void Inimigo::setJogador(Jogador* pJ, Jogador* pJ2){
				pJogador = pJ;
                pJogador2 = pJ2;
			}

			void Inimigo::perseguirJogador(){
                perseguirJogador(pJogador->getPosicao(), getPosicao());
                if(pJogador2 != nullptr){
                   // perseguirJogador(pJogador2->getPosicao(), getPosicao());
                }
			}

			void Inimigo::perseguirJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo) {
				if ((posJogador.x - posInimigo.x > 0)){
                    if(direita == true){
                        corpo.move(0.05, 0);
                    }
                    else{
                        direita = true;
                    }
				}
				else{
                    if(esquerda == true){
                        corpo.move(-0.05, 0);
                    }
                    else{
                        esquerda = true;
                    }
				}
			}

			void Inimigo::movimento() {

				sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
                sf::Vector2f posJogador2;
                if (pJogador2 == nullptr) {

                     posJogador2 = { 0,0 };
                }
                else {  posJogador2 = pJogador2->getCorpo().getPosition(); }

				sf::Vector2f posInimigo = corpo.getPosition();

				if (chao == false) {
					cair(0.07f);
				}

				if(posInimigo.x + 100 > 1200){
                    direita = false;
				}

				if(posInimigo.x <= 0){
                    esquerda = false;
				}

				if ((fabs(posJogador.x - posInimigo.x) <= 500) && (fabs(posJogador.y - posInimigo.y) <= 100)){
					perseguirJogador();

				}
                else{
					movimentoEspecifico();
				}

                if (pJogador2 != nullptr) {

                    if ((fabs(posJogador2.x - posInimigo.x) <= 500) && (fabs(posJogador2.y - posInimigo.y) <= 100)){
                        perseguirJogador();
                    }
				}
				else {
					movimentoEspecifico();
				}
			}

			void Inimigo::movimentoEspecifico()
			{
				int aleatorio = rand() % 2;

				if (aleatorio == 0 && direita == true){
                    corpo.move(0.1f, 0);
				}
				else{
                    direita = true;
				}

                if(aleatorio == 1 && esquerda == true){
                    corpo.move(-0.1f, 0);
                }
                else{
                    esquerda = true;
                }
			}

			void Inimigo::tratarColisao(Entidade* outraEntidade)
			{
			    if(outraEntidade->getId() == 2){
                    if(outraEntidade->getPosicao().x > posicao.x){
                        setDireita(false);
                    }
                    else{
                        setDireita(true);
                    }

                    if(outraEntidade->getPosicao().x < posicao.x){
                        setEsquerda(false);
                    }
                    else{
                        setEsquerda(true);
                    }

                    if(outraEntidade->getPosicao().y - 110 > posicao.y){
                        setDireita(true);
                        setEsquerda(true);
                        setChao(true);
                    }
			    }

				else if(outraEntidade->getId() == 3){
                    if(outraEntidade->getPosicao().x > posicao.x){
                        setDireita(false);
                    }

                    else{
                        setEsquerda(false);
                    }

                    if(outraEntidade->getPosicao().y - 110 > posicao.y){
                        setDireita(true);
                        setEsquerda(true);
                        setChao(true);
                    }
				}

                if (outraEntidade->getId() == 4) {
					if (outraEntidade->getPosicao().y - 110 > posicao.y) {
						chao = true;
					}
				}
			}

            void Inimigo::executar(){
                posicao = corpo.getPosition();

                if (posicao.y >= 530.0f) {
                    chao = true;
                }

                movimento();
            }
		}
	}
}
