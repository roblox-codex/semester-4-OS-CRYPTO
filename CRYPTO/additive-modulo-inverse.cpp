#include <iostream>

using namespace std;

int additiveModInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a + x * m) % m == 0) {
            return x;
        }
    }
    return -1; // additive inverse does not exist
}

int main() {
    int a, m;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter m: ";
    cin >> m;
    int result = additiveModInverse(a, m);
    if (result == -1) {
        cout << "Additive inverse does not exist\n";
    } else {
        cout << "Additive inverse of " << a << " modulo " << m << " is " << result << "\n";
    }
    return 0;
}
