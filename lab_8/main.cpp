#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using str = string;  

struct EnergyDrink {
    int id;                 
    str name;              
    str flavor;            
    double rating;         
    int similarId;         
    double price;          
    EnergyDrink* next;     
};

// Функция создания нового напитка
EnergyDrink* MAKE(int id, str name, str flavor, double rating, int similarId, double price) {
    
    EnergyDrink* p = new EnergyDrink;

    p->id = id;
    p->name = name;
    p->flavor = flavor;
    p->rating = rating;
    p->similarId = similarId;
    p->price = price;
    p->next = nullptr;

    return p;  
}

// Функция добавления напитка в КОНЕЦ списка
void ADD(EnergyDrink* head, int id, str name, str flavor, double rating, int similarId, double price) {
    
    EnergyDrink* p = MAKE(id, name, flavor, rating, similarId, price);
    EnergyDrink* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = p;
    cout << "Напиток '" << name << "' добавлен с ID: " << id << endl;
}

// Функция вывода всех напитков
void PRINT(EnergyDrink* head) {
    EnergyDrink* p = head->next;
    if (p == nullptr) {
        cout << "Каталог пуст!" << endl;
        return;
    }
    cout << "=== КАТАЛОГ ЭНЕРГЕТИЧЕСКИХ НАПИТКОВ ===" << endl;
    while (p != nullptr) {
        cout << "Напиток:" << endl;
        cout << "ID - " << p->id << endl;
        cout << "Название - " << p->name << endl;
        cout << "Вкус - " << p->flavor << endl;
        cout << "Оценка - " << p->rating << "/5.0" << endl;
        if (p->similarId == -1) {
            cout << "Похожий напиток (ID) - нет" << endl;
        }
        else {
            cout << "Похожий напиток (ID) - " << p->similarId << endl;
        }
        cout << "Цена - " << p->price << " руб." << endl;
        cout << "------------------------" << endl;
        p = p->next;
    }
}

// Функция вывода конкретного напитка по его ID
void PRINT_ELEMENT(EnergyDrink* head, int id) {
    EnergyDrink* p = head->next;
    while (p != nullptr) {
        if (p->id == id) {
            cout << "=== ДЕТАЛЬНАЯ ИНФОРМАЦИЯ ===" << endl;
            cout << "ID - " << p->id << endl;
            cout << "Название - " << p->name << endl;
            cout << "Вкус - " << p->flavor << endl;
            cout << "Оценка - " << p->rating << "/5.0" << endl;

            if (p->similarId == -1) {
                cout << "Похожий напиток (ID) - нет" << endl;
            }
            else {
                cout << "Похожий напиток (ID) - " << p->similarId << endl;
            }

            cout << "Цена - " << p->price << " руб." << endl;
            return;
        }
        p = p->next; 
    }
    cout << "Напиток с ID " << id << " не найден!" << endl;
}

// Функция создания нового напитка (интерактивный ввод)
void CREATE_NEW(EnergyDrink* head) {
    
    EnergyDrink* p = head->next;
    int maxId = 0;
    while (p != nullptr) {
        if (p->id > maxId) {
            maxId = p->id;
        }
        p = p->next;
    }
    int newId = maxId + 1;
    str name, flavor;
    double rating, price;
    int similarId;

    cout << "=== СОЗДАНИЕ НОВОГО НАПИТКА ===" << endl;
    cout << "Автоматически присвоен ID: " << newId << endl;

    cout << "Введите название: ";
    cin >> name;  

    cout << "Введите вкус: ";
    cin >> flavor;

    cout << "Введите оценку (0.0-5.0): ";
    cin >> rating;

    cout << "Введите ID похожего напитка (-1 если нет): ";
    cin >> similarId;

    cout << "Введите цену: ";
    cin >> price;

    ADD(head, newId, name, flavor, rating, similarId, price);
}

// Функция 1: Сортировка каталога по стоимости (по возрастанию)
void SORT_BY_PRICE(EnergyDrink* head) {
    
    if (head->next == nullptr || head->next->next == nullptr) {
        cout << "Недостаточно элементов для сортировки!" << endl;
        return;
    }
    bool swapped;
    do {
        swapped = false;
        EnergyDrink* prev = head;          
        EnergyDrink* curr = head->next;   
        EnergyDrink* next = curr->next;    
        while (next != nullptr) {
            if (curr->price > next->price) {
                curr->next = next->next;
                next->next = curr;
                prev->next = next;
                swapped = true; 
            }
            prev = curr;
            curr = next;
            next = next->next;
        }
    } while (swapped);  

    cout << "Каталог отсортирован по возрастанию цены!" << endl;
}

