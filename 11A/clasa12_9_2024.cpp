#include <iostream>
#include <cmath>

using namespace std;

long unsigned prim(unsigned n)
{
    int i, x;
    if (n % 2 == 0 && n != 2)
        return 0;

    for (i = 3; i <= sqrt(n) && x; i += 2)
    {
        if (n % i == 0)
            x = 0;
    }
    return x;
}

void scrie(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "introdu nr de pe pozitia " << i << ": ";
        cin >> a[i];
    }
}

void separare(int a[], int b[], int &lenB, int c[], int &lenC, int n)
{
    lenB = 0;
    lenC = 0;

    for (int i = 0; i < n; i++)
    {
        if (prim(a[i]))
            b[lenB++] = a[i];
        else
            c[lenC++] = a[i];
    }
}

void sortCrescatoare(int a[], int n)
{
    int aux;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}

void sortDescrescatoare(int a[], int n)
{
    int aux;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}

void afisare(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nnr de pozitea " << i << ": " << a[i];
    }
    cout << endl; // Just to make output clearer
}

int main()
{
    int n, a[100], b[100], c[100];

    cout << "introdu un nr: ";
    cin >> n;

    scrie(a, n);

    cout << "Vectorul principal a: ";
    afisare(a, n);

    int lenB, lenC;
    separare(a, b, lenB, c, lenC, n);

    sortCrescatoare(b, lenB);
    sortDescrescatoare(c, lenC);

    cout << "vector B (prim):\n";
    afisare(b, lenB);
    cout << "vector C (non-prim):\n";
    afisare(c, lenC);


    return 0;
}
