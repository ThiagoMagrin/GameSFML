#pragma once

#include "ListaEntidades.h"

using namespace Listas;

namespace Gerenciadores
{
	class GerenciadorColisao
	{
	private:
		ListaEntidade *ListaEntidadeEstatica;
		ListaEntidade *ListaEntidadeMovimento;

	public:
		GerenciadorColisao();
		GerenciadorColisao(ListaEntidade *LEstatica, ListaEntidade *LMovimento);
		~GerenciadorColisao();
		void colisaoDinamica();
		void colisaoEstatica();
		void executar();
	};
}
