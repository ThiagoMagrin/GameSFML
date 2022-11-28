#pragma once

#include "ListaTemplate.h"
#include "Entidade.h"

namespace Listas
{
	class ListaEntidade
	{
	private:
		Lista<Entidades::Entidade> objListaEntidade;
		bool todosMortos;

	public:
		ListaEntidade();
		~ListaEntidade();

		void adicionarEntidade(Entidades::Entidade *pEntidade);
		void removerEntidade(Entidades::Entidade *pEntidade);
		void removerEntidade(unsigned int posicao);
		unsigned int getTamanho();
		Entidades::Entidade *operator[](int posicao);
		void executar();

		bool getTodosMortos();
		void verificaMortos();
	};
}
