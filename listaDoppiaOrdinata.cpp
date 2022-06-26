
/* Implementazione lista concatenata doppia ordinata:

- inserimento in ordine
- ricerca (ottimizzata per liste ordinate)
- rimozione
*/

#include <iostream>
#include "listaDoppiaOrdinata.h"

using namespace std;

ListaDoppiaOrdinata::~ListaDoppiaOrdinata()	{
	Nodo* iter=this->testa;

	while(iter!=nullptr)	{
		Nodo* temp= iter->succ;
		delete iter;
		iter=temp;
	}
}

ostream& operator<<(ostream& out, const ListaDoppiaOrdinata& ls)
{
	Nodo* primo;//=ls.testa; 


	for(primo=ls.testa; primo!=nullptr; primo = primo->succ)
    {
        out << primo->valore << endl;
        out << "\t --> ";
        //stampo successivo
        if(primo->succ!=nullptr)
            out << primo->succ->valore;
        else
            out << "NULL";
        out << endl;
        //stampo precedente
        out << "\t <-- ";
        if(primo->prec!=nullptr)
            out << primo->prec->valore;
        else
            out << "NULL";
        out << endl << endl;
    }
    return out;

}


Nodo* ListaDoppiaOrdinata::ricerca(Golfista val){
    Nodo *p;

    for(p=this->testa;p!=nullptr;p = p->succ)
        if(p->valore==val)
            return p;

    return nullptr;
}

void ListaDoppiaOrdinata::inserisci(Golfista val)
{
	Nodo* nuovo= new Nodo;
	nuovo->valore=val;

    Nodo* iter = this->testa;
	if (this->testa == nullptr){
            nuovo->succ=nullptr;
            this->testa=nuovo;
            nuovo->prec=nullptr;
        } // se va messo prima della testa
	else if (this->testa->valore >val) {
            nuovo->succ=this->testa;
            nuovo->prec= nullptr;
            this->testa->prec=nuovo;
            this->testa=nuovo;
		}
	else { // cerco la posizione dove inserirlo (prima di iter->succ)
            while((iter->succ!=nullptr)&&(val > iter->succ->valore))
                iter = iter->succ;
            nuovo->succ = iter->succ;
            nuovo->prec = iter;
            if(iter->succ!=nullptr)
                iter->succ->prec = nuovo;
            iter->succ = nuovo;

		}
}

void ListaDoppiaOrdinata::rimuovi(Golfista val)
{
	Nodo* iter = this->testa;
    Nodo* tmp;

	if (this->testa==nullptr)
		cout << "Lista vuota: impossibile rimuovere elementi \n";
	else if (this->testa->valore==val) {
		tmp=this->testa;
		this->testa=this->testa->succ;
		this->testa->prec = nullptr; //differenza rispetto lista semplice
		delete tmp;
		}
	else	{
		while ((iter->succ!=nullptr) && (iter->succ->valore!=val))
			iter=iter->succ;
        // se e' diverso da nullptr significa che l'ho trovato
        // il nodo da eliminare e' iter->succ
		if (iter->succ!=nullptr)	{
		   tmp = iter->succ;
		   if(iter->succ->succ!=nullptr)
			iter->succ->succ->prec = iter;
		   iter->succ = iter->succ->succ;
		   delete tmp;

		}
		else
			cout << "Elemento non presente nella lista!" << endl;
	}
}



