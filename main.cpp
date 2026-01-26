#include <iostream>
#include <vector>
// Поля: день, месяц, год, часы, минуты, день недели.
// Методы: геттеры на все, сеттер на день недели, вывод всей информации, добавление X минут.

using str = std::string;

class Clock {
private:
    int day_;
    int month_;
    int hours_;
    int mins_;
    str day_of_week_;
protected:
    int year_;
public:
    Clock() {
        day_ = 31;
        month_ = 12;
        year_ = 9999;
        hours_ = 23;
        mins_ = 59;
        day_of_week_ = "Воскресенье";
        std::cerr << "конструктор по умолчанию" << std::endl;
    }
    Clock(int day, int month, int year, int hours, int mins, str day_of_week) : day_(day), month_(month),
        year_(year), hours_(hours), mins_(mins), day_of_week_(day_of_week) {
        std::cerr << "параметризованный конструктор" << std::endl;
    }
    Clock(const Clock &p) : day_(p.day_), month_(p.month_),
        year_(p.year_), hours_(p.hours_), mins_(p.mins_), day_of_week_(p.day_of_week_) {
        std::cerr << "конструктор копирования" << std::endl;
    }
    ~Clock() {
        std::cerr << "деструктор" << std::endl;
    }
    void print_info() {
        std::cout << "=============" << std::endl;
        std::cout << "День: " << day_ << std::endl; 
        std::cout << "Месяц: " << month_ << std::endl;
        std::cout << "Год: " << year_ << std::endl;
        std::cout << "Часы: " << hours_ << std::endl;
        std::cout << "Минуты: " << mins_ << std::endl;
        std::cout << "День недели: " << day_of_week_ << std::endl; 
        std::cout << "=============" << std::endl;
    }
    void set_day_of_week(int day_of_week1) {
        switch (day_of_week1) {
        case 1:
            day_of_week_ = "Понедельник";
            break;
        case 2:
            day_of_week_ = "Вторник"; 
            break;
        case 3:
            day_of_week_ = "Среда";
            break;
        case 4:
            day_of_week_ = "Четверг";
            break;
        case 5:
            day_of_week_ = "Пятница"; 
            break;
        case 6:
            day_of_week_ = "Суббота";
            break;
        case 7:
            day_of_week_ = "Воскресенье";
            break;
        default:
            std::cout << "Неверное значение" << std::endl;
            break;
        }
  }
  void set_year(int num){
    year_ = num;
  }
  void set_month(int num){
    if((num  < 1) || (num >12)){
      str error = "Месяц должен быть < 13 и > 1 ";
      throw error;
    }
    month_ = num;
  }

  void set_day(int num){
    std::vector<int> days31 = {1,3,5,7,8,10,12};
    std::vector<int> days30 = {4,6,9,11};
    if (std::find(days31.begin(), days31.end(), month_) != days31.end()){
      if ((num < 1) || (num > 31)){
        str error = "День должен быть < 31 и > 1"; 
        throw error;
      }
    }
    else if (std::find(days30.begin(), days30.end(), month_) != days30.end()){
      if ((num < 1) || (num > 30)){
        str error = "День должен быть < 30 и > 1"; 
        throw error;
      }
    }
    else {
      if ((num < 1) || (num > 28)){
        str error = "День должен быть < 28 и > 1"; 
        throw error;
      }
    }
    day_ = num;
  }
  void set_hours(int num){
    if((num  < 0) || (num >23)){
      str error = "Часы должны быть < 24 и >= 0 "; 
      throw error;
    }
    hours_ = num;
  }
  void set_minutes(int num){
    if((num  < 0) || (num >59)){
      str error = "Минуты должны быть < 60 и >= 0 "; 
      throw error;
    }
    mins_ = num;
  }

  
    void add_min(int minutes) {


        if (minutes < 1) {
            str error = "Минуты должны быть > 0"; 
            throw error;
        }
        mins_ += minutes;
        if (mins_ > 59) {
            hours_ += (mins_ / 60);
            mins_ = mins_ % 60;
        }
        if (hours_ > 23) {
            day_ += hours_ / 24;
            hours_ = hours_ % 24;
        }
        switch (month_) {
        case 1:
            if (day_ > 31) {
                month_ += day_ / 31;
                day_ = day_ % 31;
            }
            break;
        case 2:
            if (day_ > 28) {
                month_ += day_ / 28;
                day_ = day_ % 28;
            }
            break;
        case 3:
            if (day_ > 31) {
                month_ += day_ / 31;
                day_ = day_ % 31;
            }
            break;
        case 4:
            if (day_ > 30) {
                month_ += day_ / 30;
                day_ = day_ % 30;
            }
            break;
        case 5:
            if (day_ > 31) {
                month_ += day_ / 31;
                day_ = day_ % 31;
            }
            break;
        case 6:
            if (day_ > 30) {
                month_ += day_ / 30;
                day_ = day_ % 30;
            }
            break;
        case 7:
            if (day_ > 31) {
                month_ += day_ / 31;
                day_ = day_ % 31;
            }
            break;
        case 8:
            if (day_ > 31) {
                month_ += day_ / 31;
                day_ = day_ % 31;
            }
            break;
        case 9:
            if (day_ > 30) {
                month_ += day_ / 30;
                day_ = day_ % 30;
            }
            break;
        case 10:
            if (day_ > 31) {
                month_ += day_ / 31;
                day_ = day_ % 31;
            }
            break;
        case 11:
            if (day_ > 30) {
                month_ += day_ / 30;
                day_ = day_ % 30;
            }
            break;
        case 12:
            if (day_ > 31) {
                month_ += day_ / 31;
                day_ = day_ % 31;
            }
            break;
        default:
            break;
        }
        if (month_ > 12) {
            year_ += month_ / 12;
            month_ = month_ % 12;
        }
    }
    int get_day_() const {
        return day_;
    }
    int get_month_() const {
        return month_;
    }
    int get_year_() const {
        return year_;
    }
    int get_hours_() const {
        return hours_;
    }
    int get_mins_() const {
        return mins_;
    }
    str get_day_of_week_() const {
        return day_of_week_;
    }
};


