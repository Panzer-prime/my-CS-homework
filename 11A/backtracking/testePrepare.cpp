#include <iostream>

using namespace std;

int st[100],m[100], n, sol;

int succesor(int k)
{
    if (st[k]< m[k])
    {
        st[k]++;
        return 1;
    }
    return 0;
}

int valid(int k)
{
    return 1;
}


void showVector()
{
    cout<<"solution nr: "<<sol<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout << st[i] << " ";
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
            {
                isValid = valid(k);
                
            }
        }

        if (!as)
            k--;
        else if (k == n)
        {
            sol++;
            showVector();
        }
        else
        {
            k++;
            st[k] = 0;
        }
    }
}

int main()
{
    cout<<"Enter an number: ";
    cin>>n; 
    for(int i = 1; i <= n; i++){
        cout<<"enter an number per position: "<<i<<" ";
        cin>>m[i];
    }
    back();
}