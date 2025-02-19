#include<iostream>
#include<fstream>

using namespace std;

int a[10][10], d[10][10],n;

void citire(){

    fstream file("data.txt");
    if(!file.is_open()){
        cout<<"nu este nimic aici ";
        return;
        
    }
    int x,y;
    file>>n;
    while(file>>x>>y)
        a[x][y] = a[y][x] = 1;
        d[x][y] = d[y][x] = 1;
        

}

void write(int mat[10][10]){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<= n; j++){
            cout<<mat[i][j] <<" ";
        }
        cout<<endl;
    }
    
}

void roy(){
    int nr = 1;
    for(int k = 1; k<= n; k++){
        for(int i = 1; i<= n; i++){
            if(a[i][k]){
                for(int j = 1; j<= n; j++){
                    if(a[k][j]){
                        d[i][j] = 1;
                        cout<<"solutia nr: "<<nr<<endl;
                        write(d);
                        nr++;
                    }
                        
                }
            }
        }
    }
}


int check(){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<= n; j++){
            if(!d[i][j]) return 0;
        }
    }

    return 1;
}

int main(){
    citire();
    cout<<"matricea de adiacenta este \n";
    write(a);

    roy();
    cout<<"matrice drumurilor este: \n";
    write(d);

    if(check()) cout<<"matricea este conexa\n";
    else cout<<"matrice nu este conexa \n";
    
}