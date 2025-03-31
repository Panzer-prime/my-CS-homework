#include <iostream>
#include <fstream>

using namespace std;

int n, mat[10][10], nr[100], len;

void create_mat()
{
    fstream file("text/graf.txt");
    file >> n;
    int x, y;
    while (file >> x >> y)
        mat[x][y] = 1;
}

void get_degrees_i()
{
    for (int i = 1; i <= n; i++)
    {
        in[i] = 0; // Initialize degree counters
        for (int j = 1; j <= n; j++)
        {
            in[i] += mat[j][i]; // Count incoming edges
        }
    }
}

void get_degrees_o()
{
    for (int i = 1; i <= n; i++)
    {4
        out[i] = 0; // Initialize degree counters
        for (int j = 1; j <= n; j++)
        {
            out[i] += mat[i][j]; // Count outgoing edges
        }
    }
}

void read_nr()
{
    cout << "Introdu lungimea vectorului de nr: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "introdu elementul de pe pozitia " << i << ": " cin >> nr[i];
    }
}

int is_chain()
{
    for (int i = 1; i < len; i++)
        if (!mat[v[i]][v[i + 1]])
            return 0;

    return 1;
}


bool is_tournament() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && !(mat[i][j] || mat[j][i])) {
                return false;
            }
        }
    }
    return true;
}

void bfs(int node)
{
    int start = 1, end = 1, x[100], v[100];
    x[start] = node;

    v[node] = 1;

    while (start <= end)
    {
        int current = x[start];

        cout << " " << current;

        for (int i = 1; i <= n; i++)
        {
            if (v[current] && mat[current][i])
            {
                v[current] = 1;
                x[end++] = i;
            }
        }

        start++;
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

void display(int a[10][10])
{
    cout << "\nMatricea de adiacenta:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << " " << a[i][j];
        cout << endl;
    }
    cout << "-----------------------------\n";
}

int main()
{
}