#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int mat[10][10], n, m, v[10];

void create_mat()
{
    ifstream file("text/data.txt");
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }
    int x, y;
    file >> n;
    while (file >> x >> y)
    {
        mat[x][y] = mat[y][x] = 1;
        d[x][y] = d[y][x] = 1;
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

bool is_conex()
{
    for (int i = 1; i <= n; i++)
        if (!v[i])
            return false;

    return true;
}

void create_vec()
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

void afisare_grade()
{
    cout << "\nVectorul de grade ";
    for (int i = 1; i <= len; i++)
    {
        cout << grade[i] << " ";
    }
}

int main()
{
    create_mat();
    display(mat);

    char input;
    cout << "Ce metoda de parcurge veti folosi? (D/B): ";
    cin >> input;

    int start;
    cout << "Nodul de start va fi: ";
    cin >> start;

    init_v();

    if (input == 'd')
        dfs(start);
    else if (input == 'b')
        bfs(start);

    if (is_conex())
        cout << "\n\nGraful este conex";
    else
        cout << "\n\nGraful nu este conex";

    return 0;
}
