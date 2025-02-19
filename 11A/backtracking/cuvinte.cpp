#include <iostream>
#include <cstring>
using namespace std;

int st[100], n, nr = 0;
char cuv[] = {' ', 'I', 'N', 'F', 'O'}; 

void afisare() {
    cout << "Solutia " << nr << ": ";
    for (int i = 1; i <= n; i++) {
        cout << cuv[st[i]]; 
    }
    cout << endl;
}

int succesor(int k) {
    if (st[k] < n) { 
        st[k]++;
        return 1;
    }
    return 0;
}

int valid(int k) {
    for (int i = 1; i < k; i++) { 
        if (st[k] == st[i]) return 0;
    }
    return 1;
}

int solutie(int k) {
    return (k == n); 
}

void back() {
    int k = 1, ev, as;
    st[k] = 0; 
    while (k > 0) {
        ev = 0; 
        as = 1;
        while (as && !ev) {
            as = succesor(k); 
            if (as) ev = valid(k); 
        }

        if (!as) { 
            k--;
        } else if (solutie(k)) { 
            nr++;
            afisare();
        } else { 
            k++;
            st[k] = 0; 
        }
    }
}

int main() {
    n = strlen(cuv) - 1;
    cout << "Se vor genera toate permutarile posibile pentru cuvantul INFO." << endl;
    back();

    cout << "Numarul total de solutii: " << nr << endl;
    return 0;
}
