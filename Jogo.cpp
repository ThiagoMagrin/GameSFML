#include "Jogo.h"
#include "Fase1.h"
#include "Fase2.h"

Jogo::Jogo(){
    executar();
}

Jogo::~Jogo(){}

void Jogo::executar(){
    Fase1 objFase();
    Fase2 objFase2();
};
