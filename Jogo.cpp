#include "Jogo.h"
#include "Fase_Terra.h"
#include "Fase_Gelo.h"
#include "Gerenciador_Grafico.h"

using namespace Fases;

Jogo::Jogo() : Ente(0) {
   // Ente::setGraf(GerenciadorGrafico::getGerenciadorGrafico());

    //executar();
}

Jogo::~Jogo(){
   

    delete objFase_Terra;
    objFase_Terra = nullptr;

    delete objFase_Gelo;
    objFase_Gelo = nullptr;
    //GerenciadorGrafico::deletarGerenciadorGrafico();
}
void Jogo::executarFase1()
{
    objFase_Terra = new Fase_Terra();
    objFase_Terra->executar();

    objFase_Gelo = new Fase_Gelo();
    objFase_Gelo->executar();
}
void Jogo::executarFase2()
{
    objFase_Gelo = new Fase_Gelo();
    objFase_Gelo->executar();

}
/*
void Jogo::executar(){
    objFase_Terra = new Fase_Terra();
    objFase_Terra->executar();

    objFase_Gelo = new Fase_Gelo();
    objFase_Gelo->executar();
};*/
