#include "Inimigo3.h"

#define VIDAINIMIGO3 25
#define DANOINIMIGO3 2

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            Inimigo3::Inimigo3() : Inimigo(nullptr) {}
            Inimigo3::~Inimigo3() {}

            void Inimigo3::inicializar(Jogador* pJ){
                setJogador(pJ);

                setVida(VIDAINIMIGO3);
                setDano(DANOINIMIGO3);

                velocidade = sf::Vector2f(70.0f, 70.0f);
                corpo.setSize({50.0f, 70.0f});
                corpo.setPosition({400.0f, 380.0f});
                corpo.setFillColor(sf::Color::Green);

                std::cout << "Inimigo3 inicializado" << std::endl;
            }
        }
    }
}
