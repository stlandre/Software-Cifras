#ifndef TABELA_H
#define TABELA_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <vector>
#include "ClasseCifra.h"

using namespace std;

class Tabela{//Esta tabela terá 5 colunas. Então, temos 4 variáveis para controlar os espaços entre as colunas...
    private:
        vector <Cifra> cifras;
        
        string titulo1, titulo2, titulo3, titulo4, titulo5;
        int espaco1, espaco2, espaco3, espaco4;
        
        int cor1;
        int cor2;
        
        HANDLE hConsole;
        
    public:
        Tabela(){
            titulo1= "ID";
            titulo2= "NOME";
            titulo3= "ARTISTA";
            titulo4= "TOM";
            titulo5= "PARA";
            
            espaco1= titulo1.size();
            espaco2= titulo2.size();
            espaco3= titulo3.size();
            espaco4= titulo4.size();
            
            cor1= 32;
            cor2= 2;
        }
        
        void setCor(int cor1, int cor2){
            this->cor1= cor1;
            this->cor2= cor2;
        }
        
        void addCifra(Cifra c){
            this-> cifras.push_back(c);
        }
        
        void addCifras(vector <Cifra> c){
            int i;
            for(i=0; i<c.size(); i++){
                this-> cifras.push_back(c[i]);
            }
        }
        
        Cifra getCifra(int pos){
            if(pos< this->cifras.size()){
                return cifras[pos];
            }else{
                Cifra c;
                return c;
            }
        }
        
        void emptyTabela(){
            this-> cifras.resize(0);
        }
        
        int QtdLinhas(){
            return this->cifras.size();
        }
        
        int QtdCasas(int n){
            if(n% 10== n){
                return 1;
            }else{
                return 1+ QtdCasas(n/10);
            }
        }
        
        void ajustarEspacos(){
            int i;
            
            espaco1= titulo1.size();
            espaco2= titulo2.size();
            espaco3= titulo3.size();
            espaco4= titulo4.size();
                        
            for(i=0; i< this->cifras.size(); i++){
                
                if(QtdCasas(cifras[i].getId())> espaco1){
                    espaco1= QtdCasas(cifras[i].getId());
                }
                
                if(cifras[i].getNome().size()> espaco2){
                    espaco2= cifras[i].getNome().size();
                }
                
                if(cifras[i].getArtista().size()> espaco3){
                    espaco3= cifras[i].getArtista().size();
                }
                
                if(cifras[i].getTom().size()> espaco4){
                    espaco4= cifras[i].getTom().size();
                }
            }
            
            espaco1= espaco1 +2;
            espaco2= espaco2 +2;
            espaco3= espaco3 +2;
            espaco4= espaco4 +2;
        }
        
        void imprimirTabela(HANDLE *PhConsole, int qtdLinhaTela, int linha, int coluna){
            linha= linha- qtdLinhaTela;
            
            this->ajustarEspacos();
            
            int i,j;
            SetConsoleTextAttribute((*PhConsole),cor2);//cor2);
            
            cout<< "\n\n...............\n";
            cout<< this->cifras.size() <<" resultado(s)| \n";
            cout<< "..........................................................\n";
              
            cout<< titulo1;
            for(j= titulo1.size(); j<= espaco1; j++){
                cout<<" ";
            }  
            cout<< titulo2;
            for(j= titulo2.size(); j<= espaco2; j++){
                cout<<" ";
            }            

            cout<< titulo3;
            for(j= titulo3.size(); j<= espaco3; j++){
                cout<<" ";
            }            

            cout<< titulo4;
            for(j= titulo4.size(); j<= espaco4; j++){
                cout<<" ";
            }
            
            cout<< titulo5;
            
            cout<<"\n";

            for(i=0; i< this->cifras.size(); i++){
                
                if(i!= linha){
                    SetConsoleTextAttribute((*PhConsole),cor2);
                    
                    cout<< cifras[i].getId();
                    for(j= QtdCasas(cifras[i].getId()); j<= espaco1; j++){
                        cout<<" ";
                    }
                    
                    cout<< cifras[i].getNome();
                    for(j= cifras[i].getNome().size(); j<= espaco2; j++){
                        cout<<" ";
                    }            
        
                    cout<< cifras[i].getArtista();
                    for(j= cifras[i].getArtista().size(); j<= espaco3; j++){
                        cout<<" ";
                    }            
        
                    cout<< cifras[i].getTom();
                    for(j= cifras[i].getTom().size(); j<= espaco4; j++){
                        cout<<" ";
                    }
                    
                    cout<< cifras[i].getParaQuem();
                    
                    
                    cout<<"\n";
                }else{
                    SetConsoleTextAttribute((*PhConsole),cor1);
                    
                    cout<< cifras[i].getId();
                    for(j= QtdCasas(cifras[i].getId()); j<= espaco1; j++){
                        cout<<" ";
                    }
                    
                    cout<< cifras[i].getNome();
                    for(j= cifras[i].getNome().size(); j<= espaco2; j++){
                        cout<<" ";
                    }            
        
                    cout<< cifras[i].getArtista();
                    for(j= cifras[i].getArtista().size(); j<= espaco3; j++){
                        cout<<" ";
                    }            
        
                    cout<< cifras[i].getTom();
                    for(j= cifras[i].getTom().size(); j<= espaco4; j++){
                        cout<<" ";
                    }
                    
                    cout<< cifras[i].getParaQuem();
                    
                    SetConsoleTextAttribute((*PhConsole),cor2);
                    cout<<"\n";                    
                }
            }
            
        }
        
        
};

#endif
