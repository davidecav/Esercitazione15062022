
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
public:
    Albero(): radice(nullptr) {}
    void inserisci(int);
    void inOrder() const{inOrder(radice); cout << endl;}
    void preOrder() const{preOrder(radice);cout << endl;}
    void postOrder() const{postOrder(radice);cout << endl;}
    int altezza(Nodo* p) const;
    // TODO:
    Nodo* ricerca(int elemento);

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

int main(){

    Albero tree;
    tree.inserisci(6);
    tree.inserisci(5);
    tree.inserisci(7);
    tree.inserisci(2);
    tree.inserisci(8);
    tree.inserisci(5);
   // tree.inserisci(9);

    cout << tree << endl;

    cout << "Visita preorder:" << endl;
    tree.preOrder();
    cout << "Visita postorder:" << endl;
    tree.postOrder();
    cout << "Visita inorder:" << endl;
    tree.inOrder();
    return 0;
}



