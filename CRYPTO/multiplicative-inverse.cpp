#include <iostream>

using namespace std;
 
int main () {
    int a, b, x, y, q, r, x1, x2, y1, y2;
    cout << "Enter a and b: ";
    cin >> a >> b;
    x1 = 1;
    x2 = 0;
    y1 = 0;
    y2 = 1;
    while (b > 0) {
        q = a / b;
        r = a % b;
        x = x1 - q * x2;
        y = y1 - q * y2;
        a = b;
        b = r;
        x1 = x2;
        x2 = x;
        y1 = y2;
        y2 = y;
    }
    if (x1 >= 1) {
        cout << "Multiplicative inverse is " << x1 << endl;
    } else {
        cout << "Multiplicative inverse does not exist" << endl;
    }
    return 0;
}