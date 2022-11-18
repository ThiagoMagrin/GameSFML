#include "Inimigo.h"
#include <math.h>

namespace Entidades {
	namespace Personagens {
		namespace Inimigos{
			Inimigo::Inimigo() :
				Personagem(), pJogador(nullptr) {
                    setID(2);
				}

			Inimigo::Inimigo(Jogador* pJogador) :
				Personagem(), pJogador(pJogador), lado(false){
                    setID(2);
				}

			Inimigo::~Inimigo() {
				pJogador = nullptr;
			}

            void Inimigo::setJogador(Jogador* pJ){
				pJogador = pJ;
			}

			void Inimigo::perseguirJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo) {
				if ((posJogador.x - posInimigo.x > 0 ) && direita == true ){
					corpo.move(0.08, 0);
				}
				else if(esquerda == true){
					corpo.move(-0.08, 0);
				}
			}

			void Inimigo::movimento() {
				sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
				sf::Vector2f posInimigo = corpo.getPosition();

				if (chao == false) {
					cair(0.07f);
				}

				if ((fabs(posJogador.x - posInimigo.x) <= 500) && (fabs(posJogador.y - posInimigo.y) <= 100)){
					perseguirJogador(posJogador, posInimigo);
				}
				else {
					movimentoEspecifico();
				}
			}

			void Inimigo::movimentoEspecifico()
			{
				float posI = getPosicao().x;

				int aleatorio = rand() % 11;//0-10

				if (aleatorio > 5 && posI < 1200.0f) {
					corpo.move(1.f, 0);
				}
				else if (posI > 0.0f)
				{
					corpo.move(-1.f, 0);
				}
			}

			void Inimigo::colisao(Entidade* outraEntidade)
			{
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
