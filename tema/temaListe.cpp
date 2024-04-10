#include<iostream>
#include<fstream>

using namespace std;

struct nod{
    int inf; 
    nod* next;
};

void inserarePrim(nod* &cap, int x){
    nod* p = new nod;
    p ->inf = x;
    p->next = cap;
    cap = p;
}

void adaugaDupaUltim(nod* &cap, int x){
    nod* p = new nod;
     p->inf = x;
     p->next = NULL;
     if(cap == NULL){
        cap = p;
        return ;
     }else{
        nod* temp = cap;
        while(temp->next) temp = temp ->next;
        temp ->next = p;
     }
}

void creare(nod*  &cap){
    ifstream f("numere.txt");
    int x;
    f>>x;
    while(f>>x){
        adaugaDupaUltim(cap, x);
    }
f.close();
}


void afisare(nod* cap){
    nod* p; 
    for(p = cap; p != NULL; p = p->next){
        cout<<p->inf<<" ";
    }
    cout<<endl;
}

void sortare(nod* &cap){
      if (cap == NULL || cap->next == NULL) {
    return; 
  }

  for (nod* p = cap; p->next->next != NULL; p = p->next) {
    for (nod* j = p->next; j != NULL; j = j->next) {
      if (p->inf > j->inf) { 
        nod* temp = j->next;
        j->next = p->next;
        p->next = j;
        temp = p;
        p = j;
        j = temp;
      }
    }
  }
}



int main(){

    
    return 0;
}
