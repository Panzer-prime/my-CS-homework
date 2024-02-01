#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct drept {
    float L, l;
};

int main() {
    float Aria,d, p, AriaY, dy,py;
    drept x,y;
    cout << "care este lugimea  ";
    cin >> x.L;
    cout << "care este valoarea lui latimea ";
    cin >> x.l;
    cout << "care este lugimea  ";
    cin >> y.L;
    cout << "care este valoarea lui latimea ";
    cin >> y.l;

    Aria = x.L*x.l;
    p = 2*x.L+2*x.l;
    d = sqrt(pow(x.L,2) + pow(x.l,2));

    AriaY = y.L*y.l;
    py = 2*y.L+2*y.l;
    dy = sqrt(pow(y.L,2) + pow(y.l,2));

    if(x.L ==x.l) cout<<"Drepunghiul x este patrat \n";
    if(Aria == AriaY) cout<<"Ariile sunt egale \n";
    if(p ==py) cout<<"perimetrele sunt egale ";

    cout<<"\naria x "<<Aria;
    cout<<"\nAria y "<<AriaY;
    cout<<"\n perimetru x "<<p;
    cout<<"\n perimetru y "<<py;
    cout<<"\n diagonala  x "<<d;
    cout<<"\n diagonala  y "<<dy;

    return 0;
}
