#include <iostream>

using namespace std;
int x[100], n;

void citire(int low, int high)
{
    int mijloc;
    if (low == high)
    {
        cout << "\nElem de pe pozitia " << low << ": ";
        cin >> x[low];
    }
    else
    {
        mijloc = (low + high) / 2;
        citire(low, mijloc);
        citire(mijloc + 1, high);
    }
}
void afisare(int low, int high)
{
    int mijloc;
    if (low == high)
        cout << x[low] << " ";
    else
    {
        mijloc = (low + high) / 2;
        afisare(low, mijloc);
        afisare(mijloc + 1, high);
    }
}

void suma_elemente_par(int low, int high, int &value)
{
    int x1 = 0, x2 = 0;
    if (low == high)
    {
        if ((x[low] >= 10 && x[low] < 100) && x[low] % 2 == 0)
            value += x[low];
    }

    else
    {
        int middle = (low + high) / 2;
        suma_elemente_par(low, middle, x1);
        suma_elemente_par(middle + 1, high, x2);
        value += x1 + x2;
    }
}

int checkIfArrayEqual(int low, int high)
{
    int check1 = 1, check2 = 1;
    if (high == low)
        return 1;

    if (high - low == 1)
    {
        if (x[high] != x[low])
            return 0;
        else
            return 1;
    }
    else
    {
        int middle = (high + low) / 2;

        check1 = checkIfArrayEqual(low, middle);
        check2 = checkIfArrayEqual(middle + 1, high);
        return check1 && check2;
    }
}

void getTheBiggestValue(int low, int high, int &max)
{
    int mid, x1, x2;
    if (high == low)
        max = x[low];
    else
    {
        mid = (low + high) / 2;
        getTheBiggestValue(low, mid, x1);
        getTheBiggestValue(mid + 1, high, x2);
        if (x1 > x2)
            max = x1;
        else
            max = x2;
    }
}

int impare_pare(int low, int high)
{
    if (low == high)
    {
        if (x[low] % 2 == 1 && low % 2 == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        int middle = (low + high) / 2;
        int k1 = impare_pare(low, middle);
        int k2 = impare_pare(middle + 1, high);

        return k1 + k2;
    }
}

int isSorted(int low, int high)
{

    int check1 = 1, check2 = 1;
    if (high == low)
        return 1;

    if (low + 1 <= high)
        return x[low] >= x[high];    
    else
    {
        int middle = (high + low) / 2;

        check1 = isSorted(low, middle);
        check2 = isSorted(middle + 1, high);
        return check1 && check2;
    }
}

int main()
{
    int suma = 0, max = 0;
    cout << "Enter the length of the array: ";
    cin >> n;

    citire(0, n - 1);
    cout << "check if all the elements of the array are the same: \n";

    if (checkIfArrayEqual(0, n - 1))
        cout << "elementele nu sunt toate la fel\n";
    else
        cout << "\nelementele sunt egale";

    suma_elemente_par(0, n - 1, suma);

    cout << "\nget the biggest value from the array: ";
    getTheBiggestValue(0, n - 1, max);
    cout << "\nmax from the array: " << max;

    cout << "\nvalues din cea dea a 2 jumatate : ";
    getTheBiggestValue(n / 2, n - 1, max);
    cout << "\nmax from the array: " << max;
    cout << "cate numere impare pe poziti pare sunt: " << impare_pare(0, n - 1);


    if(isSorted(0, n-1)) cout<<"este sortat crescator";
    else cout<<"nu este sortat descrescator";


    return 0;
}
