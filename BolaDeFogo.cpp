#include "BolaDeFogo.h"
#include "Dragao.h"

#define VELBOLA 0.3f
#define DANOBOLA 50.0f

namespace Entidades {
	BolaDeFogo::BolaDeFogo(): lancado(false)
	{
		setID(5);
	}

	Entidades::BolaDeFogo::~BolaDeFogo(){}


	void BolaDeFogo::inicializar()
	{
		velocidade = sf::Vector2f(VELBOLA, VELBOLA);
		setDano(DANOBOLA);
		posicao = sf::Vector2f(350.0f, 505.0f);

        textura = pGraf->carregarTextura("images/fireball.png");
        corpo.setTexture(textura, true);
        corpo.setPosition(posicao);

	}

	void BolaDeFogo::apagar()
	{
		corpo.setPosition(1250.0f, 505.0f);
		lancado = false;
	}

	void BolaDeFogo::resetar(sf::Vector2f p)
	{
		corpo.setPosition(p);
		lancado = true;
	}

	void BolaDeFogo::lancar(bool esquerdaB)
	{
		
		if(corpo.getPosition().x >= 0 && corpo.getPosition().x <= 1300) {
			if (esquerdaB == true){
				corpo.move(VELBOLA, 0);
			}
			else{
				corpo.move(-VELBOLA, 0);
			}

			cair(0.005f);
		}

		else{
            apagar();
            lancado = false;
            atingiu = false;
		}
	}
}
