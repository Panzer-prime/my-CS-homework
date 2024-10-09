#include <iostream>
#include<vector>

using namespace std;


int a;


void ab(int &a){
    
    cout<<a<<endl;
    a = 343;
}

int main()
{

    int x, a = 654;
    // float r = 4.25;
    cout<<a<<endl;
    cout<<x<<"thats the x"<<endl;
    ab(a);
    cout<<a;
}