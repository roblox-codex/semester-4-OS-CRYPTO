#include <iostream>

using namespace std;

int main () {
    int a, m;
    cout << "Enter a and m: ";
    cin >> a >> m;
    int r1 = a, r2 = m, r;
    while (r2 > 0) {
        r = r1 % r2;
        r1 = r2;
        r2 = r;
    }
    if (r1 != 1) {
        cout << "No multiplicative inverse exists" << endl;
        return 0;
    }
    int b = (m - a) % m;
    cout << "Multiplicative inverse of " << a << " modulo " << m << " is " << b << endl;
    return 0;
}