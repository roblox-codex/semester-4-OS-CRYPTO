#include <iostream>

using namespace std;

int extendedEuclidean (int a, int b, int &s, int &t) {
    if (b == 0) {
        s = 0;
        t = 1;
        return a;
    }
    else {
        int gcd = extendedEuclidean (b, a % b, s, t);
        int s1 = t;
        int t1 = s - (a / b) * t;
        s = s1;
        t = t1;
        return gcd;
    }
}
int additiveModuloInverse (int a, int m) {
    int s, t;
    int gcd = extendedEuclidean (a, m, s, t);
    if (gcd != 1) {
        return -1;
    }
    else {
        return (s + m) % m;
    }
}
int main () {
    int a, m;
    cout << "Enter a and m: ";
    cin >> a >> m;
    int inverse = additiveModuloInverse (a, m);
    if (inverse == -1) {
        cout << "No additive modulo inverse exists" << endl;
    }
    else {
        cout << "Additive modulo inverse: " << inverse << endl;
    }
}