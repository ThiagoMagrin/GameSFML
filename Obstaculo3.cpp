#include "Obstaculo3.h"

#define DANO_OBSTACULO3 3

namespace Entidades{
    namespace Obstaculos{
        Obstaculo3::Obstaculo3() : Obstaculo() {}
        Obstaculo3::~Obstaculo3() {}

        void Obstaculo3::inicializar(){
            setDano(DANO_OBSTACULO3);

            corpo.setSize({30.0f, 30.0f});
            corpo.setPosition({975.0f, 193.0f});
            corpo.setFillColor(sf::Color::Cyan);

            std::cout << "Obstaculo3 inicializado" << std::endl;
        }
    }
}
