#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int st[100], n, sol;
int TARI[10][10];
char culori[5][10]={" ","rosu","galben","albastru","verde"};


void afisare(int k){
    cout << "solutia nr: " << sol << " \n";
    for(int i = 1; i<= k; i++){
        cout<<"Tara "<<i<<" are culoarea: "<<culori[st[i]]<<endl;
    }
}

int valid(int k){
    for(int i = 1; i < k; i++){
        if(TARI[i][k] == 0 && st[i] == st[k])
            return 0;
    }
    return 1;
}

void back(int k){
    int i;
    if(k == n + 1){
        sol++;
        afisare(k);
    } else {
        for(i = 1; i <= 4; i++){
            st[k] = i;
            if(valid(k))
                back(k + 1);
        }
    }
}

void readFromFile(){
    int x;
    ifstream file("input.txt");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<=n; j++){
            file>>TARI[i][j];
        }

    }
}


int main(){
    cout << "Enter n: ";
    cin >> n;
    readFromFile();
    back(1);
    cout << "number of solutions: " << sol;
    return 0;
}
