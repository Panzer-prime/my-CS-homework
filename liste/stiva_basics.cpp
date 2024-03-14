#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

struct nod {
    int data;
    nod* next;
};

nod* varf;

void adaug(nod* &vf, int x) {
    nod* p = new nod;
    p->data = x;
    if(vf) {
        p->next = vf;
        vf = p;
    } else {
        p->next = NULL;
        vf = p;
    }
}

void afisare(nod* vf) {
    nod* p = vf;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
}

void eliminare(nod* &vf) {
    nod *q;
    if(vf) {
        q = vf;
        vf = vf->next;
        delete q;
    } else {
        cout<<"Stiva vida "<<endl;
    }
}

int main() {
    varf = NULL;
    int x;
    char op;
    do{
        cout << "Introdu operatia dorita: ";
        cin >> op;
        switch(op)
        {
            case '1':{
                cout << "\nStiva dupa afisare: " << endl;
                afisare(varf);
                break;
            }
            case '2':
                cout << "\nSterg din varf" << endl;
                eliminare(varf);
                break;
            case '3':
                cout << "Care valoare adaugi: ";
                cin >> x;
                adaug(varf, x);
                break;
            default: cout << "Introdu o valoare intre 1 - 3 " << endl;
        }
    } while(op != '0');
    return 0;
}
