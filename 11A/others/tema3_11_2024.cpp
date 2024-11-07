#include <iostream>

using namespace std;

void creareV(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "enter number for position " << i<< " ";
        cin >> a[i];
    }

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

int main()
{
    int n;
    cout << "enter an number: ";
    cin >> n;
    int a[n];
    creareV(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}