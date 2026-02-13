#include "Clock.h"
#include <ctime>

Clock::Clock() {
    day_ = 1;
    month_ = 1;
    year_ = 2000;
    hours_ = 0;
    mins_ = 0;
    day_of_week_ = "Суббота";
    tasks_ = {};
    cerr << "конструктор по умолчанию" << endl;
}

Clock::Clock(int day, int month, int year, int hours, int mins, string day_of_week, vector<string> tasks) 
    : day_(day), month_(month), year_(year), hours_(hours), mins_(mins), 
      day_of_week_(day_of_week), tasks_(tasks) {
    cerr << "параметризованный конструктор" << endl;
}

Clock::Clock(const Clock &p) 
    : day_(p.day_), month_(p.month_), year_(p.year_), 
      hours_(p.hours_), mins_(p.mins_), day_of_week_(p.day_of_week_),
      tasks_(p.tasks_) {
    cerr << "конструктор копирования" << endl;
}

Clock& Clock::operator=(const Clock &other) {
    if (this != &other) {
        day_ = other.day_;
        month_ = other.month_;
        year_ = other.year_;
        hours_ = other.hours_;
        mins_ = other.mins_;
        day_of_week_ = other.day_of_week_;
        
        vector<string> tmp = other.tasks_;
        tasks_ = tmp;
        tmp.clear();
        
        cerr << "оператор присваивания" << endl;
    }
    return *this;
}

Clock::~Clock() {
    tasks_.clear();
    cerr << "деструктор" << endl;
}

Clock Clock::operator+(const Clock &other) const {
    Clock result;
    
    if (year_ > other.year_) {
        result = *this;
    } else if (year_ < other.year_) {
        result = other;
    } else if (month_ > other.month_) {
        result = *this;
    } else if (month_ < other.month_) {
        result = other;
    } else if (day_ > other.day_) {
        result = *this;
    } else if (day_ < other.day_) {
        result = other;
    } else {
        result = *this;
    }
    
    result.add_days(7);
    result.add_hours(1);
    
    vector<string> new_tasks;
    
    for (int i = 0; i < tasks_.size(); i++) {
        bool already_exists = false;
        
        for (int j = 0; j < new_tasks.size(); j++) {
            if (new_tasks[j] == tasks_[i]) {
                already_exists = true;
                break;
            }
        }
        
        if (!already_exists) {
            new_tasks.push_back(tasks_[i]);
        }
    }
    
    for (int i = 0; i < other.tasks_.size(); i++) {
        bool already_exists = false;
        
        for (int j = 0; j < new_tasks.size(); j++) {
            if (new_tasks[j] == other.tasks_[i]) {
                already_exists = true;
                break;
            }
        }
        
        if (!already_exists) {
            new_tasks.push_back(other.tasks_[i]);
        }
    }
    
    result.tasks_ = new_tasks;
    
    return result;
}

Clock Clock::operator/(const Clock &other) const {
    Clock result;
    
    if (year_ < other.year_) {
        result = *this;
    } else if (year_ > other.year_) {
        result = other;
    } else if (month_ < other.month_) {
        result = *this;
    } else if (month_ > other.month_) {
        result = other;
    } else if (day_ < other.day_) {
        result = *this;
    } else if (day_ > other.day_) {
        result = other;
    } else {
        result = *this;
    }
    
    result.add_days(3);
    
    srand(time(0));
    
    int count1;
    if (tasks_.size() == 0) {
        count1 = 0;
    } else {
        count1 = rand() % (tasks_.size() + 1);
    }
    
    int count2;
    if (other.tasks_.size() == 0) {
        count2 = 0;
    } else {
        count2 = rand() % (other.tasks_.size() + 1);
    }
    
    cout << "Будет взято " << count1 << " дел из первого и " << count2 << " дел из второго" << endl;
    
    vector<string> new_tasks;
    
    for (int i = 0; i < count1 && i < tasks_.size(); i++) {
        bool already_exists = false;
        
        for (int j = 0; j < new_tasks.size(); j++) {
            if (new_tasks[j] == tasks_[i]) {
                already_exists = true;
                break;
            }
        }
        
        if (!already_exists) {
            new_tasks.push_back(tasks_[i]);
        }
    }
    
    for (int i = 0; i < count2 && i < other.tasks_.size(); i++) {
        bool already_exists = false;
        
        for (int j = 0; j < new_tasks.size(); j++) {
            if (new_tasks[j] == other.tasks_[i]) {
                already_exists = true;
                break;
            }
        }
        
        if (!already_exists) {
            new_tasks.push_back(other.tasks_[i]);
        }
    }
    
    result.tasks_ = new_tasks;
    
    return result;
}

