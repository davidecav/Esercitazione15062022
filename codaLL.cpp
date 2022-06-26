
#include <iostream>
using namespace std;

class Nodo{
public:
    int valore;
    Nodo* succ;
    Nodo(int d): valore(d), succ(nullptr){}
};

class Queue{
    Nodo *fronte, *fine;
public:
    Queue() {fronte = fine = nullptr;}
    void enQueue(int x);
    bool deQueue();
    bool isEmpty()const { return fine == nullptr;}
    friend
    ostream& operator<<(ostream& out, const Queue& q);
};

void Queue::enQueue(int x){
    Nodo* tmp = new Nodo(x);
    if(fine == nullptr){
        fronte = fine = tmp;
    }
    else // inserimento in coda...
    {
        fine->succ = tmp;
        fine = tmp;
    }
}

bool Queue::deQueue(){
    // se e' vuota...
    if(fronte == nullptr)
        return false;

    Nodo* tmp = fronte;
    fronte = fronte->succ;
    // se ho svuotato la coda aggiorno 'fine'
    if(fronte == nullptr)
        fine = nullptr;

    delete tmp;
    return true;
}

ostream& operator<<(ostream& out, const Queue& q){
    Nodo *iter;
    out << endl << "Visualizzazione coda (LL)" << endl;
    if(q.isEmpty())
        out << "Coda vuota!" << endl;
    else{

        out << "<--";
        for(iter=q.fronte;iter!=nullptr;iter=iter->succ)
            out << "|" << iter->valore;
        out << "|<--" << endl;
    }
    out << endl;
    return out;
}


int main(){

Queue q;
q.enQueue(10);
q.enQueue(20);
q.enQueue(30);
q.enQueue(40);
q.enQueue(50);

cout << q;

q.deQueue();
q.deQueue();
q.deQueue();
q.deQueue();
//q.deQueue();

cout << q;

q.enQueue(33);
q.enQueue(44);
q.enQueue(55);

cout << q;

return 0;

}

