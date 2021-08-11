#include "DaoCifra.h"
#include "ClasseCifra.h"

vector <Cifra> DaoCifra:: cifras(0);
int DaoCifra:: qtdCifras;
int DaoCifra:: nextId;

string DaoCifra::strMaiuscula(string str){
		int j;
		char c[str.size()+1];
		
		for(j=0; j< str.size(); j++){
				c[j]= str[j];	
		}
		
		strupr(c);
		
		for(j=0; j< str.size(); j++){
				str[j]= c[j];	
		}
				
		return str;
}


void DaoCifra:: inicializar(){
    ifstream file0;
    file0.open("Cifra.txt");
    string cifraStr;
    
    while(!file0.eof()){
        getline(file0, cifraStr);
        if(cifraStr.size()!=0){
                Cifra c1;
                Cifra c;
                c= c1.CifraConvertStr(cifraStr);
                
                this-> cifras.push_back(c1.CifraConvertStr(cifraStr));            
        }
    }
    
    file0.close();
    
    ifstream file1;
    file1.open("Cifra-QtdCifras.txt");
    
    string qtdCifrasS;
    getline(file1, qtdCifrasS);
    
    stringstream qtdCsS (qtdCifrasS);
    qtdCsS>> this-> qtdCifras;    
    
    file1.close();
}


int DaoCifra:: getqtdCifras(){
    ifstream file1;
    file1.open("Cifra-QtdCifras.txt");
    
    string qtdCifrasS;
    getline(file1, qtdCifrasS);
    
    stringstream qtdCsS (qtdCifrasS);
    qtdCsS>> this-> qtdCifras;
    
    file1.close();
    
	return this-> qtdCifras;
}


void DaoCifra:: addCifra(Cifra c){

     
     ifstream file2;
	 file2.open("CifraID.txt");
	 
     string nextIdS;
     getline(file2, nextIdS);
     
     stringstream nIdS(nextIdS); 
     nIdS>>nextId;
	 
     file2.close();
	 
     c.setId(nextId);
	 this-> nextId++;
	 
	 //escrevendo no arquivo 'CifraID.txt' o próximo Id
	 ofstream file3;
	 file3.open("CifraID.txt");
	 stringstream IdTemp;
     IdTemp<< nextId;
	 nextIdS= IdTemp.str();
     file3<< nextIdS;
     file3.close();
	
     
     //abrindo o arquivo 'Cifra-QtdCifras.txt' para pegar a quantidade de cifras
     ifstream file4;
     file4.open("Cifra-QtdCifras.txt");
     
     string qtdCifrasS;
     getline(file4, qtdCifrasS);
     
     stringstream qCsS(qtdCifrasS); 
     qCsS>> this-> qtdCifras;
	 
     file4.close();
	 
     this-> qtdCifras++;
	 
	 ofstream file5;
	 file5.open("Cifra-QtdCifras.txt");
	 
	 stringstream qCsS2;
     qCsS2<< this-> qtdCifras;
	 qtdCifrasS= qCsS2.str();
     file5<< qtdCifrasS;
	 
     file5.close();
	 
	 
	 //add em arquivo
	 ofstream file;
	 file.open("Cifra.txt", ios:: app);
	 string cifraS= c.strCifra();
	 file<< cifraS;
	 file.close();
	 
	 this-> cifras.push_back(c);
}

