#include<iostream>
#include<fstream>

using namespace std;

struct nod{
    int info;
    nod* next;
};

int n;

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
    cout<<"elementul din coada este ";
    cin>>x;

    adaugaPrim(prim, ultim, x);
    for(int i = 0; i<n-1; i++){

        cout<<"elementul din coada este ";
        cin>>x;
        adaugaDupaUltim(ultim , x);
    }
}

void eliminare(nod* &prim){
    nod* p;
    if(prim){
        p = prim;
        prim = prim->next;
        delete p;
    } else cout << "Nr de elemente non existent";
}

void afisare(nod* prim){
    nod* p;
    for(p = prim; p != NULL; p = p->next) cout<<p->info<<" ";
    cout<<endl;
}

void adaugInStiva(nod* &vfStiva, int x){
    nod* p = new nod;
    p->info = x;
    if(vfStiva){
        p->next = vfStiva;
        vfStiva = p;
    }else {
        p->next = NULL;
        vfStiva = p;
    }
}

void creareStiva(nod* &vfStiva){
    int x;
    for(int i = 0; i<n; i++){
        cout<<"elementul din stiva este: ";
        cin>>x;
        adaugInStiva(vfStiva, x);
    }
}

int crescator(nod* &prim){
    nod* p;
    int ok = 0;
    for(p = prim; p ->next != NULL; p = p ->next){
        if(p->info > p->next->info) {
            ok = 1;
            break;
        }
    }
    return ok;
}

void numareImpare(nod* &prim, nod* &vfStiva){
    int nrImpare = 0;
    nod* p;
    for(p = vfStiva; p != NULL; p = p->next){
        if(p->info % 2 ==1) nrImpare++;
    }
    cout<<nrImpare<<endl;
    for(int i = 0; i < nrImpare; i++){
     eliminare(prim);
     cout<<i;
    }
}


void nrTastatura(nod* &prim){
    int x, nr = 0;
    nod* p;
    cout<<"Introdu numarul de la tastatura: "; cin>>x;
    for(p = prim; p != NULL; p = p->next){
        if(p->info == x) nr++;
    }

    for(int i = 0; i<nr; i++) eliminare(prim);
}

int main() {
    nod* prim, *ultim, *vfStiva = NULL;
    int x;
    cout<<"Cate elemente vor fi introduse: "; cin>>n;
    creareStiva(vfStiva);
    cout<<endl;
    creare(prim, ultim);

    cout<<"\nElementele din stiva ";
    afisare(vfStiva);
    cout<<"\nElementele din coada ";
    afisare(prim);

    if(crescator(vfStiva)) numareImpare(prim, vfStiva);
    else nrTastatura(vfStiva);

    cout<<"\nElementele din stiva ";
    afisare(vfStiva);
    cout<<"\nElementele din coada ";
    afisare(prim);
    cout<<crescator(vfStiva);
    return 0;
}
