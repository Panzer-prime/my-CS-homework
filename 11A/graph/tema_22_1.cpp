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

void find_vecini(int nod){
    for(int i = 0; i< len; i++){
        if(muchii[i].x == nod){
            cout<<"\nvecin pentru "<<nod<<" este "<<muchii[i].y;
        }else if(muchii[i].y== nod){
            cout<<"\nvecin pentru "<<nod<<" este "<<muchii[i].x;
        }
    }
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
int main()
{

    create_matrice_adiacenta();
    create_vec_muchii();

    afisare_mat();
    afisare_vec_muchii(); 

    afisare_real_mat();

    int nod;
    cout<<"\nce nod va fi cautat? ";
    cin>>nod;

    find_vecini(nod);
}