int main() {
    Clock clock1{ 30, 4, 2020, 23, 45, "Пятница" };
    Clock clock2{ clock1 };
    Clock clock3{};
    int n;
    do {
        std::cout << "=============" << std::endl;
        std::cout << "Меню:" << std::endl; 
        std::cout << "1. Получить день" << std::endl;
        std::cout << "2. Получить месяц" << std::endl; 
        std::cout << "3. Получить год" << std::endl; 
        std::cout << "4. Получить часы" << std::endl; 
        std::cout << "5. Получить минуты" << std::endl; 
        std::cout << "6. Получить день недели" << std::endl; 
        std::cout << "7. Установить день недели" << std::endl; 
        std::cout << "8. Добавить минуты" << std::endl;
        std::cout << "9. Вывести информацию" << std::endl;
    std::cout << "10. Установить месяц" << std::endl; 
    std::cout << "11. Установить день" << std::endl; 
    std::cout << "12. Установить часы" << std::endl; 
    std::cout << "13. Установить минуты" << std::endl;
    std::cout << "14. Установить год" << std::endl; 
        std::cout << "=============" << std::endl;
        std::cout << "Что вы хотите сделать?" << std::endl;
        std::cin >> n;
        int day_of_week;
        int minutes;
    int num;
        switch (n) {
        case 1:
            std::cout << clock1.get_day_() << std::endl;
            break;

        case 2:
            std::cout << clock1.get_month_() << std::endl;
            break;


        case 3:
            std::cout << clock1.get_year_() << std::endl;
            break;

        case 4:
            std::cout << clock1.get_hours_() << std::endl;
            break;

        case 5:
            std::cout << clock1.get_mins_() << std::endl;
            break;

        case 6:
            std::cout << clock1.get_day_of_week_() << std::endl;
            break;

        case 7:
            std::cout << "=============" << std::endl;
            std::cout << "1. Понедельник" << std::endl;
            std::cout << "2. Вторник" << std::endl;
            std::cout << "3. Среда" << std::endl; 
            std::cout << "4. Четверг" << std::endl; 
            std::cout << "5. Пятница" << std::endl;
            std::cout << "6. Суббота" << std::endl;
            std::cout << "7. Воскресенье" << std::endl;
            std::cout << "=============" << std::endl;
            std::cout << "Введите номер дня недели:" << std::endl;
            std::cin >> day_of_week;
            if ((day_of_week < 1) || (day_of_week > 7)) {
                std::cout << "Неверный номер дня недели" << std::endl;
                break;
            }
            else {
                clock1.set_day_of_week(day_of_week);
            }
            break;

        case 8:
            std::cout << "Введите минуты: " << std::endl;
            std::cin >> minutes;
            try {
                clock1.add_min(minutes);
            }
            catch (str error) {
                std::cerr << error << std::endl;
            }
            break;
        case 9:
            clock1.print_info();
            break;
    case 10:
      std::cout << "Введите месяц (номер): " << std::endl;
            std::cin >> num;
            try {
                clock1.set_month(num);
            }
            catch (str error) {
                std::cerr << error << std::endl;
            }
            break;
    case 11:
      std::cout << "Введите день: " << std::endl; 
            std::cin >> num;
            try {
                clock1.set_day(num);
            }
            catch (str error) {
                std::cerr << error << std::endl;
            }
            break;
    case 12:
      std::cout << "Введите часы: " << std::endl;
            std::cin >> num;
            try {
                clock1.set_hours(num);
            }
            catch (str error) {
                std::cerr << error << std::endl;
            }
            break;
    case 13:
      std::cout << "Введите минуты: " << std::endl; 
            std::cin >> num;
            try {
                clock1.set_minutes(num);
            }
            catch (str error) {
                std::cerr << error << std::endl;
            }
            break;
    case 14:
      std::cout << "Введите год: " << std::endl;
            std::cin >> num;
      clock1.set_year(num);
      break;
        default:
            std::cout << "Неверное значение" << std::endl;
            break;
        }
    } while (n != 0);
    return 0;
}