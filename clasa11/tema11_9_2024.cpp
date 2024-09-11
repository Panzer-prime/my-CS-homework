#include <iostream>

using namespace std;

float medieAritmetica(int a, int b)
{
    return (a + b) / 2;
}

float medieGeometrica(int a, int b)
{
    return (a * b) / 2;
}

void medie(int b, int a, float &ma, float &mb)
{
    cout << "add an number: ";
    cin >> a;
    cout << "add an second number: ";
    cin >> b;
    ma = medieAritmetica(a, b);
    mb = medieGeometrica(a, b);

    cout << ma << " " << mb;
}
int main()
{
    int a, b;
    float ma, mb;
    medie(a, b, ma, mb);
}
