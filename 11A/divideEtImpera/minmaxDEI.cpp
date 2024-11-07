#include<iostream>

using namespace std;
int v[100],n;

int maximum = 0;

void dei(int stanga, int dreapta, int &maximum, int &minimum){
    int mid, x1,x2;
    if(dreapta == stanga){
        maximum= v[stanga];
        minimum= v[stanga];
    }else{
        mid = (stanga+dreapta)/2;
        dei(stanga,mid,x1,x2);
        int left_max = x1, left_min = x2;
        dei(mid+1, dreapta, x1,x2);
        int right_max = x1, right_min = x2;
        if (left_max > right_max) {
            maximum = left_max;
        } else {
            maximum = right_max;
        }
        
        if (left_min < right_min) {
            minimum = left_min;
        } else {
            minimum = right_min;
        }
    }
}
int main(){
    int i, maximum = 0, minimum = 0;
    cout<<"Introdu numarul de elemente n: ";
    cin>>n;

    for(int i = 1; i <= n; i++){
        cout<<"Elementul de pe pozitia "<<i<<" este: ";
        cin>>v[i];
    }

    dei(1,n,maximum, minimum);
    cout<<"cel mai mare este "<< maximum;
    cout<< "\ncel mai mic este " << minimum;
}
