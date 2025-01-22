#include <iostream>
#include <fstream>
#include <cmath>
#include<vector>



using namespace std;

ifstream f("data.txt");
int a[10][10], b[100], m, n, minim;

vector<int> g;


void creare_matrice_adiacenta()
{
    int i, x, y;
    f >> n >> m;
    
    for (int i = 1; i <= m; i++)
    {
        f >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    f.close();
}

void vector_grade()
{
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum += a[i][j];
        b[i] = sum;
    }
}

void afisare_vector_grade()
{
    cout << "\nVectorul gradelor nodurilor:\n";
    cout << "d = {";
    for (int i = 1; i < n; i++)
        cout << b[i] << ", ";
    cout << b[n] << "}";
    cout << "\n-----------------------------\n";
}

void afisare_matrice_adiacenta()
{
    cout << "\nMatricea de adiacenta:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << "-----------------------------\n";
}

void gradul_minim()
{
    minim = b[1];
    for (int i = 2; i <= n; i++)
        if (b[i] < minim)
            minim = b[i];

    cout << "\nNodurile cu grad minim (" << minim << ") sunt: ";
    for (int i = 1; i <= n; i++)
        if (b[i] == minim)
            cout << i << " ";
    cout << "\n-----------------------------\n";
}

void izolate()
{
    int k = 0;
    for (int i = 1; i <= n; i++)
        if (b[i] == 0)
            k++;
    cout << "\nNoduri izolate: ";
    if (k > 0)
    {
        for (int i = 1; i <= n; i++)
            if (b[i] == 0)
                cout << i << " ";
        cout << "\nIn graf sunt " << k << " noduri izolate.";
    }
    else
        cout << "Nu exista noduri izolate in graf.";
    cout << "\n-----------------------------\n";
}

void terminale()
{
    cout << "\nNodurile terminale din graful neorientat sunt: ";
    for (int i = 1; i <= n; i++)
        if (b[i] == 1)
            cout << i << " ";
}

int main()
{
    cout << "-----------------------------\n";
    cout << "Program pentru analiza unui graf\n";
    cout << "-----------------------------\n";

    creare_matrice_adiacenta();

    afisare_matrice_adiacenta();

    vector_grade();
    afisare_vector_grade();

    gradul_minim();

    izolate();

    terminale();

    cout << "\n-----------------------------\n";
}