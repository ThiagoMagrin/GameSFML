#include "Ente.h"

Ente::Ente(const int id): id(id) {}/*, pGrafico(pGrafico->getGerenciadorGrafico())*/

Ente::~Ente() {}

GerenciadorGrafico* Ente::pGraf = nullptr;

const int Ente::getId() const{
    return id;
}

void Ente::setID(const int i){
    id = i;
}

void Ente::setGraf(GerenciadorGrafico* pGg){
    pGraf = pGg;
}
