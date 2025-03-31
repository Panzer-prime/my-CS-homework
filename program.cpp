#include <iostream>
#include <fstream>

using namespace std;

typedef int stiva[100];

int a[10][10], n, k, m, este = 0;
int x, y;
stiva st;

void create_mat() {
    int x, y;
    ifstream f("../text/graf.txt");
    f >> n;
    while (f >> x >> y) {
        a[x][y] = 1;
        m++;
    }
    f.close();
}

int valid() {
    if (k > 1) {
        if (a[st[k - 1]][st[k]] == 0) return 0;
    }
    for (int i = 1; i < k; i++) {
        if (st[k] == st[i]) return 0;
    }
    return 1;
}

int solutie() {
    return st[k] == y; 
}

void bt() {
    for (int i = 1; i <= n; i++) {
        st[k + 1] = i;
        if (valid()) {
            k++;
            if (solutie()) {
                este = 1;
                for (int j = 1; j <= k; j++) {
                    cout << st[j] << " ";
                }
                cout << endl;
            } else {
                bt();
            }
            k--;
        }
    }
}

void afisare_adiacenta() {
    cout << "Matricea de adiacenta a grafului este: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    create_mat();
    afisare_adiacenta();

    for (x = 1; x <= n; x++) {
        for (y = 1; y <= n; y++) {
            if (x != y) {
                st[1] = x;
                k = 1;
                bt();
            }
        }
    }
    if (!este) cout << "Nu exista drumuri elementare!" << endl;

    return 0;
}
