#include <iostream>

using namespace std;

class OperazioneAritmetica{
public: 
	double opSinistro;
	double opDestro;
	virtual double eseguiCalcolo();

};

class Addizione: public OperazioneAritmetica{
	double eseguiCalcolo(){
	return opSinistro + opDestro;
	}
};
class Sottrazione: public OperazioneAritmetica{
	double eseguiCalcolo(){
	return opSinistro + opDestro;
	}
};
class Moltiplicazione: public OperazioneAritmetica{
	double eseguiCalcolo(){
	return opSinistro + opDestro;
	}
};
class Divisione: public OperazioneAritmetica{
	double eseguiCalcolo(){
	return opSinistro + opDestro;
	}
};


int main(){
int n;

cout << "scrivi quante istanze casuali prendere: ";
cin >> n;
double * casuali = new double[2*n];
OperazioneAritmetica * coda[n];

for(int i=0;i<n;i++){
	if(rand()%4==1){
	coda[i] = new Addizione ;
	}
	if(rand()%4==2){
	coda[i] = new Sottrazione;
	}
	if(rand()%4==3){
	coda[i] = new Moltiplicazione;
	}
	if(rand()%4==0){
	coda[i] = new Divisione;
	}
}

return 0;
}
