#include "Chefao.h"

#define VIDA_CHEFAO 50
#define DANO_CHEFAO 10

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            Chefao::Chefao() : Inimigo(nullptr) {}
            Chefao::~Chefao() {}

            void Chefao::inicializar(Jogador* pJ){
                setJogador(pJ);

                setVida(VIDA_CHEFAO);
                setDano(DANO_CHEFAO);

                velocidade = sf::Vector2f(80.0f, 80.0f);
                corpo.setSize({50.0f, 70.0f});
                corpo.setPosition({600.0f, 380.0f});
                corpo.setFillColor(sf::Color::Yellow);

                std::cout << "Chefao inicializado" << std::endl;
            }
        }
    }
}
