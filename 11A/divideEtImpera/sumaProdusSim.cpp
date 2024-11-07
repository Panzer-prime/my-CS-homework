#include<iostream>

using namespace std;

int v[100],n;

void dei(int stanga, int dreapta, int &suma, int& produs){
    int mid, s1 = 0, s2= 0, p1 =1, p2 = 1;
    if(dreapta == stanga){
        suma= v[stanga];
        produs = v[stanga];
    }else{
        mid = (stanga+dreapta)/2;
        dei(stanga,mid,s1, p1);
        dei(mid+1, dreapta, s2, p2);
        suma = s1 + s2;
        produs = p1 * p2;
    }
}
int main(){
    int i, suma = 0, produs = 1;
    cout<<"Introdu numarul de elemente n: ";
    cin>>n;

    for(int i = 1; i <= n; i++){
        cout<<"Elementul de pe pozitia "<<i<<" este: ";
        cin>>v[i];
    }

    dei(1,n,suma, produs);
    cout<<"Produsul vectorului este: "<<produs<<endl;
    cout<<"Suma elementelor din vector este: "<<suma<<endl;
}