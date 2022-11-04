#include "Inimigo1.h"
#include "Inimigo2.h"

#define VELOCIDADE2 80.0f
#define TAMANHO_X2 30.0f
#define TAMANHO_Y2 30.0f
#define DISTANCIA_X2 400.0f
#define DISTANCIA_Y2 80.0f

namespace Entidades {
    namespace Personagens {
        namespace Inimigo {
            Inimigo2::Inimigo2(sf::Vector2f posInicio, Jogador* pJogador) :
                Inimigo(pJogador, sf::Vector2f(DISTANCIA_X2, DISTANCIA_Y2)) {
                corpo.setSize({TAMANHO_X2, TAMANHO_Y2});
                corpo.setPosition(posInicio);
                corpo.setFillColor(sf::Color::Red);
                this->inicializar();
                std::cout << "Inimigo1 criado";
            }

            Inimigo2::~Inimigo2() { }

            void Inimigo2::inicializar() {
                velocidade = sf::Vector2f(VELOCIDADE2, VELOCIDADE2);
                tamanho = sf::Vector2f(TAMANHO_X2, TAMANHO_Y2);
            }
            void Inimigo2::renderizar(){}
            void Inimigo2::executar(){}
        }
    }
}
