#include <iostream>
#include <fstream>

using namespace std;

int n, m, a[10][10], st[100], k, x, y, is, nr;

void create_mat(){
    ifstream file("graf.txt");
    file >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            file >> a[i][j];
        }
    }
    file.close();
}

void init(){
    st[k] = 0;
}

int succesor(){
    if(st[k] < n){
        st[k]++;
        return 1;
    }
    return 0;
}

int valid(){
    if (k > 1 && a[st[k-1]][st[k]] == 0) return 0;
    
    for (int i = 1; i < k; i++){
        if (st[k] == st[i]) return 0;
    }

    return 1;
}

int solutie(){
    return st[k] == y;
}

void afisare_lant(){
    is = 1;
    for (int i = 1; i <= k; i++) cout << st[i] << " ";
    cout << endl;
    // nr++;
}

void bt(){
    k = 2;
    int as = 1, ev = 0;
    init();

    while (k > 1){
        as = 1; ev = 0;
        while(as && !ev){
            as = succesor();
            if(as) ev = valid();
        }
        if(!as){
            k--;
        }else if(solutie()){
            nr++;
            afisare_lant();
        }else{
            k++;
            init();
        }
    }
}

void afisare_matrice_adiacenta(){
    cout << "\nMatricea de adiacenta:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << "\n";
}

int main(){
    create_mat();
    afisare_matrice_adiacenta();
    cout << "Introdu x:  ";
    cin >> x;
    cout << "introdu y:  ";
    cin >> y;

    is = 0;
    st[1] = x;
    bt();
    if(!is) cout << "Nu exista lant"; 

    cout << "Avem " << nr << " soluti";

    // for(x = 1; x <= n; x++)
    //     for(y = 1; y <= n; y++) {
    //         if (x!=y) {
    //             st[1] = x;
    //             bt();
    //         }
    //     }

    // if(nr) cout << "Avem " << nr << " lanturi elementare!";
    // else cout << "Nu avem lanturi elementare";
}
