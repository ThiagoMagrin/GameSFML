#include "Personagem.h"
#include <SFML/Graphics.hpp>

namespace Entidades {
    namespace Personagens {
        Personagem::Personagem() : Entidade(), vida(0), dano(0), chao(false), morrer(true) {}

        Personagem::~Personagem() {}

        void  Personagem::setVida(int v) {
            vida = v;
        }

        const int  Personagem::getVida() const {
            return vida;
        }

        void  Personagem::setDano(int d) {
            dano = d;
        }

        const int  Personagem::getDano() const {
            return dano;
        }
    }
}
