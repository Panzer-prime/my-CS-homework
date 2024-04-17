#include<iostream>
#include<string.h>
#include<fstream>


using namespace std;
struct nod
{
    char inf[40];
    nod* next;
    nod* previous;

};
nod* ultim;

void adaugaPrim(nod* &cap, char x[40]){
    nod* p = new nod;
    strcpy(p->inf, x); 
    p->previous = NULL;
    p->next = cap;
    cap = p;
}

void adaugaDupaUltim(nod* &cap, char x[40]){
    nod* p = new nod;
    strcpy(p->inf, x); 
    p->next = NULL; 
    if(cap){
        nod* temp = cap;
        while(temp->next) temp = temp->next; 
        temp->next = p;
        p->previous = temp; 
        ultim = p;
    } else { 
        cap = p;
        p->previous = NULL;
    }
}


void creare(nod* &cap){
    ifstream f("nume.txt");
    char nume[40];
    f>>nume;
    adaugaPrim(cap, nume);
    while(f>>nume)adaugaDupaUltim(cap, nume); 
}

void afisare(nod* cap){
    for(nod* p = cap; p; p= p->next){
        cout<<p->inf<<" ";
    }
    cout<<endl;
}

void afisareInversa(nod* ultim){
    for(nod* p = ultim; p; p=p->previous){
        cout<<p->inf<<" ";
    }
    cout<<endl;
}

int main(){

    nod* cap = NULL;
    creare(cap); 
    cout<<"Afisare cap la coada\n"; 
    afisare(cap);
    cout<<"Afisare lista coada la cap\n";
    afisareInversa(ultim);
    return 0;
}
