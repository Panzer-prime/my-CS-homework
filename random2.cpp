#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int mat[10][10], n, m, v[10], d[10][10];

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
void conex()
{
   
    int count = 0;

    cout << "\n\nComponentele conexe ale grafului sunt:\n";
    for (int i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            count++;
            cout << "Componenta conexa " << count << ":";
            dfs(i);
            cout << endl;
        }
    }
}
int main()
{
    create_mat();
    display(mat);

    char input;
    cout << "Ce metoda de parcurgere veti folosi? (D/B): ";
    cin >> input;

    int start;
    cout << "Nodul de start va fi: ";
    cin >> start;


    if (input == 'd'){
        cout<<"Parcurgerea in adancime aplicata pe graf este: \n\t";
        dfs(start);
    }

    else if (input == 'b'){
        cout<<"Parcurgerea in latime aplicata pe graf este: \n\t";
        bfs(start);
    }
    

    if (is_conex())
        cout << "\n\nGraful este conex";
    else
        cout << "\n\nGraful nu este conex";

    init_v();
    conex();

    return 0;
}
