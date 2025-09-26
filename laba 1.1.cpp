#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int x; // 4 байта
    // выбираем int, потому что x число целое

    cout << "Введите x: " << endl;
    cin >> x; // ввод x с клавиатуры

    float x_rec = 1 / (float)x; // находим обратное числу x, 4 байта, 6-7 значащих чисел
    // выбираем fload, потому что значение 1/x получится число дробное с плавающей точкой

    int x_2 = pow(x, 2);  // возведение x в 2 степень
    // выбираем int, потому что значение x_2 получится число целое

    int x_5 = pow(x, 5); // возведение x в 5 степень
    // выбираем int, потому что значение x_5 получится число целое

    // вывод результатов 
    cout << "x_rec(float) " << x_rec << endl;
    cout << "x_2(int) " << x_2 << endl;
    cout << "x_5(int) " << x_5 << endl;

    cout << "int: занимает " << sizeof(int) * 8 << " бит, мин. значение = " << numeric_limits<int>::lowest() <<
        " макс. значение = " << numeric_limits<int>::max() << endl;
    cout << "float: занимает " << sizeof(float) * 8 << " бит, мин. значение = "
        << numeric_limits<float>::lowest() << " макс. значение = " << numeric_limits<float>::max() << endl;
}


