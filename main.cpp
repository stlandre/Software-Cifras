#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Tela.h"
#include "MenuPrincipalTela.h"
#include "CadastrarCifraTela.h"
#include "PesquisarCifraTela.h"
#include "AlterarOuExcluirCifraTela.h"
#include "DaoCifra.h"

using namespace std;

int main(){
    
    DaoCifra bdCifra;
    bdCifra.inicializar();
//    
    MenuPrincipalTela mpt;
    CadastrarCifraTela CCifraTela;
    PesquisarCifraTela PCifraTela;
    AlterarOuExcluirCifraTela AECifraTela;
    
    int i;
    int codTela=1001;
    
    do{
        switch(codTela){
            case 1001:
                codTela= mpt.exec();
                break;
                
            case 1002:
                codTela= CCifraTela.exec();
                break;
                
            case 1003:
                codTela= PCifraTela.exec();
                break;
                 
            case 1004:    
                AECifraTela.setCifra(PCifraTela.getCifraSelecionada());
                codTela= AECifraTela.exec();
                break;
        }
    }while(codTela!=1000);
    

//    string teste="";
//    stringstream testeS(teste);
//    float n;
//    testeS>> n;
//    
//    cout<<n << endl;
        
    
//    
//	  int k;
//      HANDLE hConsole;  
//      
//	  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	  for(k=0; k<16; k++){
//               SetConsoleTextAttribute(hConsole, k);
//               cout<<"Cor: "<<k<<" Teste\n";	  
//               //system("cls");
//      }
//	  _sleep(0);
//      SetConsoleTextAttribute(hConsole, 32);
//      cout<<"Teste\n";
//      
//   
//	  SetConsoleTextAttribute(hConsole, 2);

    system("pause");
    return 0;
}
