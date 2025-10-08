#include <iostream>

using namespace std;
int main() {

    // Задание 1 

    cout << "Enter N: ";
    int n;
    cin >> n;

    int numcnt = 1;
    int sum = 0;
    int min = 100000000;
    int minnumcnt = 0;

    if (n <= 0) {
        cout << "Error" << endl;
    }
    int first;
    cout << "Enter the 1: ";
    cin >> first;

    for (int i = 2; i <= n; ++i) {
        ++numcnt;
        cout << "Enter the " << numcnt << ": ";
        int num;
        cin >> num;
        if (num > first) {
            sum = sum + num;
            if (num < min) {
                min = num;
                minnumcnt = numcnt;

            }

        }

    }
    if (sum != 0) {
        cout << "The sum of the number: " << sum << endl;
        cout << "The lowest number: " << min << endl;
        cout << "His sequence number: " << minnumcnt << endl;
        cout << "The end" << endl;
    }
    else {
        cout << "There are suitable numbers" << endl;
        cout << "The end" << endl;
    }

    // Задание 2
    short x;
    int sm = 0;
    int mn = 9;
    int mx = 0;
    int p = 0;

    cout << "Enter the number:";
    cin >> x;

    short x1;
    x1 = abs(x);
    if (x1 > 1000)
        cout << "Error" << endl;
    else {
        while (x1 > 0) {
            p = x1 % 10;
            x1 /= 10;

            if (p > mx)
                mx = p;
            if (p < mn)
                mn = p;
            sm = mn + mx;
        }
    }
    cout << "The sum min and max: " << sm << endl;
    cout << "The end" << endl;
}
