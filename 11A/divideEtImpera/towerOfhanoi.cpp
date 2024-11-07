#include<iostream>

using namespace std;

void towerOfHanoi(int n,char a, char b, char c){
    if(n == 1){
        cout<<a<<b<<endl;
    }else{
        towerOfHanoi(n-1, a, c, b);
        cout<<a<<b<<endl;
        towerOfHanoi(n-1, c,b,a);
    }
}


int main(){
    int i, result = 0;
    cout<<"Introdu numarul de elemente n: ";
    cin>>n;

    towerOfHanoi(n, 'a', 'b', 'c');
}

/*
Introdu numarul de elemente n: 3
ab
ac
bc
ab
ca
cb
ab
*/
