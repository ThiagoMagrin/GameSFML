#include "ListaEntidades.h"

namespace Listas {
	ListaEntidade::ListaEntidade() :
		objListaEntidade() , todosMortos(false){ }

	ListaEntidade::~ListaEntidade() { }

	void ListaEntidade::adicionarEntidade(Entidades::Entidade* pEntidade) {
		objListaEntidade.adicionar(pEntidade);
	}

	void ListaEntidade::removerEntidade(Entidades::Entidade* pEntidade) {
		objListaEntidade.remover(pEntidade);
	}

	void ListaEntidade::removerEntidade(unsigned int posicao) {
		objListaEntidade.remover((int)posicao);
	}

	unsigned int ListaEntidade::getTamanho() {
		return objListaEntidade.getTamanho();
	}

	Entidades::Entidade* ListaEntidade::operator[](int posicao) {
		return objListaEntidade.operator[](posicao);
	}

	void ListaEntidade::executar() {
		Entidades::Entidade* aux = nullptr;
		int tam = objListaEntidade.getTamanho();

		for (int i = 0; i < tam; i++) {
			aux = objListaEntidade.operator[](i);

			aux->executar();
			aux->imprimir();
		}

		verificaMortos();
	}

	bool ListaEntidade::getTodosMortos(){
        return todosMortos;
	}

    void ListaEntidade::verificaMortos(){
        Entidades::Entidade* aux = nullptr;
		int tam = objListaEntidade.getTamanho();

		for (int i = 0; i < tam; i++) {
			aux = objListaEntidade.operator[](i);
            if(aux->getMorrer() == true){
                objListaEntidade.remover(i);
                break;
            }
		}

		if(objListaEntidade.getTamanho() <= 1){
            todosMortos = true;
		}
    }
}
