#include <iostream>

using namespace std;


void dei(int stanga, int dreapta, int &fact) {
    if (stanga == dreapta) {
        
        fact = stanga;
    } else {
        int mid = (stanga + dreapta) / 2;
        int p1 = 1, p2 = 1;

        dei(stanga, mid, p1);
        dei(mid + 1, dreapta, p2);

        fact = p1 * p2;
    }
}

int main() {
    int n, fact = 0;
    cout << "Introdu numarul de elemente n: ";
    cin >> n;

    dei(1, n, fact);

    cout << "fact elementelor din serie este: " << fact << endl;

    return 0;
}
