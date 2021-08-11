#ifndef MENUPRINCIPALTELA_H
#define MENUPRINCIPALTELA_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

using namespace std;

class MenuPrincipalTela : public Tela{
    
    public:
        int exec(){
            resetCursor();
            
            this->setTitulo("Menu Principal");
            this->setTamanho(4,1);
            
            //void addOpcao(string opt, int linha, int coluna, int tipo, int outraTela, int codTela){            
            addOpcao("Cadastrar Cifra",0,0,4,1,1002);
            addOpcao("Pesquisar Cifra",1,0,4,1,1003);
            addOpcao("Sair",3,0,4,1,1000);
            
            return Tela:: exec();
            
            
        }
        
};

#endif
