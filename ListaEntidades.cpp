#include "ListaEntidades.h"

namespace Listas
{
	ListaEntidade::ListaEntidade() : objListaEntidade(), todosMortos(false) {}

	ListaEntidade::~ListaEntidade()
	{
		int tam = objListaEntidade.getTamanho();
		for (int i = 0; i < tam; i++)
		{
			if (objListaEntidade[i])
			{
				delete objListaEntidade[i];
			}
		}
	}

	void ListaEntidade::adicionarEntidade(Entidades::Entidade *pEntidade)
	{
		objListaEntidade.adicionar(pEntidade);
	}

	void ListaEntidade::removerEntidade(Entidades::Entidade *pEntidade)
	{
		objListaEntidade.remover(pEntidade);
	}

	void ListaEntidade::removerEntidade(unsigned int posicao)
	{
		objListaEntidade.remover((int)posicao);
	}

	unsigned int ListaEntidade::getTamanho()
	{
		return objListaEntidade.getTamanho();
	}

	Entidades::Entidade *ListaEntidade::operator[](int posicao)
	{
		return objListaEntidade.operator[](posicao);
	}

	void ListaEntidade::executar()
	{
		Entidades::Entidade *aux = nullptr;
		int tam = objListaEntidade.getTamanho();

		for (int i = 0; i < tam; i++)
		{
			aux = objListaEntidade[i];

			if (aux->getMorreu() == true)
			{
				if (aux->getDano() == 30)
				{
					objListaEntidade[i + 1]->setMorreu(true);
					objListaEntidade[i + 1]->setDano(0);
				}
				continue;
			}

			aux->executar();
			aux->imprimir();
		}

		verificaMortos();
	}

	bool ListaEntidade::getTodosMortos()
	{
		return todosMortos;
	}

	void ListaEntidade::verificaMortos()
	{
		Entidades::Entidade *aux = nullptr;
		int tam = objListaEntidade.getTamanho();
		todosMortos = true;

		for (int i = 0; i < tam; i++)
		{
			aux = objListaEntidade[i];

			if (aux->getId() == 4)
				continue;

			if (aux->getId() == 2 && aux->getMorreu() == true)
			{
				aux->setDano(0);
			}

			if (aux->getMorreu() == false && aux->getId() != 1)
			{
				todosMortos = false;
			}

			if (todosMortos == false && aux->getId() == 1)
			{
				if (aux->getMorreu() == false)
				{
					todosMortos = true;
				}
			}
		}
	}
}
