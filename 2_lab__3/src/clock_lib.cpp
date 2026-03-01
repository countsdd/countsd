#include "../include/clock_lib.hpp"
#include "../Clock.hpp" 
#include <algorithm>

// реализация Battery

Battery::Battery() : currentCharge(100), maxCharge(100) {
    cout << "Конструктор Battery по умолчанию" << endl;
}

Battery::Battery(int current, int max) : currentCharge(current), maxCharge(max) {
    if (currentCharge > maxCharge) currentCharge = maxCharge;
    if (currentCharge < 0) currentCharge = 0;
    cout << "Параметризованный конструктор Battery" << endl;
}

Battery::Battery(const Battery &other) 
    : currentCharge(other.currentCharge), maxCharge(other.maxCharge) {
    cout << "Конструктор копирования Battery" << endl;
}

void Battery::setCharge(int charge) {
    if (charge < 0) charge = 0;
    if (charge > maxCharge) charge = maxCharge;
    currentCharge = charge;
}

void Battery::setMaxCharge(int max) {
    if (max < 0) max = 0;
    maxCharge = max;
    if (currentCharge > maxCharge) currentCharge = maxCharge;
}

int Battery::getCurrentCharge() const {
    return currentCharge;
}

int Battery::getMaxCharge() const {
    return maxCharge;
}

void Battery::discharge(int amount) {
    if (amount < 0) return;
    currentCharge -= amount;
    if (currentCharge < 0) currentCharge = 0;
    cout << "Батарейка разряжена на " << amount << " ед. Текущий заряд: " 
         << currentCharge << "/" << maxCharge << endl;
}

void Battery::charge(int amount) {
    if (amount < 0) return;
    currentCharge += amount;
    if (currentCharge > maxCharge) currentCharge = maxCharge;
    cout << "Батарейка заряжена на " << amount << " ед. Текущий заряд: " 
         << currentCharge << "/" << maxCharge << endl;
}

void Battery::printInfo() const {
    cout << "Батарейка: заряд " << currentCharge << "/" << maxCharge << endl;
}

// реализация Workshop

Workshop::Workshop() : address_("Неизвестный адрес") {
    cout << "Конструктор Workshop по умолчанию" << endl;
}

Workshop::Workshop(string address) : address_(address) {
    cout << "Параметризованный конструктор Workshop" << endl;
}

Workshop::Workshop(const Workshop &other) : address_(other.address_) {
    
    clocksInWork_ = other.clocksInWork_;
    cout << "Конструктор копирования Workshop" << endl;
}

Workshop::~Workshop() {
    
    clocksInWork_.clear();
    cout << "Деструктор Workshop" << endl;
}

Workshop& Workshop::operator=(const Workshop &other) {
    if (this != &other) {
        address_ = other.address_;
        clocksInWork_ = other.clocksInWork_;
        cout << "Оператор присваивания Workshop" << endl;
    }
    return *this;
}

void Workshop::setAddress(string address) {
    address_ = address;
}

string Workshop::getAddress() const {
    return address_;
}

void Workshop::addClock(Clock* clock) {
    if (clock != nullptr) {
        clocksInWork_.push_back(clock);
        cout << "Часы добавлены в мастерскую" << endl;
    }
}

void Workshop::removeClock(Clock* clock) {
    auto it = find(clocksInWork_.begin(), clocksInWork_.end(), clock);
    if (it != clocksInWork_.end()) {
        clocksInWork_.erase(it);
        cout << "Часы удалены из мастерской" << endl;
    }
}

void Workshop::printClocks() const {
    if (clocksInWork_.empty()) {
        cout << "В мастерской нет часов в работе" << endl;
        return;
    }
    
    cout << "Часы в работе (" << clocksInWork_.size() << " шт.):" << endl;
    for (size_t i = 0; i < clocksInWork_.size(); i++) {
        cout << i + 1 << ". ";
        if (clocksInWork_[i] != nullptr) {
            cout << "Часы с датой " << clocksInWork_[i]->get_day() << "."
                 << clocksInWork_[i]->get_month() << "."
                 << clocksInWork_[i]->get_year();
        } else {
            cout << "nullptr";
        }
        cout << endl;
    }
}

void Workshop::replaceBattery(Clock* clock, int newCurrent, int newMax) {
    if (clock == nullptr) {
        cout << "Ошибка: часы не найдены" << endl;
        return;
    }
    
    auto it = find(clocksInWork_.begin(), clocksInWork_.end(), clock);
    if (it == clocksInWork_.end()) {
        cout << "Ошибка: эти часы не в работе в данной мастерской" << endl;
        return;
    }
    
    
    clock->set_battery(newCurrent, newMax);
    cout << "Батарейка успешно заменена! Новый заряд: " 
         << newCurrent << "/" << newMax << endl;
}

void Workshop::printInfo() const {
    cout << "========== МАСТЕРСКАЯ ==========" << endl;
    cout << "Адрес: " << address_ << endl;
    printClocks();
    cout << "================================" << endl;
}