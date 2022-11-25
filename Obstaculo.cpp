#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
        Obstaculo::Obstaculo() : Entidade(), vida(0), dano(0), causaDano(false) {
            setID(3);
        }

        Obstaculo::~Obstaculo(){}
        void Obstaculo::setCausaDano(bool b)
        {
            causaDano = b;
        }
        const bool Obstaculo::getCausaDano()
        {
            return causaDano;
        }
	}
}
