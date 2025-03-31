#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define inf INT64_MAX
int mat[10][10], n, m, v[10], grade[10];

void create_mat()
{
    ifstream file("text/data.txt");
  
    int x, y;
    file >> n;
    while (file >> x >> y)
    {
        mat[x][y] = mat[y][x] = 1;
    }
    file.close();
    
}

void display(int a[10][10])
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

void bfs(int start)
{
    int queue[100], left = 0, right = 0;
    v[start] = 1;
    queue[right++] = start;

    while (left < right)
    {
        int current = queue[left++];

        cout << " " << current;

        for (int i = 1; i <= n; i++)
        {
            if (mat[current][i] && !v[i])
            {
                queue[right++] = i;
                v[i] = 1;
            }
        }
    }
}

void dfs(int start)
{
    v[start] = 1;
    cout << " " << start;

    for (int i = 1; i <= n; i++)
    {
        if (mat[start][i] && !v[i])
        {
            dfs(i);
        }
    }
}

void init_v()
{
    for (int i = 1; i <= n; i++)
        v[i] = 0;
}

void check_min_f()
{
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        if (grade[i] >= 1)
        {
            cout << "\nNodul " << i << " are " << grade[i] << " relati de prietenie";
            ok = false;
        }
    }

    if (ok)
    {
        cout << "\nNu exista noduri cu cel putin o relatie de prietenie";
    }
    cout << "\n-----------------------------\n";
}

void create_vec()
{
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += mat[i][j];
        }
        grade[i] = sum;
    }
}

void afisare_grade()
{
    cout << "\nVectorul de grade ";
    for (int i = 1; i <= n; i++)
    {
        cout << grade[i] << " ";
    }
}

void check_max_f()
{
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        if (grade[i] == n - 1)
        {
            cout << "\nnodul " << i << " are relatie de 'prietenie' cu orcare alt nod";
            ok = false;
        }
    }

    if (ok)
    {
        cout << "\nNu exista noduri care au relatie de prietenie cu oricare alt nod";
    }

    cout << "\n-----------------------------\n";
}

void check_terminal()
{
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        if (grade[i] == 1)
        {
            cout << "\nNodul " << i << " are doar un prieten";
            ok = false;
        }
    }

    if (ok)
    {
        cout << "\nNu exista noduri care au doar un prieten";
    }
    cout << "\n-----------------------------\n";
}

void check_subgraf_k(int nodes[], int k)
{
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (mat[nodes[i]][nodes[j]] == 1)
            {
                count++;
            }
        }
    }

    if (count == k - 1)
        cout << "\nSubgraful format din nodurile selectate are " << count
             << " relatii de prietenie\n";

    else
        cout << "\n Subgraful nu are " << k - 1 << " relatii de prietenie";
}

int main()
{
    create_mat();
    display(mat);

    create_vec();
    afisare_grade();

    check_min_f();
    check_max_f();

    check_terminal();

    int nodes[] = {1, 3, 2, 4};
    check_subgraf_k(nodes, 4);
}