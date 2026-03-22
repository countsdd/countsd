#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Устанавливаем валидаторы для полей ввода
    QRegularExpression surnameRegex("^[А-ЯA-Z][а-яa-z]*$");
    ui->lineEdit_surname->setValidator(new QRegularExpressionValidator(surnameRegex, this));

    QRegularExpression nameRegex("^[А-Я][а-я]*$");
    ui->lineEdit_name->setValidator(new QRegularExpressionValidator(nameRegex, this));

    // Отчество - полное, без ограничения длины
    QRegularExpression patronymicRegex("^[А-Я][а-я]*$|^$");
    ui->lineEdit_patronymic->setValidator(new QRegularExpressionValidator(patronymicRegex, this));

    // ИСПРАВЛЕНО: Телефон - "+" и 10 цифр (любой код)
    QRegularExpression phoneRegex("^\\+[0-9]{10}$");
    ui->lineEdit_phone->setValidator(new QRegularExpressionValidator(phoneRegex, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Проверка фамилии (русские/английские буквы, первая заглавная)
bool MainWindow::checkSurname(const QString& text)
{
    QRegularExpression regex("^[А-ЯA-Z][а-яa-z]*$");
    return regex.match(text).hasMatch();
}

// Проверка имени (только русские буквы, первая заглавная)
bool MainWindow::checkName(const QString& text)
{
    QRegularExpression regex("^[А-Я][а-я]+$");
    return regex.match(text).hasMatch();
}

// Проверка отчества (первая заглавная, потом любые русские буквы, может быть пустым)
bool MainWindow::checkPatronymic(const QString& text)
{
    if (text.isEmpty()) return true;
    QRegularExpression regex("^[А-Я][а-я]+$");
    return regex.match(text).hasMatch();
}

// ИСПРАВЛЕНО: Проверка телефона - "+" и 10 цифр
bool MainWindow::checkPhone(const QString& text)
{
    QRegularExpression regex("^\\+[0-9]{10}$");
    return regex.match(text).hasMatch();
}

// Очистка всех полей формы (для кнопки Сброс)
void MainWindow::clearForm()
{
    // Очищаем текстовые поля
    ui->lineEdit_surname->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_patronymic->clear();
    ui->lineEdit_phone->clear();

    // Сбрасываем радиокнопки (пол)
    ui->radioButton_male->setChecked(false);
    ui->radioButton_female->setChecked(false);

    // Сбрасываем чекбоксы (языки)
    ui->checkBox_russian->setChecked(false);
    ui->checkBox_english->setChecked(false);
    ui->checkBox_french->setChecked(false);
}

// Кнопка "Сохранить" - только проверяет и сохраняет (НЕ ОЧИЩАЕТ)
void MainWindow::on_pushButton_save_clicked()
{
    // Получаем данные из полей ввода
    QString surname = ui->lineEdit_surname->text();
    QString name = ui->lineEdit_name->text();
    QString patronymic = ui->lineEdit_patronymic->text();
    QString phone = ui->lineEdit_phone->text();

    // Получаем пол
    QString gender;
    if (ui->radioButton_male->isChecked())
        gender = "Мужской";
    else if (ui->radioButton_female->isChecked())
        gender = "Женский";

    // ПРОВЕРКА ОБЯЗАТЕЛЬНЫХ ПОЛЕЙ
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

    // ПРОВЕРКА НА СООТВЕТСТВИЕ РЕГУЛЯРНЫМ ВЫРАЖЕНИЯМ
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

    // ИСПРАВЛЕНО: Проверка телефона - "+" и 10 цифр
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

    // Получаем выбранные языки (необязательные поля)
    bool russian = ui->checkBox_russian->isChecked();
    bool english = ui->checkBox_english->isChecked();
    bool french = ui->checkBox_french->isChecked();

    // СОЗДАЕМ ОБЪЕКТ КЛАССА PERSON
    Person person(surname, name, patronymic, phone, gender, russian, english, french);

    // СОХРАНЯЕМ В ФАЙЛ
    person.saveToFile();

    QMessageBox::information(this, "Успех", "Данные успешно сохранены в файл result.txt!\n\n"
                                            "Данные остались в форме, вы можете их отредактировать или нажать 'Сброс' для очистки.");

    // НЕ ОЧИЩАЕМ ФОРМУ - данные остаются для возможного редактирования
}

// Кнопка "Сброс" - очищает все поля и приводит форму в начальное состояние
void MainWindow::on_pushButton_reset_clicked()
{
    clearForm();
    QMessageBox::information(this, "Сброс", "Форма очищена и приведена в начальное состояние!");
}
