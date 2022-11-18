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

	sf::Vector2f Entidade::posicaoAleatoria(float inicio)
	{
		//PEGAR POSICAO DA PLATAFORMA OU DO CHAO
		//Plataforma {280.0f, 280.0f}
		//chao (700.0f, 530.0f}
		int local = rand() % 2;

		float x, y;
		if (local == 1) {
			 x = inicio + 80 +static_cast<float>(rand()) * static_cast<float>(250) / RAND_MAX;
			 y = 280;
			//std::cout << " PLATAFORMA";
		}
		else
		{
			//std::cout << " Chao";

			 x =  inicio + static_cast<float>(rand()) * static_cast<float>(600) / RAND_MAX;
			 y = 530;//+ static_cast<float>(rand()) * static_cast<float>(600) / RAND_MAX;
		}

		return sf::Vector2f(x,y);
	}

    void Entidade::imprimir(){
        pGraf->desenhaElemento(corpo);
    }

	void Entidade::setMorrer(bool m){
		morreu = m;
	}

	bool Entidade::getMorrer(){
		return morreu;
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
}
