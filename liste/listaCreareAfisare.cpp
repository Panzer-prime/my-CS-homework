#include<iostream>
#include<fstream>

using namespace std;


struct nod{
    int nr;
    nod* urm;
};

void inserarePrim(nod* &cap, int x){
    nod* p = new nod;
    p ->nr = x;
    p->urm = cap;
    cap = p;
}

void adaugaDupaUltim(nod* &cap, int x){
    nod* p = new nod;
    p->nr = x;
    p->urm = NULL;

    if(cap ==NULL){
        cap =p;
        return;
    }else{
        nod* temp = cap;
        while(temp ->urm != NULL) temp = temp->urm;
        temp->urm = p;
    }
}

void creare(nod* &cap){
        ifstream f("numere.txt");
        int x;
        f>>x;
        inserarePrim(cap, x);
        while(f>>x){
            adaugaDupaUltim(cap, x);
        }
        f.close();

}

void afisare(nod* cap){
    nod* p;
    for(p = cap; p != NULL; p = p->urm){
        cout<<p->nr<<" ";
    }
    cout<<endl;
}