void DaoCifra:: removeCifra(int id){

	int i;
	int achou=0;
	//Cliente cs[this->qtdClientes-1];
	
	for(i=0; i< this-> cifras.size(); i++){
 			  
              if(achou==1){
                     Cifra c;
    				 c=cifras[i];
    				 cifras[i]= cifras[i-1];
    				 cifras[i-1]= c;
    				   
              }
 			  
 			  
			  if(this->cifras[i].getId()== id && achou==0){
    				 achou=1;
              		 
			  } 
			  
			  
 	}
 	
 	if(achou==1){
            cifras.resize(this-> qtdCifras-1);
            this->qtdCifras--;
    }
 	
 	ofstream file1;
 	
    if(this-> qtdCifras!=0){
            for(i=0; i< this-> cifras.size(); i++){
                    if(i==0){
                            file1.open("Cifra.txt");
                            string cifraStr= this-> cifras[i].strCifra();
                            file1<< cifraStr;
                            
                            file1.close();    
                    }else{
                            if(i==1){
                                    file1.open("Cifra.txt", ios:: app);
                            }
                            
                            string cifraStr= this-> cifras[i].strCifra();
                            file1<< cifraStr;
                            
                            if(i== this-> cifras.size()-1){
                                    file1.close();
                            }
                    }
                    
            } 	
    }else{
            file1.open("Cifra.txt");
            file1<< " ";
            file1.close();
    }
    
	stringstream ss;
	ss<< this-> qtdCifras;
	string qtdCifrasS;
	qtdCifrasS= ss.str();
	
	ofstream file2;
	file2.open("Cifra-QtdCifras.txt");
	file2<< qtdCifrasS;
	file2.close();
	
}

vector <Cifra> DaoCifra:: getCifras(){
	   
  				return this-> cifras;
}

