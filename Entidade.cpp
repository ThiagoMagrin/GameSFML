#include "Entidade.h"

namespace Entidades {
    Entidade::Entidade() : posicao({0.f,0.f}), velocidade({0.f,0.f}), corpo(){}

	Entidade::~Entidade() {}

	void Entidade::setPosicao(sf::Vector2f pos) {
		posicao = pos;
	}

	const sf::Vector2f Entidade::getPosicao() const{
		return posicao;
	}

	void Entidade::setVelocidade(sf::Vector2f vel) {
		velocidade = vel;
	}

	const sf::Vector2f Entidade::getVelocidade() const{
		return velocidade;
	}

    sf::RectangleShape Entidade::getCorpo(){
        return corpo;
    }

    void Entidade::imprimir(){
        pGrafico->desenhaElemento(corpo);
    }
}
