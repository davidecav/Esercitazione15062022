/* Lista doppiamente linkata */

#include <iostream>
using namespace std;

class Nodo{
public:
    int valore;
    Nodo* succ;
    Nodo* prec;
};

class ListaDoppia{
    Nodo * testa;
public:
    ListaDoppia(){ testa = nullptr;}
    ~ListaDoppia();
    Nodo * getTesta()const {return this->testa;}

    void inserisci(int val); // in testa
    // prima di prec (nodo)
    void inserisci(Nodo* precedente, int val);
    // prima di prec (valore)
    void inserisci(int prec_val, int val);
    Nodo* ricerca(int val);
    void rimuovi(int val);

    friend
    ostream& operator<<(ostream& out,
                        const ListaDoppia& ls);

};

ListaDoppia::~ListaDoppia(){
    Nodo* iter = this->testa;
    while(iter!=nullptr){
        Nodo *tmp = iter->succ;
        delete iter;
        iter = tmp;
    }
}

ostream& operator<<(ostream& out,
                    const ListaDoppia& ls){

    Nodo* primo;

    for(primo=ls.testa;primo!=nullptr;primo=primo->succ)
    {
        out << "Valore:\t" << primo->valore << endl;
        out << "\t -->";
        //stampo il successivo
        if(primo->succ!=nullptr)
            out << primo->succ->valore;
        else
            out << "NULL";
        out << endl;
        out << "\t <--";
        //stampo il precedente
        if(primo->prec!=nullptr)
            out << primo->prec->valore;
        else
            out << "NULL";
        out << endl;
    }
    return out;
}

Nodo* ListaDoppia::ricerca(int val){
    Nodo* p;
    for(p=this->testa;p!=nullptr;p=p->succ)
        if(p->valore == val)
            return p;
    return nullptr;
}

// in testa
void ListaDoppia::inserisci(int val){
    Nodo* nuovo = new Nodo;
    nuovo->valore = val;
    nuovo->prec = nullptr;
   // nuovo->succ = nullptr;
    nuovo->succ= this->testa;

    if(this->testa!=nullptr)
        this->testa->prec = nuovo;
       // nuovo->succ= this->testa;

    this->testa = nuovo;

}
// dopo prec (nodo)
void ListaDoppia::inserisci(Nodo* precedente, int val){

    Nodo* nuovo = new Nodo;
    Nodo* successivo = precedente->succ;

    nuovo->valore = val;
    nuovo->prec = precedente;
    nuovo->succ = successivo;

    precedente->succ = nuovo;
    if(successivo!=nullptr)
        successivo->prec = nuovo;

}
// dopo prec (valore)
void ListaDoppia::inserisci(int prec_val, int val){
    Nodo* p = this->ricerca(prec_val);
    if(p!=nullptr)
        this->inserisci(p,val);
    else
    cout << "Nodo " << prec_val << " non presente"<<endl;
}


void ListaDoppia::rimuovi(int val){

    Nodo* iter = this->testa;
    Nodo* tmp;

    if(this->testa==nullptr)
        cout << "Lista vuota: impossibile rimuovere elementi"<< endl;
    else if(this->testa->valore == val){
       // tmp = this->testa;
        this->testa = this->testa->succ;
        delete this->testa->prec;
        this->testa->prec = nullptr;
        //delete tmp;
    }
    else{
        while((iter->succ!=nullptr)&&
                (iter->succ->valore!=val))
            iter = iter->succ;

        if(iter->succ!=nullptr){
            tmp = iter->succ;
            if(iter->succ->succ!=nullptr)
                iter->succ->succ->prec = iter;
            iter->succ = iter->succ->succ;
            delete tmp;
        }
        else
            cout << "Elemento non presente"<<endl;
    }

}

int main(){

    ListaDoppia lista;
    for(int i=0;i<3;i++)
        lista.inserisci(i*2);

    cout << lista;

return 0;
}

