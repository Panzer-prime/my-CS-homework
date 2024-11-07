#include<iostream>

using namespace std;
int v[100],n;

int result = 0;

int cmmdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void dei(int stanga, int dreapta, int &result){
    int mid, x1,x2;
    if(dreapta == stanga){
        result= v[stanga];
    }else{
        mid = (stanga+dreapta)/2;
        dei(stanga,mid,x1);
        dei(mid+1, dreapta, x2);
        result = cmmdc(x1, x2);
    }
}
int main(){
    int i, result = 0;
    cout<<"Introdu numarul de elemente n: ";
    cin>>n;

    for(int i = 1; i <= n; i++){
        cout<<"Elementul de pe pozitia "<<i<<" este: ";
        cin>>v[i];
    }

    dei(1,n,result);
    cout<<"cmmdc este: "<<result;
}
