
#ifndef LISTADOPPIAORDINATA_H
#define LISTADOPPIAORDINATA_H

#include "giocatoreGolf.h"

using namespace std;

class Nodo {
public:
	Golfista valore;
	Nodo* succ;
	Nodo* prec;
};

class ListaDoppiaOrdinata{
	Nodo* testa;
public:
	ListaDoppiaOrdinata() {testa=nullptr;}
	~ListaDoppiaOrdinata();
	Nodo* getTesta()const {return this->testa;}
    // inserimento: esiste un solo tipo di inserimento
	void inserisci(Golfista val); //in testa
    Nodo* ricerca(Golfista val);
    void rimuovi(Golfista val);

    friend
    ostream& operator<<(ostream& out, const ListaDoppiaOrdinata& ls);
};


#endif
