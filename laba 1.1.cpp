#include <iostream>
#include <cmath>

int main()
{
    int x; // 4 байта
    // выбираем int, потому что x число целое

    std::cout << "x: " << std::endl;
    std::cin >> x; // ввод x с клавиатуры

    float x_rec = 1 / (float)x; // находим обратное числу x, 4 байта, 6-7 значащих чисел
    // выбираем fload, потому что значение 1/x получится число дробное с плавающей точкой

    int x_2 = std::pow(x, 2);  // возведение x в 2 степень
    // выбираем int, потому что значение x_2 получится число целое

    int x_5 = std::pow(x, 5); // возведение x в 5 степень
    // выбираем int, потому что значение x_5 получится число целое

    // вывод результатов 
    std::cout << "x_rec(float) " << x_rec << std::endl;
    std::cout << "x_2(int) " << x_2 << std::endl;
    std::cout << "x_5(int) " << x_5 << std::endl;

    std::cout << "int: занимает " << sizeof(int) * 8 << " бит, мин. значение = " << std::numeric_limits<int>::lowest() <<
        " макс. значение = " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "float: занимает " << sizeof(float) * 8 << " бит, мин. значение = "
        << std::numeric_limits<float>::lowest() << " макс. значение = " << std::numeric_limits<float>::max() << std::endl;
}


