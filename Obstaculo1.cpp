#include "Obstaculo1.h"

#define DANO_OBSTACULO1 7

namespace Entidades{
    namespace Obstaculos{
        Obstaculo1::Obstaculo1() : Obstaculo() {}
        Obstaculo1::~Obstaculo1() {}

        void Obstaculo1::inicializar(){
            setDano(DANO_OBSTACULO1);

            corpo.setSize({30.0f, 30.0f});
            corpo.setPosition({145.0f, 170.0f});
            corpo.setFillColor(sf::Color::Black);

            std::cout << "Obstaculo1 inicializado" << std::endl;
        }
    }
}
