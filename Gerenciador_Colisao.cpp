#include "Gerenciador_Colisao.h"
#include "Entidade.h"
#include "math.h"

using namespace Entidades;
using namespace Listas;

namespace Gerenciadores{
	GerenciadorColisao::GerenciadorColisao(ListaEntidade* LEstatica, ListaEntidade* LMovimento):
		ListaEntidadeEstatica(LEstatica),
		ListaEntidadeMovimento(LMovimento) { }

	GerenciadorColisao::~GerenciadorColisao() {
		if (ListaEntidadeEstatica) {
			delete(ListaEntidadeEstatica);
			ListaEntidadeEstatica = nullptr;
		}
		if (ListaEntidadeMovimento) {
			delete(ListaEntidadeMovimento);
			ListaEntidadeMovimento = nullptr;
		}
	}

	void GerenciadorColisao::executar() {
	    bool colide;
		Entidade* Entidade1 = nullptr;
		Entidade* Entidade2 = nullptr;

		int tamLEstatica = (int)ListaEntidadeEstatica->getTamanho();
		int tamLMovimento = (int)ListaEntidadeMovimento->getTamanho();

		for(int i = 0; i < tamLMovimento; i++){
			for (int j = 0; j < tamLEstatica; j++){
				Entidade1 = ListaEntidadeMovimento->operator[](i);
				Entidade2 = ListaEntidadeEstatica->operator[](j);

                sf::FloatRect corpo1 = Entidade1->getCorpo().getGlobalBounds();
                sf::FloatRect corpo2 = Entidade2->getCorpo().getGlobalBounds();

                colide = corpo1.intersects(corpo2);

                if(colide == true){
                    if(Entidade1->getId() == 1){
                        std::cout << "COLIDIU JOGADOR COM OBSTACULO" << std::endl;
                        colisao(Entidade1, Entidade2);
                    }

                    else{
                        std::cout << "COLIDIU PERSONAGEM COM OBSTACULO" << std::endl;
                    }
                }

				Entidade1 = nullptr;
				Entidade2 = nullptr;
			}
        }

		for(int i = 0; i < tamLMovimento; i++){
			for (int j = 1; j < tamLMovimento; j++){
				Entidade1 = ListaEntidadeMovimento->operator[](i);
				Entidade2 = ListaEntidadeMovimento->operator[](j);

                if(Entidade1 != Entidade2){
                    sf::FloatRect corpo1 = Entidade1->getCorpo().getGlobalBounds();
                    sf::FloatRect corpo2 = Entidade2->getCorpo().getGlobalBounds();

                    colide = corpo1.intersects(corpo2);

                    if(colide == true){
						if (Entidade1->getId() == 1) {
							std::cout << "COLIDIU JOGADOR COM INIMIGO" << std::endl;
							colisao(Entidade1, Entidade2);
						}
						else{
                            std::cout << "COLIDIU PERSONAGEM COM PERSONAGEM" << std::endl;
						}
                    }
                }

				Entidade1 = nullptr;
				Entidade2 = nullptr;
            }
        }
    }

	void GerenciadorColisao::colisao(Entidade* Entidade1, Entidade* Entidade2)
	{
		int dano1 = Entidade1->getDano();
		int dano2 = Entidade2->getDano();

		Entidade1->setVida(-dano2);
		Entidade2->setVida(-dano1);

		if (Entidade1->getId() == 1 || Entidade2->getId() == 1) {
			std::cout << "Vida jogador: " << Entidade1->getVida() << std::endl;
		}
		else{
			std::cout << "Vida entidade1: " << Entidade1->getVida() << std::endl;
			std::cout << "Vida entidade2: " << Entidade2->getVida() << std::endl;
		}
	}

}
