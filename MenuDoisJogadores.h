#pragma once
#include "Menu.h"

class MenuDoisJogadores : public Menu
{
private:
    bool doisJogadores, selecionado;

public:
    MenuDoisJogadores();
    ~MenuDoisJogadores();

    void inicializar();
    void tratarEscolha(int escolha);

    bool getDoisJogadores();
    bool getSelecionado();
};