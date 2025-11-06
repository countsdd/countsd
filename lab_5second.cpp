#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

// Функция для двух чисел:
float secondaryFunction(int n1, int n2) {
    cout << "The function of average value of two numbers" << endl;
    float avg = 0;
    avg = (n1 + n2) / 2.f;
    return avg;
}
// Функция для трех чисел:
float secondaryFunction(int n1, int n2, int n3) {
    cout << "The function of average value of tree numbers" << endl;
    float avg = 0;
    avg = (n1 + n2 + n3) / 3.f;
    return avg;
}

float mainFunction(int x[3]) {
    vector<int>vec;
    for (int i = 0; i < 3; ++i) {
        if (x[i] != 0) {
            vec.push_back(x[i]);
        }
    }
    if (vec.size() == 2) {
        return secondaryFunction(vec[0], vec[1]);
    }
    else if (vec.size() == 3) {
        return secondaryFunction(vec[0], vec[1], vec[2]);
    }
    else {
        cout << "Error" << endl;
        return 0;
    }
}

void task1() {
    int x[3];
    for (int i = 0; i != 3; i++) {
        cout << "Enter number" << i + 1 <<": ";
        cin >> x[i];
    }
    cout << mainFunction(x) << endl;
}

void task2(int x) {
    float x_rec = 1 / (float)x;
    int x_2 = x * x;
    int x_5 = pow(x, 5);
    cout << "x_rec(float) " << x_rec << endl;
    cout << "x_2(int) " << x_2 << endl;
    cout << "x_5(int) " << x_5 << endl;

    cout << "int: takes up " << sizeof(int) * 8 << " bit, min. value = " << numeric_limits<int>::lowest() <<
        " max. takes up = " << numeric_limits<int>::max() << endl;
    cout << "float: takes up " << sizeof(float) * 8 << " bit, min. value = "
        << numeric_limits<float>::lowest() << " max. value = " << numeric_limits<float>::max() << endl;
}
int main() {

    bool flag;
    cout << "Enter the task (task 1 - 0, task 2 - 1)" << endl;
    cin >> flag;

    if (flag == 0) {
        task1();
    }
    else {
        int x;
        cout << "x:" << endl;
        cin >> x;
        task2(x);

    }
    return 0;

}
