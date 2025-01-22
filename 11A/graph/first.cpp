#include<iostream>
#include<fstream>

using namespace std;

ifstream file("data.txt");

void createa_graph(int mat[10][10], int m){
    int x,y;
    for(int i = 1; i <= m; i++){
        file >> x >> y;
        mat[x][y] = mat[y][x] = 1;
          
    }

}

bool check_graph(int mat[10][10], int n){

    for(int i = 1; i < n; i++){
        for(int j =i + 1; j <= n; j++){
            if(mat[i][j] != mat[j][i]){
                return false;
            }
        }
    }

    return true;
}

void display_graph(int mat[10][10], int n){

    cout<<"afisare graf\n";

    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(mat[i][j])
                cout<<"["<<i<<","<<j<<"] ";
        }
    }
}



int main(){

    int mat[10][10] = {0}, m ,n;
    file >> m>>n;

    createa_graph(mat, m);
    display_graph(mat, n);
    if(check_graph(mat, n)){
        cout<<"este neorientat";
    }


    
}