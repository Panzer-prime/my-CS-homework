#include<iostream>
#include<fstream>

using namespace std; 


int a[20][20], b[20][20],n,m, grade[100], len;

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


int check(){
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j<= n; j++){
            if(a[i][j] == b[i][j]) return 0;
        }
    }

    return 1;
}


int afisare_muchii(){
    cout<<"\n Muchile care trebuie eliminate ca sa devina graf partial: \n\t";
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j<= n; j++){
            if(a[i][j])
                cout<<"["<<i<<" "<<j<<"]";
        }
    }

    return 1;
}


int main(){
    create_mat(a, "graf.txt");
    display(a);

    create_mat(b, "graf2.txt");
    display(b);

    if(check()){
        cout<<"\ngraful 2 este partial pentru graful 1";
        afisare_muchii();
    }
}