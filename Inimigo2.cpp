#include "Inimigo2.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            Inimigo2::Inimigo2() : Inimigo(nullptr) {}
            Inimigo2::~Inimigo2() {}

            void Inimigo2::inicializar(Jogador* pJ) {
                setJogador(pJ);
                velocidade = sf::Vector2f(80.0f, 80.0f);
                corpo.setSize({50.0f, 70.0f});
                corpo.setPosition({600.0f, 380.0f});
                corpo.setFillColor(sf::Color::Yellow);

                std::cout << "Inimigo2 inicializado" << std::endl;
            }
        }
    }
}
