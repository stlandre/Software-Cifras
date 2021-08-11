#ifndef DAOCIFRA_H
#define DAOCIFRA_H

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include "ClasseCifra.h"

using namespace std;

class DaoCifra{
	  
	  private:
	  		  static vector<Cifra> cifras;
	  		  static int qtdCifras;
	  		  static int nextId;
	  public:
             void inicializar();
	  		 int getqtdCifras();
	  		 void addCifra(Cifra c);
	  		 void removeCifra(int id);
	  		 vector <Cifra> getCifras();
	  		 vector <Cifra> getCifras(string nome, string artista, string idS, string tom, string metronomoS, string instrumentos, string modoS, string pasta, string paraQuem, string observacoes);
	  		 string strMaiuscula(string str);
	  		 void alterarCifra(Cifra c, int id);
	  
};

#endif
