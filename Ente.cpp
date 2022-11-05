#include "Ente.h"

Ente::Ente():id(0), pGrafico(pGrafico->getGerenciadorGrafico()) {}

Ente::~Ente() {}

Ente::Ente(int id):pGrafico(pGrafico->getGerenciadorGrafico()){
    id = id;
}
