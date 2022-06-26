
#include <iostream>
using namespace std;
#define SIZE 10


class Queue{
    int *arr;
    int capacita;
    int fronte;
    int fine;
    int count; // numero di el. attualmente presenti

public:
    Queue(int size = SIZE);
    ~Queue();

    int peek();
    bool dequeue();
    bool enqueue(int x);
    int getSize() const;
    bool isEmpty() const;
    bool isFull() const;

    friend
    ostream& operator<<(ostream& out, const Queue& q);
};

Queue::Queue(int size){
    arr = new int[size];
    capacita = size;
    fronte = 0;
    fine = -1;
    count = 0;
}


Queue::~Queue(){
    delete[] arr;
}


bool Queue::dequeue(){
    if(isEmpty()){
        cout << "Coda vuota - Underflow" << endl;
        return false;
    }
    cout << "Rimuovo " << arr[fronte] << endl;
    fronte = (fronte + 1) % capacita;
    count--;
    return true;
}


bool Queue::enqueue(int x){
    if(isFull()){
        cout << "Coda piena - Overflow" << endl;
        return false;
    }
    cout << "Inserisco " << x << endl;
    fine = (fine + 1) % capacita;
    arr[fine] = x;
    count++;
    return true;
}

int Queue::peek(){
    if(isEmpty()){
        cout << "Coda vuota - Underflow" << endl;
        return 0;
    }
    return arr[fronte];
}

int Queue::getSize() const {return count;}
bool Queue::isEmpty() const {return count ==0;};
bool Queue::isFull() const {return count == capacita;}

ostream& operator<<(ostream& out, const Queue& q){
    int i = 0;
    out << endl << "Visualizzazione coda:" << endl;
    if(q.isEmpty())
        out << "Coda vuota" << endl;
    else{
        out << "<--";
        for(i =q.fronte; i!=q.fine; i = (i+1) % q.capacita)
            out << "|" << q.arr[i];

        out << "|" <<q.arr[i]<< "|<--" << endl;

        out << "Rappresentazione interna (array):"<< endl;
        for(int i=0;i<q.capacita;i++){
            if(i== q.fronte && i== q.fine)
                out << "fr/fin ->";
            else if(i==q.fronte)
                out << "fronte ->";
            else if(i==q.fine)
                out << "fine   ->";
            else
                out << "         ";
            out << i << " " << q.arr[i] << endl;
        }
        out << endl;
        return out;
    }

}

int main(){

    Queue q(5);
    cout << q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q;

    q.dequeue();
    cout << q;
    q.dequeue();
    cout << q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    cout << q;
    q.enqueue(8);

    q.dequeue();
    q.dequeue();
    cout << q;
    q.enqueue(99);
    cout << q;

return 0;
}

