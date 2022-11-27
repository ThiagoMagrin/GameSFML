#include "Entidade.h"
#include <time.h>

namespace Entidades {
    Entidade::Entidade() : Ente(0), posicao({0.f,0.f}), tamanho({0.f, 0.f}), corpo(), textura(), vida(0), dano(0), atingiu(false), morreu(false){}

	Entidade::~Entidade() {}

	void Entidade::setPosicao(sf::Vector2f pos) {
		posicao = pos;
	}

	const sf::Vector2f Entidade::getPosicao() const{
		return posicao;
	}

	void Entidade::setTamanho(sf::Vector2f tam){
        tamanho = tam;
	}

    const sf::Vector2f Entidade::getTamanho() const{
        return tamanho;
	}

    sf::Sprite Entidade::getCorpo(){
        return corpo;
    }

	sf::Vector2f Entidade::posicaoAleatoria(int tipo)
	{
		float x, y;

		if (tipo == 0) {
			 x = static_cast<float>(rand() % 740 + 250);
			 y = 280;
		}

		else
		{
			 x = static_cast<float>(rand() % 600 + 370);
			 y = 530;
		}

		return sf::Vector2f(x,y);
	}

    void Entidade::imprimir(){
        pGraf->desenhaElemento(corpo);
    }

	void Entidade::setMorrer(bool m){
		morreu = m;
	}

	const bool Entidade::getMorrer() const{
		return morreu;
	}

    void Entidade::setChao(bool b)
    {
        chao = b;
    }

    const bool Entidade::getChao() const 
    {
        return chao;
    }

	void Entidade::executar() {}

    void Entidade::cair(float intensificador){
        //Equação da velocidade do corpo na queda livre: V = G*T
        //fonte: https://brasilescola.uol.com.br/fisica/queda-livre.htm#Equa%C3%A7%C3%A3o+de+Torricelli
        float velQueda;
        float t = 1;//TEMPO em segundos
        velQueda = intensificador * (GRAVIDADE * t);
        corpo.move(0, velQueda);
    }

    const int Entidade::getVida()const {
        return vida;
    }

    void Entidade::setVida(int v) {
        vida += v;
    }

    const int Entidade::getDano()const {
        return dano;
    }

    void Entidade::setDano(int d){
        dano += d;
    }
    void Entidade::setAtingiu(bool b) {
        atingiu = b;
    }

    const bool Entidade::getAtingiu() const {
        return atingiu;
    }
}
