#include<iostream>
#include<fstream>

using namespace std;

struct nod {
    int util;
    nod* urm;
};

int nr = 0;

void adaugPrim(nod* &prim, nod* &ultim, int x){
    prim = new nod;
    prim->util = x;
    prim->urm = NULL;
    ultim = prim;
}

void adaug_dupa_ultim(nod* &ultim, int x){
    nod *p = new nod;
    p->util = x;
    p->urm = NULL;
    ultim->urm = p;
    ultim = p;
}

void creare(nod* &prim, nod* &ultim){
    prim = ultim = NULL;
    int x;

    ifstream f("numere.txt");
    f >> x;
    adaugPrim(prim, ultim, x);
    nr++;
    while(f >> x){
        nr++;
        adaug_dupa_ultim(ultim, x);
    }
    f.close();
}

void afisare(nod* prim){
    nod* p;
    for(p = prim; p != NULL; p = p->urm)
        cout << p->util << " ";
    cout << endl;
}

void stergere(nod* &prim){
    nod* p;
    if(prim){
        p = prim;
        prim = prim->urm;
        delete p;
    } else {
        cout << "coada vida" << endl;
    }
}

int Crescatoare(nod* prim){
    nod* p = prim;
    while(p->urm != NULL){
        if(p->util > p->urm->util){
            return 0;
        }
        p = p->urm;
    }
    return 1;
}

int sumaNeg(nod* prim){
    int sumNeg = 0;
    for(nod* p = prim; p != NULL; p = p->urm){
        if(p->util < 0) sumNeg += p->util;
    }
    return sumNeg;
}

void maxim(nod* prim){
    nod* p = prim;
    int maxN = p->util;
    int poz = 1;
    int maxPoz = 1;
    while(p != NULL){
        if(p->util > maxN){
            maxN = p->util;
            maxPoz = poz;
        }
        p = p->urm;
        poz++;
    }

    cout << "Maximul este: " << maxN << " si se afla la pozitia: " << maxPoz << endl;
}



int main() {
    nod* prim = NULL;
    nod* ultim = NULL;
    int x;
    creare(prim, ultim);
    afisare(prim);
    cout << nr << endl;
    if(Crescatoare(prim))
        cout << "\nEste crescatoare";
    else
        cout << "\nNu este crescatoare";
    cout << "Suma numerelor negative: " << sumaNeg(prim) << endl;
    maxim(prim);
    
    return 0;
}
