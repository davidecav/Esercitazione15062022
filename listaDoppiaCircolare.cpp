/* Lista doppia circolare

Lista semplice
        | 1 | -> | 2 | -> | 3 | -> NULL

Lista doppia
        | 1 | -> | 2 | -> | 3 | -> NULL
    NULL <-       <-       <-

*/
#include <iostream>
using namespace std;

class Nodo{
public:
    int valore;
    Nodo* prec;
    Nodo* succ;
};

class LDoppiaCircolare{
Nodo* testa;
public:
    LDoppiaCircolare() {testa = nullptr;}
    ~LDoppiaCircolare();
    void inserisci(int val);
    Nodo* getTesta() {return testa;}

friend
ostream& operator<<(ostream& out, const LDoppiaCircolare& ls);
};

LDoppiaCircolare::~LDoppiaCircolare(){
    Nodo * iter;
    if(testa!=nullptr)
        iter= testa->succ;
    else
        return;

    while(iter!=testa){
        Nodo* tmp = iter->succ;
        delete iter;
        iter = tmp;
    }
    delete testa;
}

ostream& operator<<(ostream& out, const LDoppiaCircolare& ls){

    if(ls.testa == nullptr){
        cout << "Lista vuota." << endl;
        return out;
    }

    Nodo* iter = ls.testa;
    do{
        out << "Valore:\t"<< iter->valore << endl;
        out << "\t--> ";

        if(iter->succ!=nullptr)
            out << iter->succ->valore;
        else
            out << "NULL";
        out << endl;
        out << "\t <-- ";
        if(iter->prec!=nullptr)
            out << iter->prec->valore;
        else
            out << "NULL";
        out << endl << endl;
        iter = iter->succ;
    }while(iter!=ls.testa);

    return out;
}

void LDoppiaCircolare::inserisci(int val){

    Nodo* nuovo = new Nodo;
    nuovo->valore = val;
    if(testa!=nullptr){
        /*
        Inserisco dopo la testa per evitare di
        modificare anche i riferimenti della coda ed
        il valore della testa stessa
        */
        nuovo->succ = testa->succ;
        testa->succ = nuovo;
        nuovo->prec = testa;
        nuovo->succ->prec = nuovo;
    }
    else{
        nuovo->succ = nuovo;
        nuovo->prec = nuovo;
        testa = nuovo;
    }
}

int main(){

    LDoppiaCircolare lista;
    cout << lista;

    cout << "Inserisco un elemento..." << endl;

    lista.inserisci(101);
    cout << lista;

    cout << "Inserisco 8 elementi..." << endl;
    for(int i=0;i<8;i++)
        lista.inserisci(i*10);

    cout << lista;
    return 0;

}




