#include<iostream>
#include<string.h>
using namespace std;


int st[100], n, countries[20][20], nr;
char culori[20][100];


void afisare(){
    cout<<"solutia:"<<nr<<endl;
    for(int i = 1; i<= n; i++){
        cout<<"Tara "<<i<<"are culoarea: "<<culori[st[i]]<<i<<" "<< st[i]<<endl;
    }
}

int succesor(int k){
    if(st[k] <= n){
        st[k]++;
        return 1;
    }

    return 0;
}

int valid(int k){
    for(int i = 1; i<=n; i++){
        if(countries[i][k] == 1 && st[i] == st[k]) return 0;
    }
    return 1;
}

int solutie(int k){
    return (n == k);
}



void back(){
    int k = 1, ev, as;
    st[k]= 0;
    while(k > 0){
        ev = 0; 
        as = 1; 
        while(as && !ev){
            as = succesor(k);
            if(as){
                ev = valid(k);
            }
        }

        if(!as)k--;
        else if(solutie(k)){
            nr++;
            afisare();
        }else{
            k++;
            st[k]++;
        }
    }
}


void country(){
    cout << "Introdu vecinii pentru fiecare tara (1 pentru vecini, 0 altfel):\n";
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            cout << "Sunt tara " << i << " si tara " << j << " vecine? (1/0): ";
            cin >> countries[i][j];
            countries[j][i] = countries[i][j];
        }
    }
}


void readColors(int n){
    strcpy(culori[0], "");
    for(int i = 1; i<=n; i++){
        cout<<"introdu culoarea de pe pozitea "<<i<<": ";
        cin>>culori[i];
    }
}

int main(){
    cout << "Cate tari sunt? ";
    cin >> n;
    country();

    cout << "Cate culori vei dori sa introduci: ";
    cin >> n;
    readColors(n);

    back();

    return 0;
}
