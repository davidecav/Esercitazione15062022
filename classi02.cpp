
#include <iostream>
using namespace std;

class Cerchio{
    double raggio;

public:
  /*  Cerchio(){raggio = 1; cout << "costr default"<<endl;}
    Cerchio(double r){ raggio=r; cout << "costr 1 par." << endl;}
*/
    Cerchio(double r =1){raggio =r; }//cout << "costr con valore di default"<<endl;}
    double circonferenza() const { return 2*raggio*3.1415;}
    double getRaggio() const {return raggio;}
};

double area_cerchio(Cerchio c){
    cout << "Metodo??" << endl;
    return c.getRaggio()*c.getRaggio()*3.1415;
}


double area(Cerchio& c){
    cout << "Metodo senza const" << endl;
    return c.getRaggio()*c.getRaggio()*3.1415;
}

double area(const Cerchio& c){
    cout << "Metodo con const" << endl;
    return c.getRaggio()*c.getRaggio()*3.1415;
}



int main(){

    Cerchio c1 (10.0); // notazione funzionale (sconsigliata! vedi c6)
    Cerchio c2 = 20.0; // assignment initialization
    Cerchio c3{30.0}; // unif. initialization

    Cerchio c4;
    Cerchio c5{};
   // Cerchio c6(); // sbagliato

    cout << "Circonferenza c1:\t" << c1.circonferenza() << endl;
    cout << "Circonferenza c4:\t" << c4.circonferenza() << endl;
  //  cout << "Circonferenza c6:\t" << c6.circonferenza() << endl;


    cout << "Area c2:\t" << area_cerchio(c2) << endl;
    cout << "Area di ?? \t" << area_cerchio(2.3) << endl;

    cout << endl;
    Cerchio c7{2.3};

    cout << "Area:\t" << area(c7) << endl;
    cout << "Area:\t" << area(2.3) << endl;



    return 0;
}
