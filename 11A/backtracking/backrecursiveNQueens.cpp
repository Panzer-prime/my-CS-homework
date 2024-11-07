#include<iostream>
#include<cmath>
using namespace std;

int st[100], n, sol;

void afisare(int k){
    cout << "solutia nr: " << sol << " \n";
    for(int i = 1; i <= n; i++){ // Rows
        for(int j = 1; j <= n; j++){ // Columns
            if(st[i] == j)cout << "Q \t";
            else cout << "* \t";
        }
        cout << endl;
    }
    cout << endl;
}

int valid(int k){
    for(int i = 1; i < k; i++){
        if(st[k] == st[i] || abs(st[k] - st[i]) == abs(k - i))
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
        for(i = 1; i <= n; i++){
            st[k] = i;
            if(valid(k))
                back(k + 1);
        }
    }
}

int main(){
    cout << "Enter n: ";
    cin >> n;
    back(1);
    cout << "number of solutions: " << sol;
    return 0;
}
