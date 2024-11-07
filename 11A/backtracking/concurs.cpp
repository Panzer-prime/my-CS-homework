#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct spotiv
{
    int nrConcurs;
    char tara[30];
};

spotiv concurenti[40];

int n, st[100], nr;
void readFromFile()
{
    ifstream file("input.txt");
    char tara[30];
    int i = 0, nrConcurs;
    while (file >> tara >> nrConcurs)
    {
        strcpy(concurenti[i].tara, tara);
        concurenti[i].nrConcurs = nrConcurs;
        i++;
    }
    n = i;

    file.close();
}

void afisare()
{
    cout << "Solutia " << nr << ": ";
    for (int i = 1; i <= n; i++)
    {
        cout << concurenti[st[i]].tara << " (" << concurenti[st[i]].nrConcurs << ") ";
    }
    cout << endl;
}

int succesor(int k)
{
    if (st[k] <= n)
    {
        st[k]++;
        return 1;
    }

    return 0;
}

int valid(int k)
{
    if (k > 1)
    {
        if (st[k] == st[k - 1])
            return 0;
    }

    return 1;
}

int solutie(int k)
{
    return (n == k);
}

void back()
{
    int k = 1, ev, as;
    st[k] = 0;
    while (k > 0)
    {
        ev = 0;
        as = 1;
        while (as && !ev)
        {
            as = succesor(k);
            if (as)
            {
                ev = valid(k);
            }
        }

        if (!as)
            k--;
        else if (solutie(k))
        {
            nr++;
            afisare();
        }
        else
        {
            k++;
            st[k]++;
        }
    }
}

int main()
{
    readFromFile(); // Read athletes from the file
    cout << "Numarul total de sportivi: " << n << endl;
    back();
}