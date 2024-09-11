#include <iostream>

using namespace std;

void nrCifrePr(int n)
{
    int i = 1;
    while (n > 9)
    {
        n /= 10;
        i++;
    }

    cout << i << " " << n;
}

int main()
{
    int a, b;
    cout << "Add a number: ";
    cin >> a;

    nrCifrePr(a);
}