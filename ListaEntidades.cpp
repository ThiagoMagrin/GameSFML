#include "ListaEntidades.h"

namespace Listas{
	ListaEntidade::ListaEntidade():
		objLista() {}

	ListaEntidade::~ListaEntidade() {}

	void ListaEntidade::adicionarEntidade(Entidade* pEntidade){
		objLista.incluaTipo(pEntidade);
	}

	void ListaEntidade::removerEntidade(Entidade* pEntidade){
		objLista.remover(pEntidade);
	}

	void ListaEntidade::percorrer(){
		objLista.percorrer();
	}
}
