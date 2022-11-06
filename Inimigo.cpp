#include "Inimigo.h"
#include <math.h>

namespace Entidades {
	namespace Personagens {
		namespace Inimigos{
			Inimigo::Inimigo() :
				Personagem(), pJogador(nullptr) {}

			Inimigo::Inimigo(Jogador* pJogador) :
				Personagem(), pJogador(pJogador){}

			Inimigo::~Inimigo() {
				pJogador = nullptr;
			}

            void Inimigo::setJogador(Jogador* pJ){
				this->pJogador = pJ;
			}

			void Inimigo::perseguirJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo) {
				if (posJogador.x - posInimigo.x > 0){
					corpo.move(3, 0);
				}
				else{
					corpo.move(-3, 0);
				}
			}

			void Inimigo::movimento() {
				sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
				sf::Vector2f posInimigo = corpo.getPosition();

				if ((fabs(posJogador.x - posInimigo.x) <= 100)){
					perseguirJogador(posJogador, posInimigo);
				}
			}

            void Inimigo::cair() {
                corpo.move(0.0f, velocidade.y*5);
            }

            void Inimigo::executar(){
                posicao = corpo.getPosition();
                if (posicao.y >= 380.0f || ((posicao.x >= 295 && posicao.x <= 820) && posicao.y == 155)) {
                    chao = true;
                }
                else {
                    chao = false;
                    cair();
                }

                movimento();
            }
		}
	}
}
