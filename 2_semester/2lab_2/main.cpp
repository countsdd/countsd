#include <iostream>
#include <vector>
#include <string>
#include "Clock.h"

using namespace std;

int main() {
    vector<string> tasks1, tasks2;
    tasks1.push_back("сходить в кино");
    tasks1.push_back("купить продукты");
    tasks1.push_back("позвонить маме");
    
    tasks2.push_back("купить продукты");
    tasks2.push_back("сделать домашнее задание");
    tasks2.push_back("пойти в спортзал");
    
    Clock clock1(27, 12, 2005, 12, 0, "Вторник", tasks1);
    Clock clock2(5, 6, 2003, 10, 0, "Четверг", tasks2);
    
    cout << "Исходные часы:" << endl;
    clock1.print_info();
    clock2.print_info();
    
    Clock result_plus = clock1 + clock2;
    cout << "Результат оператора + (последняя дата + неделя и 1 час, все дела без повторов):" << endl;
    result_plus.print_info();
    
    Clock result_divide = clock1 / clock2;
    cout << "Результат оператора / (первая дата + 3 дня, рандомные дела без повторов):" << endl;
    result_divide.print_info();
    
    Clock clock4;
    cout << "Демонстрация оператора присваивания:" << endl;
    clock4 = clock1;
    clock4.print_info();
    
    Clock clock3;
    int n;
    
    do {
        cout << "=============" << endl;
        cout << "Меню:" << endl; 
        cout << "1. Получить день" << endl;
        cout << "2. Получить месяц" << endl; 
        cout << "3. Получить год" << endl; 
        cout << "4. Получить часы" << endl; 
        cout << "5. Получить минуты" << endl; 
        cout << "6. Получить день недели" << endl; 
        cout << "7. Получить список дел" << endl;
        cout << "8. Установить день недели" << endl; 
        cout << "9. Добавить минуты" << endl;
        cout << "10. Вывести информацию" << endl;
        cout << "11. Установить месяц" << endl; 
        cout << "12. Установить день" << endl; 
        cout << "13. Установить часы" << endl; 
        cout << "14. Установить минуты" << endl;
        cout << "15. Установить год" << endl;
        cout << "16. Установить список дел" << endl;
        cout << "17. Демонстрация оператора +" << endl;
        cout << "18. Демонстрация оператора /" << endl;
        cout << "0. Выход" << endl;
        cout << "=============" << endl;
        cout << "Что вы хотите сделать?" << endl;
        cin >> n;
        
        int num;
        string task;
        vector<string> tasks;
        
        switch (n) {
        case 1:
            cout << "День: " << clock3.get_day() << endl;
            break;
            
        case 2:
            cout << "Месяц: " << clock3.get_month() << endl;
            break;
            
        case 3:
            cout << "Год: " << clock3.get_year() << endl;
            break;
            
        case 4:
            cout << "Часы: " << clock3.get_hours() << endl;
            break;
            
        case 5:
            cout << "Минуты: " << clock3.get_mins() << endl;
            break;
            
        case 6:
            cout << "День недели: " << clock3.get_day_of_week() << endl;
            break;
            
        case 7:
            cout << "Список дел: ";
            tasks = clock3.get_tasks();
            if (tasks.empty()) {
                cout << "нет дел";
            } else {
                for (int i = 0; i < tasks.size(); i++) {
                    cout << "\"" << tasks[i] << "\"";
                    if (i < tasks.size() - 1) cout << ", ";
                }
            }
            cout << endl;
            break;
            
        case 8:
            cout << "=============" << endl;
            cout << "1. Понедельник" << endl;
            cout << "2. Вторник" << endl;
            cout << "3. Среда" << endl; 
            cout << "4. Четверг" << endl; 
            cout << "5. Пятница" << endl;
            cout << "6. Суббота" << endl;
            cout << "7. Воскресенье" << endl;
            cout << "=============" << endl;
            cout << "Введите номер дня недели:" << endl;
            cin >> num;
            if ((num < 1) || (num > 7)) {
                cout << "Неверный номер дня недели" << endl;
            }
            else {
                clock3.set_day_of_week(num);
            }
            break;
            
        case 9:
            cout << "Введите минуты для добавления: " << endl;
            cin >> num;
            try {
                clock3.add_min(num);
            }
            catch (string error) {
                cerr << error << endl;
            }
            break;
            
        case 10:
            clock3.print_info();
            break;
            
        case 11:
            cout << "Введите месяц (номер): " << endl;
            cin >> num;
            try {
                clock3.set_month(num);
            }
            catch (string error) {
                cerr << error << endl;
            }
            break;
            
        case 12:
            cout << "Введите день: " << endl; 
            cin >> num;
            try {
                clock3.set_day(num);
            }
            catch (string error) {
                cerr << error << endl;
            }
            break;
            
        case 13:
            cout << "Введите часы: " << endl;
            cin >> num;
            try {
                clock3.set_hours(num);
            }
            catch (string error) {
                cerr << error << endl;
            }
            break;
            
        case 14:
            cout << "Введите минуты: " << endl; 
            cin >> num;
            try {
                clock3.set_minutes(num);
            }
            catch (string error) {
                cerr << error << endl;
            }
            break;
            
        case 15:
            cout << "Введите год: " << endl;
            cin >> num;
            clock3.set_year(num);
            break;
            
        case 16:
            tasks.clear();
            cout << "Введите дела (для завершения введите 'stop'):" << endl;
            cout << "Примеры: сходить в кино, купить продукты, позвонить маме" << endl;
            cin.ignore();
            while (true) {
                cout << "Дело: ";
                getline(cin, task);
                if (task == "stop") break;
                if (task != "") {
                    tasks.push_back(task);
                }
            }
            clock3.set_tasks(tasks);
            break;
            
        case 17: {
            Clock temp1, temp2;
            cout << "Создадим два объекта для демонстрации оператора +" << endl;
            
            cout << "Введите данные для первого объекта:" << endl;
            cout << "День: "; cin >> num; temp1.set_day(num);
            cout << "Месяц: "; cin >> num; temp1.set_month(num);
            cout << "Год: "; cin >> num; temp1.set_year(num);
            cout << "Часы: "; cin >> num; temp1.set_hours(num);
            cout << "Минуты: "; cin >> num; temp1.set_minutes(num);
            temp1.set_day_of_week(1);
            
            tasks.clear();
            cout << "Введите дела для первого объекта (для завершения введите 'stop'):" << endl;
            cout << "Примеры: сходить в кино, купить продукты, позвонить маме" << endl;
            cin.ignore();
            while (true) {
                cout << "Дело: ";
                getline(cin, task);
                if (task == "stop") break;
                if (task != "") {
                    tasks.push_back(task);
                }
            }
            temp1.set_tasks(tasks);
            
            cout << "Введите данные для второго объекта:" << endl;
            cout << "День: "; cin >> num; temp2.set_day(num);
            cout << "Месяц: "; cin >> num; temp2.set_month(num);
            cout << "Год: "; cin >> num; temp2.set_year(num);
            cout << "Часы: "; cin >> num; temp2.set_hours(num);
            cout << "Минуты: "; cin >> num; temp2.set_minutes(num);
            temp2.set_day_of_week(1);
            
            tasks.clear();
            cout << "Введите дела для второго объекта (для завершения введите 'stop'):" << endl;
            cout << "Примеры: сходить в кино, купить продукты, позвонить маме" << endl;
            cin.ignore();
            while (true) {
                cout << "Дело: ";
                getline(cin, task);
                if (task == "stop") break;
                if (task != "") {
                    tasks.push_back(task);
                }
            }
            temp2.set_tasks(tasks);
            
            Clock temp_result = temp1 + temp2;
            cout << "Результат оператора +:" << endl;
            temp_result.print_info();
            break;
        }
        
        case 18: {
            Clock temp1, temp2;
            cout << "Создадим два объекта для демонстрации оператора /" << endl;
            
            cout << "Введите данные для первого объекта:" << endl;
            cout << "День: "; cin >> num; temp1.set_day(num);
            cout << "Месяц: "; cin >> num; temp1.set_month(num);
            cout << "Год: "; cin >> num; temp1.set_year(num);
            cout << "Часы: "; cin >> num; temp1.set_hours(num);
            cout << "Минуты: "; cin >> num; temp1.set_minutes(num);
            temp1.set_day_of_week(1);
            
            tasks.clear();
            cout << "Введите дела для первого объекта (для завершения введите 'stop'):" << endl;
            cout << "Примеры: сходить в кино, купить продукты, позвонить маме" << endl;
            cin.ignore();
            while (true) {
                cout << "Дело: ";
                getline(cin, task);
                if (task == "stop") break;
                if (task != "") {
                    tasks.push_back(task);
                }
            }
            temp1.set_tasks(tasks);
            
            cout << "Введите данные для второго объекта:" << endl;
            cout << "День: "; cin >> num; temp2.set_day(num);
            cout << "Месяц: "; cin >> num; temp2.set_month(num);
            cout << "Год: "; cin >> num; temp2.set_year(num);
            cout << "Часы: "; cin >> num; temp2.set_hours(num);
            cout << "Минуты: "; cin >> num; temp2.set_minutes(num);
            temp2.set_day_of_week(1);
            
            tasks.clear();
            cout << "Введите дела для второго объекта (для завершения введите 'stop'):" << endl;
            cout << "Примеры: сходить в кино, купить продукты, позвонить маме" << endl;
            cin.ignore();
            while (true) {
                cout << "Дело: ";
                getline(cin, task);
                if (task == "stop") break;
                if (task != "") {
                    tasks.push_back(task);
                }
            }
            temp2.set_tasks(tasks);
            
            Clock temp_result = temp1 / temp2;
            cout << "Результат оператора /:" << endl;
            temp_result.print_info();
            break;
        }
        
        case 0:
            cout << "Выход из программы" << endl;
            break;
            
        default:
            cout << "Неверное значение" << endl;
            break;
        }
    } while (n != 0);
    
    return 0;
}