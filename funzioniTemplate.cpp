
#include <iostream>
using namespace std;
/*
void stampa(int value){ cout << value << endl;}
void stampa(float value) { cout << value << endl;}
void stampa(char* value) {cout << value << endl;}
*/
template<typename Tipo>
void stampa(Tipo value) { cout << value << endl;}


template<>
void stampa<bool>(bool value){
    if(value) cout << "true";
    else cout << "false";
    cout << endl;
}

int main(){

stampa(5);
stampa(3.5);
stampa("ciao");

stampa<int>(15);
stampa<float>(3.4);
stampa<char*>("ciaociao");

cout << endl;

stampa<bool>(true);
stampa<bool>(false);
stampa<bool>(1);
stampa<bool>(0);


return 0;
}
