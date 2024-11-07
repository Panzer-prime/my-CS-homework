#include<iostream>

using namespace std;

int st[100], n, m, sol;

int succesor(int k) {
    if (st[k] < m) { 
        st[k]++;
        return 1;
    }
    return 0;
}

int validare(int k) {
    if (k > 1 && st[k] <= st[k-1] + 1) return 0;
    return 1;
}


void afisare() {
    int result[100] = {0}; 
    
    for (int i = 1; i <= n; i++) {
        result[st[i]] = i;
    }
    
    for (int i = 1; i <= m; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int solutie(int k) {
    return (k == n);
}

void back() {
    int k = 1, as, ev;
    st[k] = 0;

    while (k > 0) {
        as = 1;
        ev = 0;
        while (as && !ev) {
            as = succesor(k);
            if (as)
                ev = validare(k);
        }

        if (!as) {
            k--;
        } else if (solutie(k)) {
            afisare();
            sol++;
        } else {
            k++;
            st[k] = st[k - 1];
        }
    }
}

int main() {
    do{
    cout << "Enter the nr of exams: ";
    cin >> n;
    cout << "Enter the nr of days: ";
    cin >> m;
    if (m < n * 2) {
        cout << "Inca o data" << endl;
    }

    }while(m < n * 2);
    
    back();
    cout << "Number of solutions: " << sol << endl;

    return 0;
}
