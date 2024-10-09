#include<iostream>

using namespace std; 

int k, st[100], as, ev, n, p;

int succesor(){
    if(st[k] < n - p + k){
        st[k]++;
        return 1;
    }

    return 0;
}


int validare(){
        for(int i = 1; i < k; i++){
            if(st[i] == st[k]) return 0;
        }
    return 1;
}

void afisare(){
    for(int i = 1; i <= p; i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
}


int solutie(){
    return (k == p);
}

void back(){
    k = 1;
    st[k] = 0;

    while(k > 0){
        as = 1; 
        ev = 0; 
        while(as && !ev){
            as = succesor();
            if(as)
                ev = validare();
        }

       if (!as) {
            k--;  
        } else if (solutie()) {
            afisare();  
        } else {
            k++;  
            st[k] = st[k-1];
        }
    }
}

int main(){
    cout<<"introdu un n\n";
    cin>>n;
    cout<<"introdu un p\n";
    cin>>p;

    back();
}