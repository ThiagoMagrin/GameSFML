#include "Jogo.h"
#include "Fase_Terra.h"
#include "Fase_Gelo.h"
#include "Gerenciador_Grafico.h"

using namespace Fases;

Jogo::Jogo() : Ente(0) {
    Ente::setGraf(GerenciadorGrafico::getGerenciadorGrafico());
   // menu = new Menu();
    executar();
}

Jogo::~Jogo(){
   

    delete objFase_Terra;
    objFase_Terra = nullptr;

    delete objFase_Gelo;
    objFase_Gelo = nullptr;

  //  delete menu;
  //  menu = nullptr;

    GerenciadorGrafico::deletarGerenciadorGrafico();
}
void Jogo::executarFase1()
{
    objFase_Terra = new Fase_Terra();
    objFase_Terra->executar();

    executarFase2();
}
void Jogo::executarFase2()
{
    objFase_Gelo = new Fase_Gelo();
    objFase_Gelo->executar();

}

void Jogo::executar()
{
    int op = 0;
   
   // menu->run_menu();
   // op = menu->getOpcao();
    while (pGraf->verificaJanelaAberta())
    {
    menu.run_menu();
    op = menu.getOpcao();
    switch (op){
    case 1:
        executarFase1();
        break;
    case 2:
        executarFase2();
        break;
    case 3:
        break;
    case 4:
        pGraf->fecharJanela();
        break;
    default:
        break;
    }
    }
    //objFase_Terra = new Fase_Terra();
    //objFase_Terra->executar();

    //objFase_Gelo = new Fase_Gelo();
    //objFase_Gelo->executar();
};
