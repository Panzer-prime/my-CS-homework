#include <iostream>

using namespace std;

int factorial(int x) {
    int result = 1;
    for (int i = 1; i <= x; i++) {
        result *= i;
    }
    return result;
}

void dei(int stanga, int dreapta, int &suma) {
    if (stanga == dreapta) {
        suma = factorial(stanga);
    } else {
        int mid = (stanga + dreapta) / 2;
        int s1 = 0, s2 = 0;

        dei(stanga, mid, s1);
        dei(mid + 1, dreapta, s2);

        suma = s1 + s2;
    }
}

int main() {
    int n, suma = 0;
    cout << "Introdu numarul de elemente n: ";
    cin >> n;

    // Use divide and conquer to calculate the sum of terms
    dei(1, n, suma);

    cout << "Suma elementelor din serie este: " << suma << endl;

    return 0;
}
