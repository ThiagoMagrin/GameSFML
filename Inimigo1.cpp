#include "Inimigo1.h"

#define VELOCIDADE 80.0f
#define TAMANHO_X 50.0f
#define TAMANHO_Y 70.0f
#define DISTANCIA_X 400.0f
#define DISTANCIA_Y 80.0f

namespace Entidades {
    namespace Personagens {
        namespace Inimigo {
            Inimigo1::Inimigo1(sf::Vector2f posInicio, Jogador* pJogador) :
                Inimigo(pJogador, sf::Vector2f(DISTANCIA_X, DISTANCIA_Y)) {
                corpo.setSize({TAMANHO_X, TAMANHO_Y});
                corpo.setPosition(posInicio);
                corpo.setFillColor(sf::Color::Red);
                this->inicializar();
                std::cout << "Inimigo1 criado";
            }

            Inimigo1::~Inimigo1() { }

            void Inimigo1::inicializar() {
                velocidade = sf::Vector2f(VELOCIDADE, VELOCIDADE);
                tamanho = sf::Vector2f(TAMANHO_X, TAMANHO_Y);
            }
            void Inimigo1::renderizar(){}
            void Inimigo1::executar(){}
        }
    }
}
