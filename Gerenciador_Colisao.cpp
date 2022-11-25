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

	void GerenciadorColisao::colisaoEstatica(){
        bool colide = false;
        int tamLMovimento = (int)ListaEntidadeMovimento->getTamanho();
        int tamLEstatica = (int)ListaEntidadeEstatica->getTamanho();
        Entidade* entidade1 = nullptr;
		Entidade* entidade2 = nullptr;

        for(int i = 0; i < tamLMovimento; i++){
			for (int j = 0; j < tamLEstatica; j++){
				entidade1 = ListaEntidadeMovimento->operator[](i);
				entidade2 = ListaEntidadeEstatica->operator[](j);

                sf::FloatRect corpo1 = entidade1->getCorpo().getGlobalBounds();
                sf::FloatRect corpo2 = entidade2->getCorpo().getGlobalBounds();

                colide = corpo1.intersects(corpo2);

                if(colide){
                    entidade1->tratarColisao(entidade2);
                }

                else{
                    if(entidade2->getId() == 4){
                        entidade1->setChao(false);
                    }
                }

				entidade1 = nullptr;
				entidade2 = nullptr;
			}
        }
	}

    void GerenciadorColisao::colisaoDinamica(){
        bool colide = false;
        int tamLMovimento = (int)ListaEntidadeMovimento->getTamanho();
        Entidade* entidade1 = nullptr;
		Entidade* entidade2 = nullptr;

		for(int i = 0; i < tamLMovimento; i++){
			for (int j = 1; j < tamLMovimento; j++){
				entidade1 = ListaEntidadeMovimento->operator[](i);
				entidade2 = ListaEntidadeMovimento->operator[](j);
				if(entidade1 != entidade2){
                    sf::FloatRect corpo1 = entidade1->getCorpo().getGlobalBounds();
                    sf::FloatRect corpo2 = entidade2->getCorpo().getGlobalBounds();

                    colide = corpo1.intersects(corpo2);

                    if(colide){
                        entidade1->tratarColisao(entidade2);
                    }
                }
				entidade1 = nullptr;
				entidade2 = nullptr;
            }
        }
	}

	void GerenciadorColisao::executar() {
        colisaoDinamica();
        colisaoEstatica();
    }
}
