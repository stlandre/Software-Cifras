#ifndef PESQUISARCIFRATELA_H
#define PESQUISARCIFRATELA_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "ClasseCifra.h"
#include "DaoCifra.h"

using namespace std;

class PesquisarCifraTela : public Tela{
    private:
        DaoCifra bdCifra;
    
    public:
        PesquisarCifraTela(){
            
            this->setTitulo("Pesquisar Cifra");
            this->setTamanho(14,2);
            this->ativarTabela();
            
            //Cifra c;
//            c.setId(1);
//            this->addCifraTabela(c);
//            
//            Cifra c2;
//            c2.setId(2);
//            this->addCifraTabela(c2);
//            
            //void addOpcao(string opt, int linha, int coluna, int tipo, int outraTela, int codTela){            
            addOpcao("Nome",0,0,1,0,0);
            addOpcao("Artista",1,0,1,0,0);
            addOpcao("Id",2,0,1,0,0);
            addOpcao("Tom",3,0,1,0,0);
            addOpcao("Metronomo|bpm|",4,0,1,0,0);
            addOpcao("Instrumentos",5,0,1,0,0);
            addOpcao("Modo de Impressao",6,0,2,0,0);
            addOpcao("escrito",7,1,3,0,0);
            addOpcao("impresso",8,1,3,0,0);
            addOpcao("Pasta",9,0,1,0,0);
            addOpcao("ParaQuem",10,0,1,0,0);
            addOpcao("Observacoes",11,0,1,0,0);
            addOpcao("Pesquisar",13,0,4,1,2001);
            
            addOpcao("Voltar",13,1,4,1,1001);

        }
        
        int exec(){
            resetCursor();
            resetResposta();

            int i,j;
            
            for(i=0; i< this->qtdLinha; i++){
                for(j=0; j< this->qtdColuna; j++){
                    if(rastreioDeOpt[i][j]== 3){
                        this->setOpcao(i,j, ' ');
                    }
                }
            }
            
            int codTela= Tela:: exec();
            
            while(codTela== 2001){
                string nome= this->getResposta(0,0);
                string artista= this->getResposta(1,0);
                string idS= this->getResposta(2,0);
                string tom= this->getResposta(3,0);
                
                string metronomoS= this->getResposta(4,0);
                
                string instrumentos= this->getResposta(5,0);
                
                string modoS;
                
                if((this->getOpcao(7,1))[8]== 'X'){
                    modoS="0";
                }else{
                    if((this->getOpcao(8,1))[8]== 'X'){//[8]== 'X'){
                        modoS="1";
                    }else{
                        modoS="";
                    }
                }

                
                string pasta= this->getResposta(9,0);
                string paraQuem= this->getResposta(10,0);
                string observacoes= this->getResposta(11,0);
                
                vector <Cifra> resultado;
                resultado= bdCifra.getCifras(nome, artista, idS, tom, metronomoS, instrumentos, modoS, pasta, paraQuem, observacoes);//bdCifra.getCifras("", "", "", "", "", "", "", "", "", "");
                //system("pause");
                this->tabela.emptyTabela();//Esvazia tabela
                this->tabela.addCifras(resultado );
                  
                codTela= Tela:: exec();
                                
            }
            
            //if(codTela!=1004){
            this->tabela.emptyTabela();
            //}
            
            return codTela;   
        }
        
};

#endif
