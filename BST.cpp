
#include <iostream>
using namespace std;

struct Nodo{
    int val;
    Nodo *left, *right, *padre;
};

class Albero{
    Nodo *radice;
    int num_elementi=0;
    void inOrder(Nodo* p) const;
    void preOrder(Nodo* p) const;
    void postOrder(Nodo* p) const;
    Nodo* ricercaRicorsiva(Nodo* x,int valore);
    void cancella(Nodo* z);
    void trapianta(Nodo* u, Nodo *v);
    Nodo* minimo(Nodo* x);

public:
    Albero(): radice(nullptr) {}
    void inserisci(int);
    void inOrder() const{inOrder(radice); cout << endl;}
    void preOrder() const{preOrder(radice);cout << endl;}
    void postOrder() const{postOrder(radice);cout << endl;}
    int altezza(Nodo* p) const;
    bool cancella(int valore);
    Nodo* ricercaIterativa(int valore);
    Nodo* ricercaRicorsiva(int valore){
        return ricercaRicorsiva(radice,valore);
    }

    friend
    ostream& operator<<(ostream& out, const Albero&t);
};


void Albero::inserisci(int valore){
    Nodo* nuovo = new Nodo;
    Nodo* x=radice, *y=nullptr;

    nuovo->val = valore;
    nuovo->left = nullptr;
    nuovo->right = nullptr;
    while(x!=nullptr){
        y = x;// y tiene traccia del padre di x
        if(valore < x->val)
            x = x->left;
        else
            x = x->right;
    }
    nuovo->padre = y;
    if(y==nullptr)
        radice = nuovo;
    else if(valore < y->val)
        y->left = nuovo;
    else
        y->right = nuovo;

    num_elementi++;
}


void Albero::inOrder(Nodo* p) const{
    if(p!=nullptr){
        inOrder(p->left);
        cout << p->val << "\t";
        inOrder(p->right);
    }
}
void Albero::preOrder(Nodo* p) const{
        if(p!=nullptr){
        cout << p->val << "\t";
        preOrder(p->left);
        preOrder(p->right);
    }
}

void Albero::postOrder(Nodo* p) const{
        if(p!=nullptr){
        postOrder(p->left);
        postOrder(p->right);
        cout << p->val << "\t";
    }
}

int Albero::altezza(Nodo* p) const{
    if(p == nullptr)
        return 0;
    else{
        int leftHeight = altezza(p->left);
        int rightHeight = altezza(p->right);

        if(leftHeight>rightHeight)
            return leftHeight +1;
        else
            return rightHeight+1;

    }

}

void stampaLivello(Nodo* p, int livello){
    if(p == nullptr){
        cout << "_\t";
        return;
    }
    if (livello==0)
        cout << p->val << "\t";
    else if(livello>0){
        stampaLivello(p->left, livello-1);
        stampaLivello(p->right, livello-1);
    }

}

ostream& operator<<(ostream& out, const Albero&t){
    int h = t.altezza(t.radice);
    out << "Albero di altezza " << h << endl;

    for(int i=0;i<h;i++){
        stampaLivello(t.radice,i);
        out << endl;
    }
    return out;

}

Nodo* Albero::ricercaIterativa(int valore){
    Nodo *x=radice;
    while(x!=nullptr && valore!=x->val){
         cout << " --> " << x->val;
        if(valore < x->val)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}
Nodo* Albero::ricercaRicorsiva(Nodo* x, int valore){

    if(x==nullptr || x->val == valore)
        return x;
     cout << " --> " << x->val;

    if(valore<x->val)
        return ricercaRicorsiva(x->left, valore);
    else
        return ricercaRicorsiva(x->right, valore);

}

void Albero::trapianta(Nodo* u, Nodo *v){
    if(u->padre==nullptr)
        radice = v;
    else if(u==u->padre->left)
        u->padre->left = v;
    else
        u->padre->right = v;

    if(v!=nullptr)
        v->padre = u->padre;
}

void Albero::cancella(Nodo* z){
    Nodo *y;
    // Caso 2: z ha un solo figlio
    if(z->left == nullptr)
        trapianta(z,z->right);
    else if(z->right==nullptr)
        trapianta(z,z->left);

    // Caso 3: ha entrambi i figli
    else{
        y = minimo(z->right); // y <- successore di z
        if(y->padre!=z){
            trapianta(y, y->right); // y->right corrisponde ad 'x' nelle slides
            y->right = z->right; // z->right <==> 'r' nelle slides
            y->right->padre = y;
        }
        //non ci resta altro che trapiantare y in z
        trapianta(z,y);
        y->left = z->left; // z->left <==> 'l' nelle slides
        y->left->padre = y;
    }
    delete z;
}

Nodo* Albero::minimo(Nodo* x){
    Nodo* nMin = x;
    while(nMin->left!=nullptr)
        nMin = nMin->left;
    return nMin;
}

bool Albero::cancella(int valore){
    Nodo* n = ricercaIterativa(valore);
    if(n==nullptr)
        return false;

    cancella(n);
    return true;
}


int main(){

    Albero tree;
    tree.inserisci(8);
    tree.inserisci(5);
    tree.inserisci(18);
    tree.inserisci(2);
    tree.inserisci(6);
    tree.inserisci(19);
    tree.inserisci(16);

   // tree.inserisci(9);

    cout << tree << endl;

    cout << "Visita preorder:" << endl;
    tree.preOrder();
    cout << "Visita postorder:" << endl;
    tree.postOrder();
    cout << "Visita inorder:" << endl;
    tree.inOrder();


    int x;
    cout << "Inserisci un valore da cercare: ";
    cin >> x;
    cout << endl;
    Nodo *n = tree.ricercaRicorsiva(x);
    if(n==nullptr)
        cout << endl << "Elemento non presente"<< endl;
    else
        cout << endl << n->val << endl;


    cout << "Inserisci un valore da cercare: ";
    cin >> x;
    cout << endl;
    n = tree.ricercaIterativa(x);
    if(n==nullptr)
        cout << endl << "Elemento non presente"<< endl;
    else
        cout << endl << n->val << endl;

    cout << endl << tree << endl;
    cout << "Inserisci un valore da cancellare: ";
    cin >> x;
    cout << endl;
    if(!tree.cancella(x))
        cout << endl << "Elemento non presente"<< endl;
    else
        cout << endl << tree << endl;



    return 0;
}



