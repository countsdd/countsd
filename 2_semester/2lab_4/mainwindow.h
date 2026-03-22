#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QMessageBox>
#include "person.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_save_clicked();   // кнопка Сохранить
    void on_pushButton_reset_clicked();  // кнопка Сброс

private:
    Ui::MainWindow *ui;

    // Методы для проверки полей
    bool checkSurname(const QString& text);
    bool checkName(const QString& text);
    bool checkPatronymic(const QString& text);
    bool checkPhone(const QString& text);

    // Метод очистки формы
    void clearForm();
};

#endif // MAINWINDOW_H
