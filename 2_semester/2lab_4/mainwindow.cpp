#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegularExpression surnameRegex("^[А-ЯA-Z][а-яa-z]*$");
    ui->lineEdit_surname->setValidator(new QRegularExpressionValidator(surnameRegex, this));

    QRegularExpression nameRegex("^[А-Я][а-я]*$");
    ui->lineEdit_name->setValidator(new QRegularExpressionValidator(nameRegex, this));

    QRegularExpression patronymicRegex("^[А-Я][а-я]*$|^$");
    ui->lineEdit_patronymic->setValidator(new QRegularExpressionValidator(patronymicRegex, this));

    QRegularExpression phoneRegex("^\\+[0-9]{10}$");
    ui->lineEdit_phone->setValidator(new QRegularExpressionValidator(phoneRegex, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkSurname(const QString& text)
{
    QRegularExpression regex("^[А-ЯA-Z][а-яa-z]*$");
    return regex.match(text).hasMatch();
}

bool MainWindow::checkName(const QString& text)
{
    QRegularExpression regex("^[А-Я][а-я]+$");
    return regex.match(text).hasMatch();
}

bool MainWindow::checkPatronymic(const QString& text)
{
    if (text.isEmpty()) return true;
    QRegularExpression regex("^[А-Я][а-я]+$");
    return regex.match(text).hasMatch();
}

bool MainWindow::checkPhone(const QString& text)
{
    QRegularExpression regex("^\\+[0-9]{10}$");
    return regex.match(text).hasMatch();
}

void MainWindow::clearForm()
{
    ui->lineEdit_surname->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_patronymic->clear();
    ui->lineEdit_phone->clear();

    ui->radioButton_male->setAutoExclusive(false);
    ui->radioButton_female->setAutoExclusive(false);

    ui->radioButton_male->setChecked(false);
    ui->radioButton_female->setChecked(false);

    ui->radioButton_male->setAutoExclusive(true);
    ui->radioButton_female->setAutoExclusive(true);

    ui->checkBox_russian->setChecked(false);
    ui->checkBox_english->setChecked(false);
    ui->checkBox_french->setChecked(false);
}
void MainWindow::on_pushButton_save_clicked()
{
    QString surname = ui->lineEdit_surname->text();
    QString name = ui->lineEdit_name->text();
    QString patronymic = ui->lineEdit_patronymic->text();
    QString phone = ui->lineEdit_phone->text();

    QString gender;
    if (ui->radioButton_male->isChecked())
        gender = "Мужской";
    else if (ui->radioButton_female->isChecked())
        gender = "Женский";

    if (surname.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Поле 'Фамилия' обязательно для заполнения!");
        ui->lineEdit_surname->setFocus();
        return;
    }

    if (name.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Поле 'Имя' обязательно для заполнения!");
        ui->lineEdit_name->setFocus();
        return;
    }

    if (phone.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Поле 'Телефон' обязательно для заполнения!");
        ui->lineEdit_phone->setFocus();
        return;
    }

    if (gender.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Выберите пол!");
        return;
    }

    if (!checkSurname(surname))
    {
        QMessageBox::warning(this, "Ошибка в поле 'Фамилия'",
                             "Фамилия должна содержать только буквы и начинаться с заглавной!\n"
                             "Пример: Иванов или Ivanov");
        ui->lineEdit_surname->setFocus();
        ui->lineEdit_surname->selectAll();
        return;
    }

    if (!checkName(name))
    {
        QMessageBox::warning(this, "Ошибка в поле 'Имя'",
                             "Имя должно содержать только русские буквы и начинаться с заглавной!\n"
                             "Пример: Иван");
        ui->lineEdit_name->setFocus();
        ui->lineEdit_name->selectAll();
        return;
    }

    if (!checkPatronymic(patronymic))
    {
        QMessageBox::warning(this, "Ошибка в поле 'Отчество'",
                             "Отчество должно начинаться с заглавной буквы и содержать только русские буквы!\n"
                             "Пример: Иванович\n"
                             "Или оставьте поле пустым");
        ui->lineEdit_patronymic->setFocus();
        ui->lineEdit_patronymic->selectAll();
        return;
    }

    if (!checkPhone(phone))
    {
        QMessageBox::warning(this, "Ошибка в поле 'Телефон'",
                             "Телефон должен быть в формате:\n"
                             "+XXXXXXXXXXX (знак + и 10 цифр)\n"
                             "Пример: +71234567890");
        ui->lineEdit_phone->setFocus();
        ui->lineEdit_phone->selectAll();
        return;
    }

    bool russian = ui->checkBox_russian->isChecked();
    bool english = ui->checkBox_english->isChecked();
    bool french = ui->checkBox_french->isChecked();

    Person person(surname, name, patronymic, phone, gender, russian, english, french);

    person.saveToFile();

    QMessageBox::information(this, "Успех", "Данные успешно сохранены в файл result.txt!\n\n"
                                            "Данные остались в форме, вы можете их отредактировать или нажать 'Сброс' для очистки.");

}

void MainWindow::on_pushButton_reset_clicked()
{
    clearForm();
    QMessageBox::information(this, "Сброс", "Форма очищена и приведена в начальное состояние!");
}
