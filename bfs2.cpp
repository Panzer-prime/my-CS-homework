#include<iostream>
#include<fstream>

using namespace std; 


int a[20][20], b[20][20],n,m, x[100], v[100], len, grade[100];

void create_mat(int a[20][20], const char* filename){
    fstream file(filename);
    file>>n;
    int x, y;

    while(file>>x>>y){
        a[x][y] = a[y][x] = 1;
        m++;
    }

}

void display(int a[20][20])
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


void bfs(int node){
    int start = 1, end = 1;
    x[start] = node;

    v[node] = 1;

    while(start <= end){
        int k = x[start];

        cout<<k<<" ";
        for(int i = 1; i <= n; i++){
            if(a[k][i] && v[i] == 0){
                v[i] = 1;
                x[++end] = i;
            }
        }
        start++;
    }
    
}

void create_vec(){
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j<= n; j++){
            sum += a[i][j];

        }
        grade[len++] = sum;
    }
}


void afisare_grade(){
    cout<<"\nVectorul de grade ";
    for(int i = 1; i <= len; i++){
        cout<<grade[i]<<" ";
    }
}

int reset(){
    for(int i = 1; i <=n; i++) v[i] = 0;
}

void find_min(int &min, int &maxim) {
    min = 0;
    maxim = 0;

    for (int i = 1; i <= len; i++) { 
        if (grade[i] > grade[maxim]) maxim = i;
        if (grade[i] < grade[min]) min = i;
    }

}
int main(){
    create_mat(a, "bfs.txt");
    display(a);

    create_vec();
    afisare_grade();

    for(int i = 1; i <=n; i++){
        
        cout<<"\nBFS de nodul "<<i<<":  \n\t";
        bfs(i);
        reset();
    }
 
}