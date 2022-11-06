#pragma once

#include "Entidade.h"
#include "Lista.h"

using namespace Entidades;

namespace Listas{
	class ListaEntidade{
        private:
            Lista<Entidade> objLista;
        public:
            ListaEntidade();
            ~ListaEntidade();

            void adicionarEntidade(Entidade* pEntidade);
            void removerEntidade(Entidade* pEntidade);
            void percorrer();
	};
}
