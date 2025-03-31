#include <iostream>
#include <fstream>

using namespace std;

int a[10][10], n, m = 0, x[10], v[10], grade[10];

void citire_adiacenta()
{
    int x, y;
    ifstream f("graf.txt");
    f >> n;
    while (f >> x >> y)
    {
        a[x][y] = a[y][x] = 1;
        m++;
    }
    f.close();
}

void afisare_adiacenta()
{
    cout << "Matricea de adiacenta al firmelor este: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int init_v()
{
    for (int i = 0; i < 100; i++)
    {
        v[i] = 0;
    }
}

void bfs(int start)
{
    int i, k, st = 0, dr = 0;
    x[1] = start;
    v[start] = 1;

    while (st <= dr)
    {
        k = x[st];
        cout << k << " ";
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == 0 && a[k][i] == 1)
            {
                v[i] = 1;
                x[++dr] = i;
            }
        }
        st++;
    }
}

void dfs(int start)
{
    v[start] = 1;
    cout << " " << start;

    for (int i = 1; i <= n; i++)
    {
        if (a[start][i] && !v[i])
        {
            dfs(i);
        }
    }
}

void creare_vec_grade()
{
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += a[i][j];
        }
        grade[i] = sum;
    }
}

int verificare_graf_complet()
{
    for (int i = 1; i <= n; i++)
    {
        if (grade[i] != n - 1) return 0;
    }
    return 1;
}

void intrerupe_relatia(int nod)
{
    while (nod != 0) {
        for (int i = 1; i <= n; i++) {
            a[nod][i] = a[i][nod] = 0;
        }
        cout << "Introduceti urmatorul nod care intrerupe relatia sau 0 pentru a termina: ";
        cin >> nod;
    }

    if (nod == 0) {
        cout << "\nGraful dupa interuperea relatiilor este: " << endl;
        afisare_adiacenta();
    }
}

void faliment(int nod)
{
    for (int i = 1; i <= n; i++)
    {
        a[nod][i] = a[i][nod] = 0;
    }

    for (int i = nod; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = a[i + 1][j];
            a[j][i] = a[j][i + 1];
        }
    }

    n--;

    cout << "Matricea dupa falimentul firmei " << nod << " este: " << endl;
    afisare_adiacenta();
}

int main()
{
    int g;
    citire_adiacenta();
    afisare_adiacenta();

    if (verificare_graf_complet()) cout << "Orice firma colaboreaza cu toate celelalte!" << endl;
    else cout << "Nu toate firmele colaboreaza cu celelalte!" << endl;

    cout << "\nIntroduceti numarul firmei care isi intrerupe relatiile, cand ati terminat introduceti valoarea 0: ";
    cin >> g;
    intrerupe_relatia(g);

    cout << "\nUnele firme dau faliment si nu mai pot functiona! " << endl;
    cout << "\nIntroduceti numarul firmei care da faliment, cand terminati introduceti valoarea 0: ";
    cin >> g;
    while (g != 0)
    {
        faliment(g);
        cout << "Introduceti urmatorul nod care da faliment sau 0 pentru a termina: ";
        cin >> g;
    }

    return 0;
}
