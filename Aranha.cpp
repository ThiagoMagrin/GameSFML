#include "Aranha.h"

#define VIDA_ARANHA 25
#define DANO_ARANHA 2

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            Aranha::Aranha() : Inimigo(nullptr) {}
            Aranha::~Aranha() {}

            void Aranha::inicializar(Jogador* pJ){
                setJogador(pJ);

                setVida(VIDA_ARANHA);
                setDano(DANO_ARANHA);

                velocidade = sf::Vector2f(70.0f, 70.0f);
                corpo.setSize({50.0f, 70.0f});
                corpo.setPosition({400.0f, 380.0f});
                corpo.setFillColor(sf::Color::Green);

                std::cout << "Aranha inicializado" << std::endl;
            }
        }
    }
}
