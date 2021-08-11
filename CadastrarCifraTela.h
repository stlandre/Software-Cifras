#ifndef CADASTRARCIFRATELA_H
#define CADASTRARCIFRATELA_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "DaoCifra.h"

using namespace std;

class CadastrarCifraTela : public Tela{
    private:
        DaoCifra bdCifra;
        
    public:
        CadastrarCifraTela(){
            this->setTitulo("Cadastrar Cifra");
            this->setTamanho(13,2);
            
            //void addOpcao(string opt, int linha, int coluna, int tipo, int outraTela, int codTela){            
            addOpcao("Nome",0,0,1,0,0);
            addOpcao("Artista",1,0,1,0,0);
            addOpcao("Tom",2,0,1,0,0);
            addOpcao("Metronomo|bpm|",3,0,1,0,0);
            addOpcao("Instrumentos",4,0,1,0,0);
            addOpcao("Modo de Impressao",5,0,2,0,0);
            addOpcao("escrito",6,1,3,0,0);
            addOpcao("impresso",7,1,3,0,0);
            addOpcao("Pasta",8,0,1,0,0);
            addOpcao("ParaQuem",9,0,1,0,0);
            addOpcao("Observacoes",10,0,1,0,0);
            addOpcao("Cadastrar",12,0,4,1,2000);
            
            addOpcao("Voltar",12,1,4,1,1001);
               
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


            while(codTela==2000 && getResposta(0,0)==""){
                cout<< "\n\n     ";
                SetConsoleTextAttribute(hConsole, 207);//Vermelho com letra Branca
                cout<< "Nome e um campo obrigatorio!\n\n";
                SetConsoleTextAttribute(hConsole, cor2);
                system("pause");
                codTela= Tela:: exec();
            }            

            if(codTela== 2000){
                string nome= this->getResposta(0,0);
                string artista= this->getResposta(1,0);
                string tom= this->getResposta(2,0);
                
                
                stringstream metronomoS(this->getResposta(3,0));
                float metronomo;
                metronomoS>> metronomo;
                if(this->getResposta(3,0)=="" || this->getResposta(3,0)==" "){
                    metronomo= -1;
                }
                
                
                string instrumentos= this->getResposta(4,0);
                
                int modo;
                
                if((this->getOpcao(6,1))[8]== 'X'){
                    modo=0;
                }else{
                    if((this->getOpcao(7,1))[8]== 'X'){//[8]== 'X'){
                        modo=1;
                    }else{
                        modo=-1;
                    }
                }

                
                string pasta= this->getResposta(8,0);
                string paraQuem= this->getResposta(9,0);
                string observacoes= this->getResposta(10,0);
                
                Cifra c;
                c.setNome(nome);
                
                if(artista==""){
                    artista=" ";
                }
                c.setArtista(artista);
                
                if(tom==""){
                    tom= " ";
                }
                c.setTom(tom);
                
                c.setMetronomo(metronomo);
                
                if(instrumentos==""){
                    instrumentos= " ";
                }
                c.setInstrumentos(instrumentos);
                
                c.setModoDeImpressao(modo);
                
                if(pasta==""){
                    pasta= " ";
                }
                c.setPasta(pasta);
                
                if(paraQuem==""){
                    paraQuem= " ";
                }
                c.setParaQuem(paraQuem);
                
                if(observacoes==""){
                    observacoes= " ";
                }
                c.setObservacoes(observacoes);
                
                this->bdCifra.addCifra(c);

                cout<< "\n\n     ";
                SetConsoleTextAttribute(hConsole, 159);//Azul com letra Branca
                cout<< "Cadastro feito com sucesso!\n\n";
                SetConsoleTextAttribute(hConsole, cor2);
                system("pause");                
                
                
                                
                codTela= 1002;
            }
            
            return codTela;
        }
        
};

#endif
