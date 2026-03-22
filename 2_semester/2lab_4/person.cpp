#include "person.h"

// Конструктор заполнения
Person::Person(QString s, QString n, QString p, QString ph, QString g, bool rus, bool eng, bool fr)
{
    surname = s;
    name = n;
    patronymic = p;
    phone = ph;
    gender = g;
    russian = rus;
    english = eng;
    french = fr;
}

// Деструктор
Person::~Person()
{
    // Деструктор пустой, так как нет динамической памяти
}

// Метод записи в файл
void Person::saveToFile()
{
    QFile file("result.txt");

    // Открываем файл для добавления (Append) или создаем новый
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);

        out << "=== Данные пользователя ===\n";
        out << "Фамилия: " << surname << "\n";
        out << "Имя: " << name << "\n";
        out << "Отчество: " << (patronymic.isEmpty() ? "—" : patronymic) << "\n";
        out << "Телефон: " << phone << "\n";
        out << "Пол: " << gender << "\n";
        out << "Языки: ";

        if (russian) out << "Русский ";
        if (english) out << "Английский ";
        if (french) out << "Французский ";

        out << "\n========================\n\n";

        file.close();
    }
}
