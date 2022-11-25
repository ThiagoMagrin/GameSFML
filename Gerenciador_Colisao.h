#pragma once

#include "ListaEntidades.h"

using namespace Listas;

namespace Gerenciadores{
	class GerenciadorColisao{
	private:
		ListaEntidade* ListaEntidadeEstatica;
		ListaEntidade* ListaEntidadeMovimento;
	public:
		GerenciadorColisao(ListaEntidade* LEstatica, ListaEntidade* LMovimento);
		~GerenciadorColisao();
		void colisaoDinamica();
		void colisaoEstatica();
		void executar();
		//sf::Vector2f calculaColisao(Entidades::Entidade* Entidade1, Entidades::Entidade* Entidade2);
	};
}