void Clock::add_days(int days) {
    day_ += days;
    
    while (true) {
        int days_in_month;
        if (month_ == 2) {
            days_in_month = 28;
        } else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {
            days_in_month = 30;
        } else {
            days_in_month = 31;
        }
        
        if (day_ > days_in_month) {
            day_ -= days_in_month;
            month_++;
            if (month_ > 12) {
                month_ = 1;
                year_++;
            }
        } else {
            break;
        }
    }
}

void Clock::add_hours(int hours) {
    hours_ += hours;
    if (hours_ > 23) {
        int extra_days = hours_ / 24;
        hours_ = hours_ % 24;
        add_days(extra_days);
    }
}

void Clock::add_min(int minutes) {
    if (minutes < 1) {
        string error = "Минуты должны быть > 0"; 
        throw error;
    }
    
    mins_ += minutes;
    int extra_hours = mins_ / 60;
    mins_ = mins_ % 60;
    
    if (extra_hours > 0) {
        add_hours(extra_hours);
    }
}

void Clock::print_info() const {
    cout << "=============" << endl;
    cout << "Дата: " << day_ << "." << month_ << "." << year_ << endl; 
    cout << "Время: " << hours_ << ":" << (mins_ < 10 ? "0" : "") << mins_ << endl;
    cout << "День недели: " << day_of_week_ << endl;
    cout << "Дела: ";
    if (tasks_.empty()) {
        cout << "нет дел";
    } else {
        cout << "(";
        for (int i = 0; i < tasks_.size(); i++) {
            cout << "\"" << tasks_[i] << "\"";
            if (i < tasks_.size() - 1) cout << ", ";
        }
        cout << ")";
    }
    cout << endl;
    cout << "=============" << endl;
}

void Clock::set_day_of_week(int day_of_week1) {
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
        cout << "Неверное значение" << endl;
        break;
    }
}

void Clock::set_year(int num) {
    year_ = num;
}

void Clock::set_month(int num) {
    if((num < 1) || (num > 12)) {
        string error = "Месяц должен быть от 1 до 12";
        throw error;
    }
    month_ = num;
}

void Clock::set_day(int num) {
    if (month_ == 2) {
        if ((num < 1) || (num > 28)) {
            string error = "День должен быть от 1 до 28 для февраля"; 
            throw error;
        }
    }
    else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {
        if ((num < 1) || (num > 30)) {
            string error = "День должен быть от 1 до 30 для этого месяца"; 
            throw error;
        }
    }
    else {
        if ((num < 1) || (num > 31)) {
            string error = "День должен быть от 1 до 31 для этого месяца"; 
            throw error;
        }
    }
    day_ = num;
}

void Clock::set_hours(int num) {
    if((num < 0) || (num > 23)) {
        string error = "Часы должны быть от 0 до 23"; 
        throw error;
    }
    hours_ = num;
}

void Clock::set_minutes(int num) {
    if((num < 0) || (num > 59)) {
        string error = "Минуты должны быть от 0 до 59"; 
        throw error;
    }
    mins_ = num;
}

void Clock::set_tasks(const vector<string> &tasks) {
    tasks_ = tasks;
}

int Clock::get_day() const {
    return day_;
}

int Clock::get_month() const {
    return month_;
}

int Clock::get_year() const {
    return year_;
}

int Clock::get_hours() const {
    return hours_;
}

int Clock::get_mins() const {
    return mins_;
}

string Clock::get_day_of_week() const {
    return day_of_week_;
}

vector<string> Clock::get_tasks() const {
    return tasks_;
}