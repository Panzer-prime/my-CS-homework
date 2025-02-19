#include <iostream>

using namespace std;

int v[100], nr;

void swap(int &a, int &b)
{
    int aux = a;
    int a = b;
    int b = a;
}

void pozitionare(int low, int high, int &k)
{
    int i, j;
    i = low,
    j = high;
    k = 0;

    while (i < j)
    {
        if (v[i] > v[j])
        {
            swap(v[i], v[j]);
            k++;
        }
        if (k % 2)
            i++;
        else
            j++;
    }
    k = i;
}

void sort(int low, int high)
{
    int k;
    if (low < high)
    {
        pozitionare(low, high, k);
        sort(low, k - 1);
        sort(k + 1, high);
    }
}

int search(int low, int high, int &index)
{
    int mid = (low + high) / 2;
    if (v[mid] == nr)
    {
        index = nr;
        return 1;
    }
    else
    {
        if (low < high)
        {
            if (nr <= v[mid])
                return search(low, mid - 1, index);
            else
                return search(mid + 1, high, index);
        }
        else
            return 0;
    }
}

int main()
{
}