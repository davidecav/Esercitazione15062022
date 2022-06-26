#include <iostream>
using namespace std;


template <typename T>
void mySwap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
template<typename T>
void bubbleSort(T a[], int n){
    for(int i=0;i< n-1;i++)
        for(int j=n-1;i<j;j--)
            if(a[j] < a[j-1])
                mySwap(a[j], a[j-1]);
}

class Rettangolo{
private:
    int b,h;
public:
    Rettangolo(int _b = 10, int _h = 5): b(_b), h(_h){}
    int getB(){return b;}
    int getH(){return h;}
    void setB(int _b){ b = _b;}
    void setH(int _h){h = _h;}
    void print() const { cout << b << " X " << h;}

    /*
    Rettangolo a;
    Rettangolo b;
    if (a < b) ??
    */
    bool operator<(const Rettangolo& r ) const {
        return (b*h) < (r.b*r.h);
    }
};

int main(){

int int_arr[5] = {11,5,30,4, 20};
int n = 5;

bubbleSort<int>(int_arr, n);

cout << "Array di int ordinato: ";
for(int i=0;i<n;i++)
    cout << int_arr[i] << " ";

cout << endl;

char ch_arr[5] = {'f', 'g', 't', 'a','b'};
bubbleSort<char>(ch_arr,5);
cout << "Array di char ordinato: ";
for(int i=0;i<5;i++)
    cout << ch_arr[i] << " ";

cout << endl << endl;

Rettangolo arr_rett[4] = {{2,2}, {10,20}, {4,4}, {2,8}};
cout << "Array di rettangoli: " << endl;
for(int i=0;i<4;i++){
    arr_rett[i].print();
    cout << endl;
}

bubbleSort<Rettangolo>(arr_rett, 4);
cout << "Array di rettangoli ordinato:" << endl;
for(int i=0;i<4;i++){
    arr_rett[i].print();
    cout << endl;
}

return 0;
}



