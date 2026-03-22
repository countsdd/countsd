#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QFile>
#include <QTextStream>

class Person
{
private:

    QString surname;
    QString name;
    QString patronymic;
    QString phone;
    QString gender;
    bool russian;
    bool english;
    bool french;

public:

    Person(QString s, QString n, QString p, QString ph, QString g, bool rus, bool eng, bool fr);

    ~Person();

    void saveToFile();

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
