#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

float secondaryFunction(int n1, int n2) {
    cout << "The function of average value of two numbers" << endl;
    float avg = 0;
    avg = (n1 + n2) / 2.f;
    return avg;
}
float secondaryFunction(int n1, int n2, int n3) {
    cout << "The function of average value of tree numbers" << endl;
    float avg = 0;
    avg = (n1 + n2 + n3) / 3.f;
    return avg;
}
float mainFunction(int num1, int num2, int num3) {
    vector <int>nonZeroNumbers;
    if (num1 != 0) {
        nonZeroNumbers.push_back(num1);
    }
    if (num2 != 0) {
        nonZeroNumbers.push_back(num2);
    }
    if (num3 != 0) {
        nonZeroNumbers.push_back(num3);
    }
    if (nonZeroNumbers.size() == 2) {
        return secondaryFunction(nonZeroNumbers[0], nonZeroNumbers[1]);
    }
    else if (nonZeroNumbers.size() == 3) {
        return secondaryFunction(nonZeroNumbers[0], nonZeroNumbers[1], nonZeroNumbers[2]);
    }
    else {
        cout << "Incorrect number input" << endl;
        return 0;
    }
}
void task1() {
    int a, b, c;
    cout << "Enter tree numbers: ";
    cin >> a >> b >> c;
    cout << mainFunction(a, b, c) << endl;
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