vector <Cifra> DaoCifra:: getCifras(string nome, string artista, string idS, string tom, string metronomoS, string instrumentos, string modoS, string pasta, string paraQuem, string observacoes){
        
//            ifstream file1;
//            file1.open("Cifra-QtdCifras.txt");
//            
//            string qtdCifrasS;
//            getline(file1, qtdCifrasS);
//            
//            stringstream qtdCsS (qtdCifrasS);
//            qtdCsS>> this-> qtdCifras;    
//            
//            file1.close();
		
        
        	vector <Cifra> cif(0);//vector <Cliente> cli(0);
			int i;

			int searchForNome=0;
			int searchForArtista=0;
            int searchForId=0;
			int searchForTom=0;
			int searchForMetronomo=0;
			int searchForInstrumentos=0;
			int searchForModo=0;
			int searchForPasta=0;
			int searchForParaQuem=0;
			int searchForObservacoes=0;
			
			int idInt;
			int metronomoInt;
			int modoInt;
			int tamanhoNome= nome.size();
			int tamanhoArtista= artista.size();
			int tamanhoInstrumentos= instrumentos.size();
			int tamanhoParaQuem= paraQuem.size();
			int tamanhoObservacoes= observacoes.size();
			
			if(idS!=""){
					stringstream idStr(idS);
					idStr>> idInt;
					searchForId=1;
			}
			
			if(nome!=""){
					nome= strMaiuscula(nome);										
					searchForNome=1;
			}
			
			if(artista!=""){
					artista= strMaiuscula(artista);
					searchForArtista=1;
			}
			
			if(tom!=""){
                    tom= strMaiuscula(tom);
                    searchForTom=1;
            }

			if(metronomoS!=""){
					stringstream metronomoStr(metronomoS);
					metronomoStr>> metronomoInt;
					searchForMetronomo=1;
            }

			
			if(instrumentos!=""){
                    instrumentos= strMaiuscula(instrumentos);
                    searchForInstrumentos=1;
            }

			
			if(modoS!=""){
					stringstream modoStr(modoS);
					modoStr>> modoInt;
					searchForModo=1;
            }

			if(pasta!=""){
                    pasta= strMaiuscula(pasta);
                    searchForPasta=1;
            }   
            
			if(paraQuem!=""){
                    paraQuem= strMaiuscula(paraQuem);
                    searchForParaQuem=1;
            }   
            
			if(observacoes!=""){
                    observacoes= strMaiuscula(observacoes);
                    searchForObservacoes=1;
            }                              
			
			string nomeCmp;
			string artistaCmp;
			int idCmp;
			string tomCmp;
			float metronomoCmp;
			string instrumentosCmp;
			int modoCmp;
			string pastaCmp;
			string paraQuemCmp;
			string observacoesCmp;

//			cout<< searchForNome <<endl;
//			cout<< searchForArtista <<endl;
//            cout<< searchForId <<endl;
//			cout<< searchForTom <<endl;
//			cout<< searchForMetronomo <<endl;
//			cout<< searchForInstrumentos <<endl;
//			cout<< searchForModo <<endl;
//			cout<< searchForPasta <<endl;
//			cout<< searchForParaQuem <<endl;
//			cout<< searchForObservacoes <<endl;			
			
	//		cout << this->qtdCifras << endl;
//			cout << this->cifras[this->qtdCifras-1].strCifra() << endl;
//			
			for(i=0; i< this->qtdCifras; i++){
					nomeCmp= strMaiuscula(this->cifras[i].getNome().substr(0,tamanhoNome));
        			artistaCmp= strMaiuscula(this->cifras[i].getArtista().substr(0,tamanhoArtista));
        			idCmp= this->cifras[i].getId();
        		    tomCmp= strMaiuscula(this->cifras[i].getTom());
        			metronomoCmp= this->cifras[i].getMetronomo();
        			instrumentosCmp= strMaiuscula(this->cifras[i].getInstrumentos().substr(0,tamanhoInstrumentos));
        			modoCmp= this->cifras[i].getModoDeImpressao();
        			pastaCmp= strMaiuscula(this->cifras[i].getPasta());
        			paraQuemCmp= strMaiuscula(this->cifras[i].getParaQuem().substr(0,tamanhoParaQuem));
        		    observacoesCmp= strMaiuscula(this->cifras[i].getObservacoes().substr(0,tamanhoObservacoes));
                    Cifra c;
					
					if(searchForNome==0){
							nome= nomeCmp;
					}
					
					if(searchForArtista==0){
							artista= artistaCmp;
					}
					
					if(searchForId==0){
							idInt= idCmp;
					}
					
					if(searchForTom==0){
                            tom= tomCmp;
                    }

					if(searchForMetronomo==0){
                            metronomoInt= metronomoCmp;
                    }

					if(searchForInstrumentos==0){
                            instrumentos= instrumentosCmp;
                    }         

					if(searchForModo==0){
                            modoInt= modoCmp;
                    }                               

					if(searchForPasta==0){
                            pasta= pastaCmp;
                    }

					if(searchForParaQuem==0){
                            paraQuem= paraQuemCmp;
                    }

					if(searchForObservacoes==0){
                            observacoes= observacoesCmp;
                    }
					
                    //pesquisa objetiva
					if(nomeCmp== nome && artistaCmp== artista && idCmp== idInt && tomCmp== tom && metronomoCmp== metronomoInt && instrumentosCmp== instrumentos && modoCmp== modoInt && pastaCmp== pasta && paraQuemCmp== paraQuem && observacoesCmp== observacoes){
							c= this->cifras[i];
							cif.push_back(c);
					}
			}
			
			return cif;
}

void DaoCifra:: alterarCifra(Cifra c, int id){
    int i;
    for(i=0; i< this->cifras.size(); i++){
            if(this->cifras[i].getId()== c.getId()){
                    this->cifras[i]= c;
                    break;
            }
    }
    
    ofstream file1;
    
    
    for(i=0; i< this-> cifras.size(); i++){
            if(i==0){
                    file1.open("Cifra.txt");
                    string cifraStr= this-> cifras[i].strCifra();
                    file1<< cifraStr;
                    
                    file1.close();    
            }else{
                    if(i==1){
                            file1.open("Cifra.txt", ios:: app);
                    }
                    
                    string cifraStr= this-> cifras[i].strCifra();
                    file1<< cifraStr;
                    
                    if(i== this-> cifras.size()-1){
                            file1.close();
                    }
            }
            
    }
    
}
