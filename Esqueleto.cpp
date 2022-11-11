#include "Esqueleto.h"

#define VIDA_ESQUELETO 25
#define DANO_ESQUELETO 2

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            Esqueleto::Esqueleto() : Inimigo(nullptr) {}
            Esqueleto::~Esqueleto() {}

            void Esqueleto::inicializar(Jogador* pJ) {
                setJogador(pJ);

                setVida(VIDA_ESQUELETO);
                setDano(DANO_ESQUELETO);

                velocidade = sf::Vector2f(70.0f, 70.0f);
                corpo.setSize({50.0f, 70.0f});
                corpo.setPosition({400.0f, 380.0f});
                corpo.setFillColor(sf::Color::Red);

                std::cout << "Esqueleto inicializado" << std::endl;
            }
        }
    }
}
