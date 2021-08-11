#ifndef ALTERAROUEXCLUIRCIFRATELA_H
#define ALTERAROUEXCLUIRCIFRATELA_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "DaoCifra.h"
#include "ClasseCifra.h"

using namespace std;

class AlterarOuExcluirCifraTela : public Tela{
    private:
        DaoCifra bdCifra;
        Cifra cifra;
        
    public:
        AlterarOuExcluirCifraTela(){
            this->setTitulo("Alterar ou Excluir Cifra");
            this->setTamanho(14,2);
            
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
            addOpcao("Alterar",12,0,4,1,2002);
            
            addOpcao("Excluir",13,0,4,1,2003);
            addOpcao("Voltar",13,1,4,1,1003);
               
        }
        
        void setCifra(Cifra c){
            this->cifra= c;
        }
        
        int exec(){
            resetCursor();
            resetResposta();
  
            this->setResposta(0,0, this->cifra.getNome());
            this->setResposta(1,0, this->cifra.getArtista());
            this->setResposta(2,0, this->cifra.getTom());
            
            
            stringstream metronomoS;
            metronomoS<< this->cifra.getMetronomo();
            string metronomoStr= metronomoS.str();
            
            if(this->cifra.getMetronomo()<=0){
                metronomoStr= "";
            }
            this->setResposta(3,0, metronomoStr);
            
            
            this->setResposta(4,0, this->cifra.getInstrumentos());
            
            
            int modo= this->cifra.getModoDeImpressao();
            
            if(modo==0){
                this->setOpcao(6,1,'X');
                this->setOpcao(7,1,' ');
            }else{
                if(modo==1){//[8]== 'X'){
                    this->setOpcao(7,1,'X');
                    this->setOpcao(6,1,' ');
                }else{
                    this->setOpcao(6,1,' ');
                    this->setOpcao(7,1,' ');
                }
            }
    
            
            this->setResposta(8,0, this->cifra.getPasta());
            this->setResposta(9,0, this->cifra.getParaQuem());
            this->setResposta(10,0, this->cifra.getObservacoes());          
         
            int codTela= Tela:: exec();


            while(codTela==2002 && getResposta(0,0)==""){
                cout<< "\n\n     ";
                SetConsoleTextAttribute(hConsole, 207);//Vermelho com letra Branca
                cout<< "Nome e um campo obrigatorio!\n\n";
                SetConsoleTextAttribute(hConsole, cor2);
                system("pause");
                codTela= Tela:: exec();
            }            

            if(codTela== 2002){
                string nome= this->getResposta(0,0);
                string artista= this->getResposta(1,0);
                string tom= this->getResposta(2,0);
                
                fflush(stdin);
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
                c.setId(this->cifra.getId());
                
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
                
                this->bdCifra.alterarCifra(c, this->cifra.getId());

                cout<< "\n\n     ";
                SetConsoleTextAttribute(hConsole, 159);//Azul com letra Branca
                cout<< "Alteracao feita com sucesso!\n\n";
                SetConsoleTextAttribute(hConsole, cor2);
                system("pause");                
                
                
                                
                codTela= 1003;
            }
            
            if(codTela== 2003){
                string resposta;
                SetConsoleTextAttribute(hConsole, cor2);
                system("cls");
                
                cout<<"------------------------------\n    ";
                cout<< this-> titulo;
                cout<<"\n------------------------------\n"; 
                
                cout<< "\n\n     ";
                SetConsoleTextAttribute(hConsole, 207);//Vermelho com letra Branca
                cout<< "Deseja realmente excluir?\n\n";
                SetConsoleTextAttribute(hConsole, cor2);
                cout<< "Y ou N?  ";
                cin>> resposta;  
                
                if(resposta=="Y" || resposta=="y" || resposta=="sim" || resposta=="s" || resposta=="S"){
                    bdCifra.removeCifra(this->cifra.getId());
        
                    cout<< "\n\n     ";
                    SetConsoleTextAttribute(hConsole, 159);//Azul com letra Branca
                    cout<< "Remocao feita com sucesso!\n\n";
                    SetConsoleTextAttribute(hConsole, cor2);
                    system("pause");
                }   
                
                codTela= 1003;           
                               
            }
            
            return codTela;
        }
        
};

#endif
