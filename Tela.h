#ifndef TELA_H
#define TELA_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <vector>
#include "Tabela.h"
#include "ClasseCifra.h"

using namespace std;

class Tela{
    protected:
        
        int cursor[2];//linha e coluna
        int cursorAnt[2];
        string titulo;
        vector <string> options;
        int rastreioDeOpt[20][20];//
        string opcoes[20][20];
        string respostas[20][20];
        //Tela telas[1];
        //int rastreioDeTela[1][2];
        //int qtdDeTelas;
        //int digitar;
        int qtdLinha;
        int qtdColuna;
        int qtdLinhaComTabela;
        
        int tabelaAtiva;
        Tabela tabela;
        Cifra cifraSelecionada; //Poderia ser outra classe. Classe Produtos, por exemplo, de um super-mercado (contendo preço, quantidade, marca, etc.)
        
        int input;
        
        int cor1;
        int cor2;
        HANDLE hConsole;
        HANDLE *PhConsole;
        
    public:
        Tela(){
            cursor[0]=0;
            cursor[1]=0;
            cursorAnt[0]=0;
            cursorAnt[1]=0;
            rastreioDeOpt[0][0]=0;
            opcoes[0][0]="";
            respostas[0][0]="";
            //qtdDeTelas=0;
            qtdLinha=1;
            qtdColuna=1;
            qtdLinhaComTabela=1;
            
            tabelaAtiva=0;
            //digitar=0;
            
            cor1= 32;
            cor2= 2;  
            
            PhConsole= &hConsole;       
        }
        
        void ativarTabela(){
            this-> tabelaAtiva= 1;
        }
        
        void desativarTabela(){
            this-> tabelaAtiva= 0;
        }
        
        Cifra getCifraSelecionada(){
            return this->cifraSelecionada;
        }
        
        void addCifraTabela(Cifra c){
            tabela.addCifra(c);
        }
        
        void setTitulo(string titulo){
            this-> titulo= titulo;
        }
        
        void setCor(int cor1,int cor2){
            this->cor1= cor1;
            this->cor2= cor2;
        }
        
        
        void setTamanho(int l, int c){
            if(l>0 && c>0){
                this-> qtdLinha= l;
                this-> qtdColuna= c;
                this-> qtdLinhaComTabela= l;
                
                int i,j;
                
                for(i=0; i< l; i++){
                    for(j=0; j< c; j++){
                        this-> rastreioDeOpt[i][j]=0;
                        this-> opcoes[i][j]=" ";
                        this-> respostas[i][j]= "";
                    }
                }
            }
            
        }
        
        void addOpcao(string opt, int linha, int coluna, int tipo, int outraTela, int codTela){
            if( (linha< this->qtdLinha)&&(coluna< this->qtdColuna)&&(linha>=0)&&(coluna>=0) ){
                
                if(rastreioDeOpt[linha][coluna]==0){
                    rastreioDeOpt[linha][coluna]= tipo;
                
                    switch(tipo){
                        
                        case 1:
                            opcoes[linha][coluna]= opt+":";
                            rastreioDeOpt[linha][coluna+1]= 11;
                            break;
                        case 2:
                            opcoes[linha][coluna]= opt+":";
                            rastreioDeOpt[linha][coluna+1]= 21;
                            break;
                        case 3:
                            opcoes[linha][coluna]= "       [ ]"+ opt;
                            break;
                        case 4:
                            opcoes[linha][coluna]= opt;//Parei aqui. Olhar os atributos que conseguem levar à uma tela
                            break;
                    }
                    
                    if(outraTela==1){
                        rastreioDeOpt[linha][coluna]= codTela;
                    }
                    
//                    if(tipo>=1000){
//                        opcoes[linha][coluna]= opt;
//                    }
                }
                
                
                
            }
            
        }
        
        void setOpcao(int l, int c, char a){
            this->opcoes[l][c][8]=a;
        }
        
