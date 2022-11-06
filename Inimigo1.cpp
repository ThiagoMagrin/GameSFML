#include "Inimigo1.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            Inimigo1::Inimigo1() : Inimigo(nullptr) {}
            Inimigo1::~Inimigo1() {}

            void Inimigo1::inicializar(Jogador* pJ) {
                setJogador(pJ);
                velocidade = sf::Vector2f(70.0f, 70.0f);
                corpo.setSize({50.0f, 70.0f});
                corpo.setPosition({400.0f, 380.0f});
                corpo.setFillColor(sf::Color::Red);

                std::cout << "Inimigo1 inicializado" << std::endl;
            }
        }
    }
}
