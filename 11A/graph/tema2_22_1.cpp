#include <iostream>
#include <fstream>

using namespace std;

ifstream f("data.txt");
int n,m, a[10][10], len;

struct muchie{
    int x,y;
};

muchie muchii[100];

void create_matrice_adiacenta() {
    int x, y;
    f >> m >> n; 
    
    for (int i = 1; i <= m; i++) {
        f >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    f.close();
}


void create_vec_muchii(){
    for(int i = 1; i< n; i++){
        for(int j = i+1; j<= n; j++){
            if(a[i][j]){
                muchii[len].x = i;
                muchii[len].y = j;
                len++;
            }
        }
    }
}


void afisare_mat(){
    for(int i = 1; i<= n; i++){
        for(int j = i+1; j<= n; j++){
            if(a[i][j]){
                cout<<"[ "<<i<<","<<j<<"] ";
            }
        }
    }
    cout<<endl;
}


void afisare_vec_muchii(){
    cout<<"{";
     for(int i = 0; i< len; i++){
        cout<<"[ "<<muchii[i].x<<","<<muchii[i].y<<"] ";
    }
    cout<<"}";
}


void afisare_real_mat(){
    cout<<endl;
     for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            cout<<"\t"<<a[i][j];
        }
        cout<<endl;
    }

}

void get_noduri_izolate() {
    int connect[100] = {0};

   
    for (int i = 0; i < len; i++) {
        connect[muchii[i].x] = 1;
        connect[muchii[i].y] = 1;
    }

    
    cout << "noduri izolate: ";
    int izo_count = 0;
    for (int i = 1; i <= n; i++) { 
        if (!connect[i]) {
            cout << i << " "; 
            izo_count++;
        }
    }
    cout << endl;

    cout<<"numarul de noduri izolate "<<izo_count;
}
int main()
{

    create_matrice_adiacenta();
    create_vec_muchii();

    afisare_mat();
    afisare_vec_muchii(); 

    afisare_real_mat();

    cout<<"ceva "<<len<<endl;

    get_noduri_izolate();

}