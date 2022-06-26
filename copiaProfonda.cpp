
#include <iostream>
using namespace std;

class Weapon{
public:
    string name = "Ascia";
    int power = 10;
    Weapon(string n, int p): name(n), power(p) {}
    Weapon(){}
};

class GameCharacter{
int n_inv;
public:
    string name;
    int posX, posY, HP;
    Weapon* inventory;

    int getN()const {return n_inv;}

    GameCharacter(int n): n_inv(n){
        inventory = new Weapon[n];
    }

    ~GameCharacter(){
        delete[] inventory;
    }

    void printAll(){
        cout << endl << name << endl;
        cout << "Position: " << posX << " " << posY << endl;
        cout << "HP: " << HP << endl;
        for(int i=0;i<n_inv;i++)
            cout << inventory[i].name << " (" << inventory[i].power << ") " << endl;
    }


    friend
    ostream& operator<<(ostream& out, const GameCharacter& gc);


    // Costruttore copia
    GameCharacter(const GameCharacter &original): n_inv(original.getN()){
        cout << "uso costruttore copia" << endl;

        name = original.name;
        posX = original.posX;
        posY = original.posY;
//        n_inv = original.getN();
        HP = original.HP;
        if(original.inventory != nullptr){
            inventory = new Weapon[n_inv];
            *inventory = *(original.inventory);
        }
        else
            inventory = nullptr;
    }

    GameCharacter& operator=(const GameCharacter& original){
    cout << "uso operatore di assegnamento" << endl;

        if(this != &original){
            if(inventory !=nullptr)
                delete inventory;
            name = original.name;
            posX = original.posX;
            posY = original.posY;
            n_inv = original.getN();
            HP = original.HP;
            if(original.inventory != nullptr){
                inventory = new Weapon[n_inv];
                *inventory = *(original.inventory);
            }
            else
                inventory = nullptr;

        }
        return *this;
    }
};

ostream& operator<<(ostream& out, const GameCharacter& gc){
        out << endl<< gc.name << endl;
        out << "Position: " << gc.posX << " " << gc.posY << endl;
        out << "HP: " << gc.HP << endl;
        for(int i=0;i<gc.n_inv;i++)
            out << gc.inventory[i].name << " (" << gc.inventory[i].power << ") " << endl;
        return out;
}


int main(){

GameCharacter ch1(2);
ch1.name = "Giocatore 1";
ch1.HP = 100;
ch1.posX= 10;
ch1.posY = 20;

Weapon wp1("Arco", 50);
Weapon wp2;
ch1.inventory[0] = wp1;
ch1.inventory[1] = wp2;

//ch1.printAll();
cout << "riga 69" << endl;
cout << ch1 << endl;

GameCharacter ch2(ch1);
ch2.name = "Giocatore 2";
cout << "riga 74" << endl;
cout << ch2 << endl;

cout << "Modifico inventario Giocatore 1" << endl;
ch1.inventory[0] = Weapon("Bazooka", 2000);

cout << "righe 80-81" << endl;
cout << ch1 << endl;
cout << ch2 << endl;


cout << "Creo giocatore 3 ... ";
GameCharacter ch3(2);
ch3 = ch1;
ch3.name = "Giocatore 3";
cout << ch1 <<endl;
cout << ch3 << endl;

cout << "Modifico inventario giocatore 3 ..." << endl;
ch3.inventory[0] = Weapon("Martello", 400);

cout << ch1 << endl;
cout << ch3 << endl;


return 0;
}
