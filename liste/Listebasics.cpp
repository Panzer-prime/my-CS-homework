#include<iostream>
#include<fstream>
#include"lista.h"
using namespace std;

void inserareDupaUnElement(nod* &cap, nod* elem, int x)
{
    nod* p = new nod;
    p->nr = x;
    p->urm = NULL;
    if (cap == NULL)
    {
        cap = p;
        return;
    }
    p->urm = elem->urm;
    elem->urm = p;
}

void cautareDupaPozitie(nod* cap, int poz)
{
    nod* p = cap;
    int i = 0;
    while (p)
    {
        if (i == poz)
        {
            cout << "elementul de pe pozitia " << i << " este : " << p->nr;
            break;
        }
        i++;
        p = p->urm;
    }
}

void cautareDupaVal(nod* cap, int val)
{
    nod* p = cap;
    int i = 0;
    while (p)
    {
        if (p->nr == val)
        {
            cout << "elementul cu valuare: " << val << " este aflat pe pozitia " << i;
            break;
        }
        i++;
        p = p->urm;
    }
}

void stergereaDupaPozitie(nod* &cap, int poz)
{
    nod* temp = cap;
    if (poz == 0)
    {
        cap = cap->urm;
        delete temp;
        return;
    }
    temp = cap;
    for (int i = 0; i < poz - 1; i++)
    {
        temp = temp->urm;
    }
    nod* deSters = temp->urm;
    temp->urm = deSters->urm;
    delete deSters;
}

void stergeDupaVal(nod* &cap, int val)
{
    nod* temp = cap;
    while (temp != NULL && temp->urm != NULL)
    {
        if (temp->urm->nr == val)
        {
            nod* deSters = temp->urm;
            temp->urm = deSters->urm;
            delete deSters;
        }
        temp = temp->urm;
    }
}

int main()
{
    nod* cap = NULL;
    int valoareNoua, pozitieCautata, valoareCautata, pozitieDeSters, valoareDeSters;
    creare(cap);
    afisare(cap);
    cout << "introdu valuare noua: ";
    cin >> valoareNoua;
    nod* element = cap;
    inserareDupaUnElement(cap, element, valoareNoua);

    cout << "ce pozitie va fi cautata: ";
    cin >> pozitieCautata;
    cautareDupaPozitie(cap, pozitieCautata);

    cout << "ce valoare va fi cautata: ";
    cin >> valoareCautata;
    cautareDupaVal(cap, valoareCautata);

    cout << "introdu pozitia de sters: ";
    cin >> pozitieDeSters;
    cout << "\nafisarea inainte de stergere: ";
    afisare(cap);
    cout << "\nafisarea dupa stergere: ";
    stergereaDupaPozitie(cap, pozitieDeSters);
    afisare(cap);

    cout << "Introdu valoarea de sters: ";
    cin >> valoareDeSters;
    cout << "\nafisarea inainte de stergere: ";
    afisare(cap);
    cout << "\nstergerea dupa valoare: ";
    stergeDupaVal(cap, valoareDeSters);
    afisare(cap);

    return 0;
}
