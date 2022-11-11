#include "Pedra.h"

#define DANO_PEDRA 7

namespace Entidades{
    namespace Obstaculos{
        Pedra::Pedra() : Obstaculo() {}
        Pedra::~Pedra() {}

        void Pedra::inicializar(){
            setDano(DANO_PEDRA);

            corpo.setSize({30.0f, 30.0f});
            corpo.setPosition({145.0f, 170.0f});
            corpo.setFillColor(sf::Color::Black);

            std::cout << "Pedra inicializado" << std::endl;
        }
    }
}
