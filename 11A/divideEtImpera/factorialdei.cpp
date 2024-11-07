#include<iostream>

using namespace std;
int v[100],n;

int factorial(int stanga, int dreapta){
    if(stanga==dreapta)
        return stanga;
    else {
        int mid = (stanga+dreapta)/2;

        int factorial_stanga = factorial(stanga, mid);
        int factorial_dreapta = factorial(mid + 1, dreapta);

        return factorial_stanga * factorial_dreapta;
    }
}
int main(){
    int i;
    cout<<"n = ";
    cin>>n;

    cout << n << "! = " << factorial(1, n);
}
