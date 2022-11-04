#include "Entidade.h"

namespace Entidades {

	//Entidade::Entidade() : Ente(), posicao({ 0.f,0.f }), tamanho(0.f, 0.f), velocidade(0.f, 0.f) {}

	Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel)
	{}

	Entidade::~Entidade() {}

	void Entidade::setPosicao(sf::Vector2f pos) {
		posicao = pos;
	}

	const sf::Vector2f Entidade::getPosicao() const{
		return posicao;
	}

	void Entidade::setTamanho(sf::Vector2f tam) {
		tamanho = tam;
	}

	const sf::Vector2f Entidade::getTamanho() const  {
		return tamanho;
	}

	void Entidade::setVelocidade(sf::Vector2f vel) {
		velocidade = vel;
	}

	const sf::Vector2f Entidade::getVelocidade() const{
		return velocidade;
	}

}
