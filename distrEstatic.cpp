
#include <iostream>
using namespace std;

class MyClass{
int value;
static int num_obj; // numero di istanze della classe

public:
    MyClass();
    MyClass(int x);
    ~MyClass();

    int getValue();
    void setValue(int x);

    static int getNumObj();

    //definisco un metodo per clonare una istanza
    MyClass * clone();
    void copyIn(MyClass *destination);


};


int MyClass::num_obj = 0;
// distruttore
MyClass::~MyClass(){ num_obj--; cout << "Distruggi!"<<endl;}
MyClass::MyClass(int x) {value=x; num_obj++;}
MyClass::MyClass(): MyClass(-10){}

int MyClass::getNumObj() {return num_obj;}
int MyClass::getValue() { return value;}
void MyClass::setValue(int x) {value = x;}

MyClass * MyClass::clone(){
    MyClass *copia_p = new MyClass();
    copia_p->setValue(value);
    return copia_p;
}

void MyClass::copyIn(MyClass *destination){
    destination->setValue(value);
}


int main(){

    MyClass obj_1;
    obj_1.setValue(20);
    MyClass obj_2(10);

    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;
    cout << "Obj 1 value:\t" << obj_1.getValue() << endl;
    cout << "Obj 2 value:\t" << obj_2.getValue() << endl;


    MyClass * cp_p_1 = obj_1.clone();
    cout << "Copia 1 value:\t" << cp_p_1->getValue() << endl;
    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;

    {
        MyClass obj_3(100);
        cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;
    }
    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;

    delete cp_p_1;


    cout << endl;
    MyClass obj_4;
    obj_4.setValue(2000);

    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;
    cout << "Obj 4 value:\t" << obj_4.getValue() << endl;

    MyClass cp_4;
    obj_4.copyIn(&cp_4);
    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;
    cout << "Copia di obj 4 value:\t" << cp_4.getValue() << endl;


    cout << "Fine del main()" << endl;
    return 0;
}