// Функция 2: Вывод уникальных вкусов (тех, которые никому не похожи)
void PRINT_UNIQUE_FLAVORS(EnergyDrink* head) {
    vector<str> uniqueFlavors;
    vector<str> similarFlavors;
    EnergyDrink* p = head->next;
    while (p != nullptr) {
        if (p->similarId != -1) {
            EnergyDrink* temp = head->next;
            while (temp != nullptr) {
                if (temp->id == p->similarId) {
                    similarFlavors.push_back(temp->flavor);
                    break;
                }
                temp = temp->next;
            }
        }
        p = p->next;
    }
    p = head->next;
    while (p != nullptr) {
        bool isSimilar = false;
        for (size_t i = 0; i < similarFlavors.size(); i++) {
            if (similarFlavors[i] == p->flavor) {
                isSimilar = true;
                break;
            }
        }
        if (!isSimilar) {
            bool alreadyAdded = false;
            for (size_t j = 0; j < uniqueFlavors.size(); j++) {
                if (uniqueFlavors[j] == p->flavor) {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded) {
                uniqueFlavors.push_back(p->flavor);
            }
        }
        p = p->next;
    }
    cout << "=== УНИКАЛЬНЫЕ ВКУСЫ (похожих нет) ===" << endl;
    if (uniqueFlavors.empty()) {
        cout << "Уникальных вкусов не найдено!" << endl;
    }
    else {
        for (size_t i = 0; i < uniqueFlavors.size(); i++) {
            cout << i + 1 << ". " << uniqueFlavors[i] << endl;
        }
    }
}

// Функция 3: Вывод напитков по вкусам с указанием переходов к похожим
void PRINT_BY_FLAVORS(EnergyDrink* head) {
    
    vector<EnergyDrink*> allDrinks;
    EnergyDrink* p = head->next;
    while (p != nullptr) {
        allDrinks.push_back(p);
        p = p->next;
    }
    vector<str> flavors;
    for (size_t i = 0; i < allDrinks.size(); i++) {
        EnergyDrink* drink = allDrinks[i];
        bool found = false;
        for (size_t j = 0; j < flavors.size(); j++) {
            if (flavors[j] == drink->flavor) {
                found = true;
                break;
            }
        }
        if (!found) {
            flavors.push_back(drink->flavor);
        }
    }
    cout << "=== ВЫВОД ПО ВКУСАМ С ПЕРЕХОДАМИ ===" << endl;
    for (size_t k = 0; k < flavors.size(); k++) {
        str flavor = flavors[k];
        cout << "--- Вкус: " << flavor << " ---" << endl;
        vector<EnergyDrink*> flavorDrinks;
        for (size_t i = 0; i < allDrinks.size(); i++) {
            EnergyDrink* drink = allDrinks[i];
            if (drink->flavor == flavor) {
                flavorDrinks.push_back(drink);
            }
        }
        for (size_t i = 0; i < flavorDrinks.size(); i++) {
            cout << flavorDrinks[i]->name << " [ID:" << flavorDrinks[i]->id;
            if (flavorDrinks[i]->similarId != -1) {
                for (size_t j = 0; j < allDrinks.size(); j++) {
                    EnergyDrink* drink = allDrinks[j];
                    if (drink->id == flavorDrinks[i]->similarId) {
                        cout << " -> " << drink->name;
                        break;
                    }
                }
            }
            cout << "]"; 
            if (i < flavorDrinks.size() - 1) {
                cout << " | ";
            }
        }
        cout << endl;  
    }
}
// Функция очистки памяти (удаление всех элементов списка)
void CLEAR(EnergyDrink* head) {
    EnergyDrink* p = head->next;
    while (p != nullptr) {
        EnergyDrink* temp = p;  
        p = p->next;           
        delete temp;           
    }
    head->next = nullptr;
}
int main() {
    setlocale(LC_ALL, "Russian");
    EnergyDrink head;
    head.next = nullptr;

    cout << "Заполняем каталог начальными данными..." << endl;
    ADD(&head, 1, "Red Bull", "Классический", 4.2, 2, 150.0);
    ADD(&head, 2, "Burn", "Классический", 3.8, 1, 120.0);
    ADD(&head, 3, "Adrenaline Rush", "Цитрусовый", 4.0, -1, 140.0);
    ADD(&head, 4, "Monster", "Ягодный микс", 4.5, -1, 180.0);
    ADD(&head, 5, "Gorilla", "Тропический", 3.9, -1, 130.0);
    ADD(&head, 6, "Flash", "Лимонный", 4.1, -1, 110.0);
    ADD(&head, 7, "Bullet", "Кола", 3.7, -1, 125.0);

    int choice;
    do {
        cout << "=== МЕНЮ КАТАЛОГА ЭНЕРГЕТИЧЕСКИХ НАПИТКОВ ===" << endl;
        cout << "1. Просмотр всех напитков" << endl;
        cout << "2. Просмотр конкретного напитка (по ID)" << endl;
        cout << "3. Создание нового напитка" << endl;
        cout << "4. Сортировка каталога по стоимости" << endl;
        cout << "5. Вывод уникальных вкусов (похожих нет)" << endl;
        cout << "6. Вывод по вкусам с переходами" << endl;
        cout << "0. Выход из программы" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Выход из программы..." << endl;
            break;

        case 1:
            PRINT(&head);  
            break;

        case 2: {
            int id;
            cout << "Введите ID напитка для просмотра: ";
            cin >> id;
            PRINT_ELEMENT(&head, id);  
            break;
        }

        case 3:
            CREATE_NEW(&head);  
            break;

        case 4:
            SORT_BY_PRICE(&head);  
            PRINT(&head);          
            break;

        case 5:
            PRINT_UNIQUE_FLAVORS(&head);  
            break;

        case 6:
            PRINT_BY_FLAVORS(&head); 
            break;

        default:
            cout << "Неверный выбор! Пожалуйста, выберите от 0 до 6." << endl;
        }
    } while (choice != 0); 

    CLEAR(&head);
    cout << "Память очищена. Программа завершена!" << endl;

    return 0; 
}