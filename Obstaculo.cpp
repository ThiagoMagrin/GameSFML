#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
        Obstaculo::Obstaculo() : Entidade(){}
        Obstaculo::~Obstaculo(){}

        void Obstaculo::setVida(int v){
            vida = v;
        }

        const int Obstaculo::getVida() const{
            return vida;
        }

        void Obstaculo::setDano(int d){
            dano = d;
        }

        const int Obstaculo::getDano() const{
            return dano;
        }
	}
}
