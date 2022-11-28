#include "Jogo.h"
#include "Fase_Terra.h"
#include "Fase_Gelo.h"
#include "Gerenciador_Grafico.h"
#include <list>
#include <iterator>
#include <fstream>

using namespace std;
using namespace Fases;

Jogo::Jogo() : Ente(0), dois_jogadores(false)
{
    Ente::setGraf(GerenciadorGrafico::getGerenciadorGrafico());

    srand(time(NULL));

    executar();
}

Jogo::~Jogo()
{
    GerenciadorGrafico::deletarGerenciadorGrafico();

    if (objFase_Terra)
    {
        delete objFase_Terra;
    }
    objFase_Terra = nullptr;

    if (objFase_Gelo)
    {
        delete objFase_Gelo;
    }
    objFase_Gelo = nullptr;
}

void Jogo::executarFase1()
{
    menuD.inicializar();
    while (!menuD.getSelecionado())
    {
        menuD.executar();
    }

    dois_jogadores = menuD.getDoisJogadores();

    objFase_Terra = new Fase_Terra(dois_jogadores);
    objFase_Terra->executar();

    if (objFase_Terra->getSobreviveram())
    {
        if (dois_jogadores == true)
        {
            executarFase2(objFase_Terra->getJogador().getPontuacao(), objFase_Terra->getJogador2().getPontuacao(), objFase_Terra->getJogador().getVida(), objFase_Terra->getJogador2().getVida());
        }
        else
        {
            executarFase2(objFase_Terra->getJogador().getPontuacao(), 0, objFase_Terra->getJogador().getVida(), 0);
        }
    }
}

void Jogo::executarFase2(int p1, int p2, int v1, int v2)
{
    if (p1 == 0 && p2 == 0)
    {
        menuD.inicializar();
        while (!menuD.getSelecionado())
        {
            menuD.executar();
        }
    }
    dois_jogadores = menuD.getDoisJogadores();

    objFase_Gelo = new Fase_Gelo(dois_jogadores);

    objFase_Gelo->executar(p1, p2, v1, v2);

    if (objFase_Gelo->getSobreviveram())
    {
        objFase_Gelo->gravarPontuacao();
    }
}

void Jogo::executar()
{
    menuP.inicializar();
    while (pGraf->verificaJanelaAberta())
    {
        menuP.executar();

        int escolha = menuP.getOpcaoJogo();

        switch (escolha)
        {
        case 1:
            executarFase1();
            break;

        case 2:
            executarFase2(0, 0, 3000, 3000);
            break;
        }

        menuP.setOpcaoJogo(0);
    }
};