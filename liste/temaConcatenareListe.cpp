#include<iostream>
#include<fstream>

using namespace std;

struct nod{
    int info;
    nod* next;
};

void adaugaPrim(nod* &prim , nod* &ultim, int x){
    prim = new nod;
    prim->info = x;
    prim->next = NULL;
    ultim = prim;
}

void adaugaDupaUltim(nod* &ultim, int x){
    nod* p = new nod;
    p->info = x;
    p->next = NULL;
    ultim->next = p;
    ultim = p;
}


void creare(nod* &prim, nod* &ultim){
    prim = ultim = NULL;
    int x;
    ifstream f("numere.txt");
    f>>x;
    adaugaPrim(prim, ultim, x);
    while(f>>x){
        adaugaDupaUltim(ultim , x);
    }
    f.close();
    
}

void eliminare(nod* &prim){
    nod* p;
    if(prim){
        p = prim;
        prim = prim->next;
        delete prim;
    }else cout<<"nr de elemente non existent";
}

void afisare(nod* &prim){
    nod* p; 
    for(p = prim; p != NULL; p = p->next) cout<<p->info<<" ";
    cout<<endl;
}

void adaugInStiva(nod* &prim, int x){
    nod* p = new nod;
    p->info = x;
    if(prim){
        p->next = prim;
        prim = p;
    }else {
        p->next = NULL;
        prim = p;
    }
}

void concatenareInCoada(nod* &vfStiva, nod* &coada) {
    nod* p;
    for (p = vfStiva; p != NULL; p = p->next) {
        adaugaDupaUltim(coada, p->info); 
    }

    nod* temp;
    while (vfStiva != NULL) {
        eliminare(vfStiva);
    }
    vfStiva = NULL; 
}

void concatenareInStiva(nod* &vfStiva, nod* &coada) {
    nod* p;
    for (p = coada; p != NULL; p = p->next) {
        adaugInStiva(vfStiva, p->info); 
    }

    while (coada != NULL) {
        eliminare(coada);
    }
    coada = NULL; 
}

bool sumaStiva(nod* prim){
    nod* p;
    int suma =0; 
    for(p = prim; p != NULL; p = p->next) {
        suma += p ->info;
    }
    cout<<suma<<endl;
    if(suma % 2) return false;
    else return true;
}
int main() {
    nod* prim, *ultim, *vfStiva = NULL; 

    ifstream f("numere.txt");
    int x;
    while (f >> x) {
        adaugInStiva(vfStiva, x);
    }
    afisare(vfStiva);  
    creare(prim, ultim);
    afisare(prim);
    if(sumaStiva(vfStiva)) concatenareInCoada(vfStiva, ultim);
        else concatenareInStiva(prim, vfStiva);
    afisare(prim); 
    afisare(vfStiva);
    f.close();
    return 0;
}
