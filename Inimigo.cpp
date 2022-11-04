#include "Inimigo.h"
#include <math.h>

namespace Entidades {
	namespace Personagens {
		namespace Inimigo {
			Inimigo::Inimigo() :
				Personagem(), pJogador(nullptr), distanciaJogador({ 0.f, 0.f }) {}

			Inimigo::Inimigo(Jogador* pJogador, sf::Vector2f distanciaJogador) :
				Personagem(), pJogador(pJogador), distanciaJogador(distanciaJogador) {}

			Inimigo::~Inimigo() {
				pJogador = nullptr;
			}

			void Inimigo::perseguirJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo) {
				if (posJogador.x - posInimigo.x > 0) //se esta a esquerda
				{
					corpo.move(3, 0);
				}
				else
				{
					corpo.move(-3, 0);//se esta a direita
				}
			}

			void Inimigo::atualizar() {
				sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
				sf::Vector2f posInimigo = corpo.getPosition();

				if ((fabs(posJogador.x - posInimigo.x) <= 100) && (fabs(posJogador.y - posInimigo.y) <= 100)){
					std::cout << "Jogador entrou no raio do Inimigo\n";
					perseguirJogador(posJogador, posInimigo);
				}
			}

			void Inimigo::setJogador(Jogador* pJ) {
				this->pJogador = pJ;
			}
		}
	}
}
