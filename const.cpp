
#include <iostream>
using namespace std;

class ContoCorrente{

private:
    int saldo = 100000;
public:
    // questo metodo mi permette di modificare il saldo
    // dall'esterno, anche se e' privato
    int & getSaldoCattiva(){return saldo;}

    int const & getSaldo() const { return saldo;}

    void printSaldo(){
        cout << "Il tuo saldo e':\t" << saldo << endl;
        if(saldo < 0)
            cout << "Attenzione!!! il conto e' in passivo!" << endl;
    }
};

int main(){

    ContoCorrente A;
    A.printSaldo();

    int y = A.getSaldo();
    y = -5000;
    A.printSaldo();


    return 0;
}
