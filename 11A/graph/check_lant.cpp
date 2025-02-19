#include<iostream>
#include<fstream>

using namespace std;

int lant[100], n, len;

struct edge{
    int x, y;
};
edge mat[20];

void read() {
    fstream file("data.txt");
    file >> n;
    int x, y;
    while (file >> x >> y) {
        mat[len].x = x;
        mat[len].y = y;
        len++;
    }
}

void write() {
    for (int i = 0; i < len; i++) {
        cout << "[ " << mat[i].x << " " << mat[i].y << " ] ";
    }
    cout << endl;
}

void read_lant(int l) {
    for (int i = 0; i < l; i++) {
        cout<<"\nelementul de pe pozitia "<<i<<" este: ";
        cin >> lant[i];
    }
}

void write_lant(int l) {
    for (int i = 0; i < l; i++) {
        cout << lant[i] << " ";
    }
    cout << endl;
}

int check(int l) {
    int found = 0;
    for (int i = 0; i < l - 1; i++) {
        found = 0;
        for (int j = 0; j < len; j++) {
            if ((mat[j].x == lant[i] && mat[j].y == lant[i + 1]) ||
                (mat[j].y == lant[i] && mat[j].x == lant[i + 1])) {
                found = 1;
                break;
            }
        }
       
    }
    return found;
}

int main() {
    read();
    cout << "lista de muchii: \n"<<len;
    write();

    int l;
    cout << "Introdu lungimea lantului: ";
    cin >> l;
    
    read_lant(l);
    cout << "Lantul este: ";
    write_lant(l);

    if (check(l)) 
        cout << "secventa valida.\n";
    else 
        cout << "secventa nu este valida.\n";

    return 0;
}
