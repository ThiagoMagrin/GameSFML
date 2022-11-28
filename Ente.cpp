#include "Ente.h"

Ente::Ente() : id(id)
{
}

Ente::Ente(const int id) : id(id) {}

Ente::~Ente() {}

GerenciadorGrafico *Ente::pGraf = nullptr;

const int Ente::getId() const
{
    return id;
}

void Ente::setID(const int i)
{
    id = i;
}

void Ente::setGraf(GerenciadorGrafico *pGg)
{
    pGraf = pGg;
}
