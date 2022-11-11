#include "Tronco.h"

#define DANO_TRONCO 3

namespace Entidades{
    namespace Obstaculos{
        Tronco::Tronco() : Obstaculo() {}
        Tronco::~Tronco() {}

        void Tronco::inicializar(){
            setDano(DANO_TRONCO);

            corpo.setSize({30.0f, 30.0f});
            corpo.setPosition({975.0f, 193.0f});
            corpo.setFillColor(sf::Color::Cyan);

            std::cout << "Tronco inicializado" << std::endl;
        }
    }
}
