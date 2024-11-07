#include <iostream>
#include <cmath> 

using namespace std;

int st[100], n, sol;

int succesor(int k)
{
    if (st[k] < n)
    {
        st[k]++;
        return 1;
    }
    return 0;
}

int valid(int k){
    for(int i = 1; i < k; i++){
        if (st[i] == st[k] || abs(st[k] - st[i]) == abs(k - 1)) {
            return 0;
        }
    }
    return 1;
}


void show(){
    cout<<"solutie "<<sol<<" "<<endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (st[i] == j) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
   
}

void back()
{
    int k = 1, as, isValid;
    st[k] = 0;
    while (k > 0)
    {
        as = 1;
        isValid = 0;
        while (as && !isValid)
        {
            as = succesor(k);
            if (as)
                isValid = valid(k);
        }

        if(!as)k--;
        else if(k == n){
            sol++; show();
           
        }else{
            k++;
            st[k] = 0;
        }
    }
}

int main()
{
    cout<<"enter the number: ";
    cin>>n;
    back();
    cout<<"number of sol "<< sol;
    
}