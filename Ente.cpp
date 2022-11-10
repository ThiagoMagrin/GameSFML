#include "Ente.h"

Ente::Ente():id(0), pGrafico(pGrafico->getGerenciadorGrafico()) {}

Ente::Ente(int id): pGrafico(pGrafico->getGerenciadorGrafico()){
    id = id;
}

Ente::~Ente() {}

const int Ente::getId() const
{
    return id;
}

void Ente::setId(int i)
{
    id = i;
}

