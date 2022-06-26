
#include <iostream>
using namespace std;

class NoConstruct{
public:
    int x;
    char c;
    float f;
    void printAll(){
        cout << "x:" << "\t" << x
            << "\t" << "c:" <<"\t" << c
            << "\tf:\t" << f << endl;
    }
};

class A{
    public:
        int uno;
        void printAll() const{
            cout << "Dati membro:" << endl;
            cout << "uno:\t" << uno << endl;
            cout << "due:\t" << due << endl;
            cout << "tre:\t" << tre << endl;
        }
        A(){}
        A(int, int);
        A(int, int, int);

        void setDataMember(int,int);
    private:
        int due;
        const int tre=10;
};

void A::setDataMember(int att, int val){

    switch(att){
        case 1: uno = val; break;
        case 2: due = val; break;
     //   case 3: tre = val; break;
    }
}

A::A(int x, int y): uno(x), due(x+y), tre(x+y+1){}
A::A(int x, int y, int z): uno(x), due(y), tre(z){}


int main(){

    NoConstruct noc1;
    //inizializzazione uniforme
    NoConstruct noc2{4};
    NoConstruct noc3{4, 'X', 3.14};
    noc3.printAll();
    noc1.printAll();


    A obj_a;
    // posso modificare direttamente solo i dati pubblici
    obj_a.uno = 100;
    obj_a.printAll();

    obj_a.setDataMember(1,10);
    obj_a.setDataMember(2,20);
    obj_a.printAll();

    A obj_b{10,5};
    obj_b.printAll();

//    A obj_c(); // Errore!

    // se esiste un costruttore prova a fare matching
    // altrimenti tenta di fare la unif. initialization.
    A obj_c = {101, 102, 103};
    obj_c.printAll();

    cout << endl;

    A a{1,2,3};
    a.printAll();

    // Puntatore
    A* ptA = &a;
    ptA->printAll();

    // Riferimento
    A& rA = a;
    rA.setDataMember(1,100);
    rA.printAll();


    const A& cRefA = a;
//    cRefA.setDataMember(1,0);
    cRefA.printAll();

    // Allocazione dinamica
    A* ptrA = new A(100, 200, 300);
    ptrA->printAll();
    delete ptrA;


    cout << endl;

    A arrA[2];
    for(int i=0;i<2;i++){
        cout << "arrA[" << i << "]: ";
        arrA[i].printAll();
        cout << endl;
    }
    cout << endl;


    // array con costruttore specifico per ciascun elemento
    A arrA_2[2] = { A(3,3,3), A(9,9) };
    for(int i=0;i<2;i++){
        cout << "arrA_2[" << i << "]: ";
        arrA_2[i].printAll();
        cout << endl;
    }


    A* ptrArrA3 = new A[2]; // costr. di default
    ptrArrA3[0].printAll();
    delete[] ptrArrA3;

    A* ptrArrA4 = new A[2] {A(2,2,2), A(10,10)};
    (ptrArrA4+1)->printAll(); // aritm. puntatori
    delete[] ptrArrA4;

    return 0;
}