        string getOpcao(int l, int c){
            return this->opcoes[l][c];
        }
        
        void setResposta(int l, int c, string resposta){
            this-> respostas[l][c]= resposta;
        }
        
        string getResposta(int l, int c){
            return this-> respostas[l][c];
        }
        
        void resetResposta(){
                int i,j;
                
                for(i=0; i< this->qtdLinha; i++){
                    for(j=0; j< this->qtdColuna; j++){
                        this-> respostas[i][j]= "";
                    }
                }            
        }
        
        void resetCursor(){
            this->cursor[0]= 0;
            this->cursor[1]= 0;
        }
        
        void setCursor(){
            input= getch();
            
            int linha= this->cursor[0];
            int coluna= this->cursor[1];
            
            int i,j;
            
            if(this->tabelaAtiva== 1){
                this->qtdLinhaComTabela= this->qtdLinha + this->tabela.QtdLinhas();
            }
            
            if(input==13){
                if(rastreioDeOpt[linha][coluna]==3){
                    if(this->rastreioDeOpt[linha][coluna]==3){
                        while(this->rastreioDeOpt[linha][coluna]!=21 && linha>=0){
                            linha--;
                        }
                    }
                    //Estes dois if's estão diretamente relacionados...
                    if(this->rastreioDeOpt[linha][coluna]==21){
                        coluna--;
                    }
                }
                
            }
            

            
            if(input==224){
                input= getch();
                
                switch(input){
                    case 72://cima

                        if( (linha)>=0 && this->rastreioDeOpt[linha][coluna]==21){ //Utilizando Curto-Circuito
                            i=linha+1;
                            
                            while(this->rastreioDeOpt[i][coluna]==3){
                                i++;
                            }
                            
                            if(this->rastreioDeOpt[i][coluna]!=3){
                                i--;
                            }
                            
                            linha=i;
                        }else{
                            
                            if(this-> tabelaAtiva== 0){
                                if(linha==0){
    
                                    i= this->qtdLinha-1;
    
                                    j=0;
                                    
                                    while(this->rastreioDeOpt[i][j]!=1 && this->rastreioDeOpt[i][j]!=2 && this->rastreioDeOpt[i][j]<1000 && i>0){
                                        while((this->rastreioDeOpt[i][j]!=1 && this->rastreioDeOpt[i][j]!=2 && this->rastreioDeOpt[i][j]<1000)&& j< this-> qtdColuna-1 ){
                                            j++;
                                        }
                                        
                                        if(this->rastreioDeOpt[i][j]==1 || this->rastreioDeOpt[i][j]==2 || this->rastreioDeOpt[i][j]>=1000){
                                            linha=i;
                                            coluna=j;
                                            break;
                                            
                                        }else{
                                            j=0;
                                            i--;
                                        }
                                        
                                    }
                                    
                                    linha= i;
                                }else{
                                    //Parei aqui 05-07-14 15:48hs
    
                                    linha--;
                
                                    while( (this->rastreioDeOpt[linha][coluna]==0 || this->rastreioDeOpt[linha][coluna]==11) && linha!=0){
                                        
                                        if(this->rastreioDeOpt[linha][coluna]==0){
                                            linha--;  
                                        }
                                        
                                        if(this->rastreioDeOpt[linha][coluna]==11  || this->rastreioDeOpt[linha][coluna]==21 || this->rastreioDeOpt[linha][coluna]==3){
                                            coluna= 0;
                                        }  
                                    }           
                                }
                                
                            }else{
                                if(linha== 0){
                                    linha= this-> qtdLinhaComTabela-1;
                                    coluna= 0;
                                }else{
                                    if(linha<= this->qtdLinha-1){
                                        linha--;
                    
                                        while( (this->rastreioDeOpt[linha][coluna]==0 || this->rastreioDeOpt[linha][coluna]==11) && linha!=0){
                                            
                                            if(this->rastreioDeOpt[linha][coluna]==0){
                                                linha--;  
                                            }
                                            
                                            if(this->rastreioDeOpt[linha][coluna]==11  || this->rastreioDeOpt[linha][coluna]==21 || this->rastreioDeOpt[linha][coluna]==3){
                                                coluna= 0;
                                            }  
                                        }                           
                                    }else{
                                        linha--;
                                        coluna= 0;
                                    }         
                                }
                            }
                                                                

                        }
                        
                        break;
                        
                    case 80://baixo
                        
                        if(this->rastreioDeOpt[linha][coluna]==3 || this->rastreioDeOpt[linha][coluna]==21){
                            i=linha+1;
                            
                            if(this->rastreioDeOpt[i][coluna]!=3){
                                
                                i--;
                                while(this->rastreioDeOpt[i][coluna]!=21){
                                    i--;
                                }
                                
//                                if(this->rastreioDeOpt[i][coluna]==21){
//                                    i++; //Parei aqui 13-12-14
//                                }
                                
                                //i++;
                                //linha=i;
                            }//else{
                                //linha=i;
                            //}
                            
                            linha=i;
                            
                        }else{
                            
                            if(this->tabelaAtiva== 0){
                                if(linha== this->qtdLinha-1){
                                    linha=0;
                                    coluna=0;
                                }else{
    
                                    i=linha+1;
                                    
                                    if((this->rastreioDeOpt[linha][coluna]==1 || this->rastreioDeOpt[linha][coluna]==2 || this->rastreioDeOpt[linha][coluna]>=1000 ) && (this->rastreioDeOpt[i][coluna]==1 || this->rastreioDeOpt[i][coluna]==2 || this->rastreioDeOpt[i][coluna]>=1000) ){
                                        linha++;//Parei aqui 05-07-14 15:49hs
                                                // Verificar para qual tipo de opção que o cursor irá apontar...
                                    }else{
                                    
                                        while(this->rastreioDeOpt[i][coluna]==0 && i!= this->qtdLinha-1){
                                            i++;
                                        }
                                        
                                        if(i== this->qtdLinha-1 && this->rastreioDeOpt[i][coluna]==0){
                                            i=0;
                                        }
                                        
                                        linha= i;
                                        
                                    }
                                }
                            }else{
                                if(linha== this->qtdLinhaComTabela-1){
                                    linha=0;
                                    coluna=0;
                                }else{
                                    
                                    if(linha< this->qtdLinha-1){
                                        i=linha+1;
                                        
                                        if((this->rastreioDeOpt[linha][coluna]==1 || this->rastreioDeOpt[linha][coluna]==2 || this->rastreioDeOpt[linha][coluna]>=1000 ) && (this->rastreioDeOpt[i][coluna]==1 || this->rastreioDeOpt[i][coluna]==2 || this->rastreioDeOpt[i][coluna]>=1000) ){
                                            linha++;//Parei aqui 05-07-14 15:49hs
                                                    // Verificar para qual tipo de opção que o cursor irá apontar...
                                        }else{
                                        
                                            while(this->rastreioDeOpt[i][coluna]==0 && i!= this->qtdLinha-1){
                                                i++;
                                            }
                                            
                                            if(i== this->qtdLinha-1 && this->rastreioDeOpt[i][coluna]==0){
                                                i=0;
                                            }
                                            
                                            linha= i;
                                            
                                        }
                                    }else{
                                        linha++;
                                        coluna= 0;
                                    }
                                }
                                
                            }   
                            
                        }
                        break;
                        
                    case 77://direita
                        
                        
                        if(this->rastreioDeOpt[linha][coluna]==1){
                            coluna++;
                        }else{
                            
                            if(this->rastreioDeOpt[linha][coluna]==2){
                                linha++;
                                coluna++;
                                
                                if(this->rastreioDeOpt[linha][coluna]!=3){
                                    linha--;
                                    coluna--;
                                }
                            }else{
                                
                                if(this->rastreioDeOpt[linha][coluna]==3){
                                    while(this->rastreioDeOpt[linha][coluna]!=21 && linha>=0){
                                        linha--;
                                    }
                                }
                                //Estes dois if's estão diretamente relacionados...
                                if(this->rastreioDeOpt[linha][coluna]==21){
                                    coluna--;
                                }else{
                                    j= coluna;
                                    if(j!= this->qtdColuna-1){
                                        j++;
                                    }else{
                                        j=0;
                                    }
                                    
                                    while(this->rastreioDeOpt[linha][j]==0 && j<(this->qtdColuna-1) ){
                                        j++;
                                    }
                                    
                                    if(this->rastreioDeOpt[linha][j]==0 && j==(this->qtdColuna-1) ){
                                        j=0;
                                    }
                                    
                                    coluna= j;
                                }
                                
                            }
                        }
                        
                        break;
                    case 75://esquerda

                        if(this->rastreioDeOpt[linha][coluna]==3){
                            while(this->rastreioDeOpt[linha][coluna]!=21 && linha>=0){
                                linha--;
                            }
                        }
                        //Estes dois if's estão diretamente relacionados...
                        if(this->rastreioDeOpt[linha][coluna]==21){
                            coluna--;
                        }else{                        
                            
                            if(this->rastreioDeOpt[linha][coluna]!=1 && this->rastreioDeOpt[linha][coluna]!=2){ 
                                j=coluna;
                                if(j!=0){
                                    j--;
                                }else{
                                    j= this->qtdColuna-1;
                                }
                                
                                while(this->rastreioDeOpt[linha][j]==0){
                                    j--;
                                }
                                
                                coluna= j;
                                
                            }
                        }
                        
                        break;
                    
                }
            }
            
            this->cursorAnt[0]= this->cursor[0];
            this->cursorAnt[1]= this->cursor[1];
            
            this->cursor[0]= linha;
            this->cursor[1]= coluna;
            
            if(this->rastreioDeOpt[this->cursor[0]][this->cursor[1]]== 3 || this->rastreioDeOpt[this->cursor[0]][this->cursor[1]]== 21){
                i= this->cursor[0];
                j= this->cursor[1]; 
                
                while(this->rastreioDeOpt[i][j]==3 && i< this->qtdLinha-1){
                    i--;
                }               
                
                i++;
                
                while(this->rastreioDeOpt[i][j]==3 && i< this->qtdLinha-1){
                    if(i!= this->cursor[0]){
                        (this->opcoes[i][j])[8]= ' ';
                    }else{
                        (this->opcoes[i][j])[8]= 'X';
                    }
                    i++;
                }    
                                
            }
            
//            if(this->rastreioDeOpt[this->cursorAnt[0]][this->cursorAnt[1]]== 3 && this->rastreioDeOpt[this->cursor[0]][this->cursor[1]]== 2){
//                i= this->cursor[0] +1;
//                j= this->cursorAnt[1];
//                
//                //parei aqui... 25-12-14
//            }
            
        }
        
