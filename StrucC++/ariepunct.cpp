#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct punct {
    float x, y;
};

int main() {
    int AB, BC, AC, p;
    float Aria; // Change the type to float or double
    punct a, b, c;
    cout << "care este valoarea lui a.x ";
    cin >> a.x;
    cout << "care este valoarea lui a.y ";
    cin >> a.y;

    cout << "care este valoarea lui b.x ";
    cin >> b.x;
    cout << "care este valoarea lui b.y ";
    cin >> b.y;

    cout << "care este valoarea lui b.x ";
    cin >> c.x;
    cout << "care este valoarea lui b.y ";
    cin >> c.y;

    AB = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    BC = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
    AC = sqrt(pow(c.x - a.x, 2) + pow(c.y - a.y, 2));
    p = (AB + BC + AC) / 2;
    Aria = sqrt(p * (p - AB) * (p - BC) * (p - AC));

    cout << AB << endl;
    cout << BC << endl;
    cout << AC << endl;
    cout << p << endl;
    cout << "Aria este " << Aria << endl;

    return 0;
}
