#ifndef CLASSECIFRA_H
#define CLASSECIFRA_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Cifra{
    private:
        int id;
        string nome;
        string artista;
        string tom;
        float metronomo;
        string instrumentos;// vector <Instrumento> instrumentos
        int modoDeImpressao;//-1- nenhum; 0- escrito; 1- impressa
        string pasta;//Em qual pasta a cifra se encontra?
        string paraQuem;//Especificamente, para quem cantar?
        string observacoes;
        
        
    public:
        
        void setId(int id){
            this-> id= id;
        }
        
        int getId(){
            return this-> id;
        }
        
        void setNome(string nome){
            this-> nome= nome;
        }
        
        string getNome(){
            return this-> nome;
        }
        
        void setArtista(string artista){
            this-> artista= artista;
        }
        
        string getArtista(){
            return this-> artista;
        }
        
        void setTom(string tom){
            this-> tom= tom;
        }
        
        string getTom(){
            return this-> tom;
        }
        
        void setMetronomo(float m){
            this->metronomo= m;
        }
        
        float getMetronomo(){
            return this->metronomo;
        }
        
//        void addInstrumento(string nome){
//            this-> instrumentos.push_back(nome);
//        }
//        
//        vector <string> getInstrumento(){
//            return this-> instrumentos;
//        }
        
        void setInstrumentos(string nomes){
            this-> instrumentos= nomes;
        }
        
        string getInstrumentos(){
            return this-> instrumentos;
        }
        
        void setModoDeImpressao(int modo){
            if(modo==-1 || modo==0 || modo==1){
                this->modoDeImpressao= modo;
            }else{
                this->modoDeImpressao= -1;
            }
        }
        
        int getModoDeImpressao(){
            return this->modoDeImpressao;
        }
        
        void setPasta(string p){
            this->pasta= p;
        }
        
        string getPasta(){
            return this->pasta;
        }
        
        void setParaQuem(string pQ){
            this-> paraQuem= pQ;
        }
        
        string getParaQuem(){
            return this-> paraQuem;
        }
                
        void setObservacoes(string obs){
            this-> observacoes= obs;
        }
        
        string getObservacoes(){
            return this-> observacoes;
        }
        
        string strCifra(){
            string cifraString;

            stringstream convert;
            convert<< this-> id;
            string idS= convert.str();
            
            stringstream convert2;
            convert2<< this-> metronomo;
            string metronomoS= convert2.str();
            
            if(this->metronomo<=0){
                metronomoS= " ";
            }
            
            stringstream convert3;
            convert3<< this-> modoDeImpressao;
            string modoS= convert3.str();            
            
            
            cifraString= idS+ "\t" + nome+ "\t" + artista+ "\t" + tom+ "\t" + metronomoS+ "\t" + instrumentos+ "\t" + modoS+ "\t" + pasta+ "\t" + paraQuem+ "\t" + observacoes+ "\n";
            
            return cifraString;
            
        }
        
        Cifra CifraConvertStr(string cifraStr){
            char tab= "\t"[0];
            stringstream cifraSS(cifraStr);
            
            string idS;
            getline(cifraSS, idS, tab);
            
            string nome;
            getline(cifraSS, nome, tab);
            
            string artista;
            getline(cifraSS, artista, tab);
            
            string tom;
            getline(cifraSS, tom, tab);
            
            string metronomoS;
            getline(cifraSS, metronomoS, tab);
            
            string instrumentos;
            getline(cifraSS, instrumentos, tab);
            
            string modoS;
            getline(cifraSS, modoS, tab);
            
            string pasta;
            getline(cifraSS, pasta, tab);
            
            string paraQuem;
            getline(cifraSS, paraQuem, tab);
            
            string observacoes;
            getline(cifraSS, observacoes, tab);
            
            
            stringstream idSs(idS);
            int id;
            idSs>> id;
            
            stringstream metronomoSs(metronomoS);
            float metronomo;
            metronomoSs>> metronomo;
            if(metronomoS==" "){
                metronomo= -1;
            }
            
            stringstream modoSs(modoS);
            int modo;
            modoSs>> modo;
            
            Cifra c;
            c.setId(id);
            c.setNome(nome);
            c.setArtista(artista);
            c.setTom(tom);
            c.setMetronomo(metronomo);
            c.setInstrumentos(instrumentos);
            c.setModoDeImpressao(modo);
            c.setPasta(pasta);
            c.setParaQuem(paraQuem);
            c.setObservacoes(observacoes);
            
            return c;
        }
        
        
    
    
};



#endif