        virtual int exec(){
            //HANDLE hConsole;
            hConsole= GetStdHandle (STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole,cor2);
            this-> input=0;
            
            int i,j;
            int codTela;
            //int select3;
            int temOpt=0;
            int entrada=0;
            


            while(this-> input!=13){
                entrada=0;
                
                if(rastreioDeOpt[cursor[0]][cursor[1]]==11){
                    entrada=1;
                }
                
                system("cls");
                
                cout<<"------------------------------\n    ";
                cout<< this-> titulo;
                cout<<"\n------------------------------\n";
                
                for(i=0; i< this->qtdLinha; i++){
                    for(j=0; j< this->qtdColuna; j++){
                        if(rastreioDeOpt[i][j]!=0){//Se isso for verdade, quer dizer que existe alguma opcao no atributo 'opcoes'
                            temOpt=1;

                            

                            if(entrada== 0){
                                if(i== cursor[0] && j== cursor[1]){      
                                                   
                                    
                                    if(rastreioDeOpt[i][j]>=1000 || rastreioDeOpt[i][j]>=2000){
                                        SetConsoleTextAttribute(hConsole,cor1);
                                        cout<< opcoes[i][j];
                                        SetConsoleTextAttribute(hConsole,cor2);
                                        cout<< "    ";
                                        cout<< respostas[i][j];
                                                                        
                                    }else{
                                        
//                                        select3= this->rastreioDeOpt[i][j];
//                                        
//                                        if(select3== 3){
//                                            (opcoes[i][j])[8]='X';
//                                        }                                        
                                        
                                        SetConsoleTextAttribute(hConsole,cor1);
                                        cout<< opcoes[i][j];
                                        SetConsoleTextAttribute(hConsole,cor2);
                                        cout<< " ";
                                        cout<< respostas[i][j];
                                    }
                                }else{
                                    if(rastreioDeOpt[i][j]>=1000 || rastreioDeOpt[i][j]>=2000){
                                        cout<< opcoes[i][j];
                                        cout<< "    ";
                                        cout<< respostas[i][j];                                    
                                    }else{
                                        
//                                        if(this->rastreioDeOpt[i][j]== 3){
//                                            (opcoes[i][j])[8]=' ';
//                                        }
                                        
                                        cout<< opcoes[i][j];
                                        cout<< " ";
                                        cout<< respostas[i][j];
                                    }
                                }
                            }else{
                                
                                if(i== cursorAnt[0] && j== cursorAnt[1]){      
                                    SetConsoleTextAttribute(hConsole,cor1);
                                    cout<< opcoes[i][j];
                                    SetConsoleTextAttribute(hConsole,cor2);
                                    cout<< " ";
                                
                                    getline(cin,respostas[i][j]);
                                    
                                    this-> cursor[0]= this-> cursorAnt[0];
                                    this-> cursor[1]= this-> cursorAnt[1];
                                
                                }else{
                                    if(rastreioDeOpt[i][j]>=1000 || rastreioDeOpt[i][j]>=2000){
                                        cout<< opcoes[i][j];
                                        cout<< "    ";
                                        cout<< respostas[i][j];                                    
                                    }else{
                                        
//                                        if(this->rastreioDeOpt[i][j]== 3){
//                                            (opcoes[i][j])[8]=' ';
//                                        }
                                        
                                        cout<< opcoes[i][j];
                                        cout<< " ";
                                        cout<< respostas[i][j];
                                    }
                                } 
                                
//                                i=0;
//                                entrada=0;  
                                break;                             
                            }

                        }
                        
                    }
                    
//                    if(entrada==1){
//                        break;
//                    }
                    
                    //if(/*temOpt==1 &&*/ entrada!=1){
                        cout<<"\n";
                    //    temOpt=0;
                    //}
                    
                    
                }
                
                if(this->tabelaAtiva== 1){
                    tabela.imprimirTabela(PhConsole, this-> qtdLinha, cursor[0], cursor[1]);

                    //cout<<"\n"<<this-> qtdLinha<<" "  << cursor[0] <<" "<<this->tabela.QtdLinhas()<<" "<< this->qtdLinhaComTabela<<  endl;
                    //Verificar esta parte...
                }
                
                if(entrada!=1){
                    setCursor();
                }
                codTela= this->rastreioDeOpt[cursor[0]][cursor[1]];

                if(cursor[0]- this-> qtdLinha >=0 && tabelaAtiva==1){
                    codTela= 1004;//Indica que algum item da tabela foi selecionado (vai para tela 'Aleterar ou excluir Cifra'
                    this->cifraSelecionada= tabela.getCifra(cursor[0]- this-> qtdLinha);
                }                

                if(codTela<1000 || codTela==3){
                    this->input=0;
                }  
                
                             
            }

            return codTela;
        }
        
        
          
};

#endif
