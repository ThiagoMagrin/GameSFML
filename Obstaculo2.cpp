#include "Obstaculo2.h"

namespace Entidades{
    namespace Obstaculos{
        Obstaculo2::Obstaculo2() : Obstaculo() {}
        Obstaculo2::~Obstaculo2() {}

        void Obstaculo2::inicializar(){
                corpo.setSize({30.0f, 30.0f});
                corpo.setPosition({975.0f, 193.0f});
                corpo.setFillColor(sf::Color::Magenta);

                std::cout << "Obstaculo2 inicializado" << std::endl;
        }
    }
}
