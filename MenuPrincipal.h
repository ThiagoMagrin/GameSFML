#pragma once
#include "Menu.h"
#include "MenuRanking.h"

class MenuPrincipal : public Menu
{
private:
    MenuRanking menuR;

    int opcaoJogo;

public:
    MenuPrincipal();
    ~MenuPrincipal();

    void inicializar();
    void tratarEscolha(int escolha);
    void setOpcaoJogo(int opcao);
    int getOpcaoJogo();
};