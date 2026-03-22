#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QFile>
#include <QTextStream>

class Person
{
private:
    // Приватные поля класса (скрыты от внешнего доступа)
    QString surname;      // фамилия
    QString name;         // имя
    QString patronymic;   // отчество
    QString phone;        // телефон
    QString gender;       // пол
    bool russian;         // русский язык
    bool english;         // английский язык
    bool french;          // французский язык

public:
    // Конструктор для заполнения всех полей
    Person(QString s, QString n, QString p, QString ph, QString g, bool rus, bool eng, bool fr);

    // Деструктор
    ~Person();

    // Метод записи в файл
    void saveToFile();

    // Геттеры (методы для получения значений)
    QString getSurname() const { return surname; }
    QString getName() const { return name; }
    QString getPatronymic() const { return patronymic; }
    QString getPhone() const { return phone; }
    QString getGender() const { return gender; }
    bool hasRussian() const { return russian; }
    bool hasEnglish() const { return english; }
    bool hasFrench() const { return french; }
};

#endif // PERSON_H
