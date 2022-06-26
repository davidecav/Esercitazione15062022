

#include <iostream>
using namespace std;

class ClasseA {
public:
    ClasseA() {}
    void virtual dinamica(){
        cout << "Metodo dinamico della Classe A" << endl;
    }
    void statica(){
        cout << "Metodo statico della classe A" << endl;
    }
};

class ClasseB: public ClasseA{
public:
    ClasseB(){}
    void dinamica(){
        cout << "Metodo dinamico della classe B" << endl;
    }
    void statica(){
        cout << "Metodo statico della classe B" << endl;
    }

};

int main(){

    ClasseA* a;
    ClasseB* b;

    a = new ClasseA();
    b = new ClasseB();

    cout << "Metodi di a* della classe A:" << endl;
    a->dinamica();
    a->statica();
    cout << endl;
    cout << "Metodi di b* della classe B:" << endl;
    b->dinamica();
    b->statica();
    cout << endl;

    a = b;
    cout << "Metodi di a* dopo a=b:" << endl;
    a->dinamica();
    a->statica();



return 0;
}
