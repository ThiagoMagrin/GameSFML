#include "Espinho.h"

#define DANO_ESPINHO 5

namespace Entidades{
    namespace Obstaculos{
        Espinho::Espinho() : Obstaculo() {}
        Espinho::~Espinho() {}

        void Espinho::inicializar(){
            setDano(DANO_ESPINHO);

            corpo.setSize({30.0f, 30.0f});
            corpo.setPosition({975.0f, 193.0f});
            corpo.setFillColor(sf::Color::Magenta);

            std::cout << "Espinho inicializado" << std::endl;
        }
    }
}
