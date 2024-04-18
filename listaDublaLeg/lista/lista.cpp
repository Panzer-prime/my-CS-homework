#include<iostream>
#include<string.h>
#include<fstream>


using namespace std;
struct nod
{
    int inf;
    nod* next;
    nod* previous;

};
nod* ultim;

void adaugaPrim(nod* &cap, int x){
    nod* p = new nod;
    p->inf = x;
    p->previous = NULL;
    p->next = cap;
    cap = p;
}

void adaugaDupaUltim(nod* &cap, int x){
    nod* p = new nod;
    p->inf = x; 
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
    int x;
    f>>x;
    adaugaPrim(cap, x);
    while(f>>x){
        if(x  % 2 == 0)
            adaugaDupaUltim(cap, x);
        else adaugaPrim(cap, x);
    }
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
    int x;
    creare(cap); 
    cout<<"Afisare cap la coada\n"; 
    afisare(cap);
    
        cout<<"cel fel de afisare doriti\n";
        cout<<"1.afisare cap la coada\n";
        cout<<"2. afisare coada la cap\n";
        cin>>x;
    switch(x){
        case 1: afisare(cap); 
            break;
        case 2: afisareInversa(ultim);
            break;
    }
    

    return 0;
}
