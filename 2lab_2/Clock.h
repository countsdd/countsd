#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Clock {
private:
    int day_;
    int month_;
    int hours_;
    int mins_;
    string day_of_week_;
    vector<string> tasks_;
    
protected:
    int year_;
    
public:
    Clock();
    Clock(int day, int month, int year, int hours, int mins, string day_of_week, vector<string> tasks);
    Clock(const Clock &p);
    
    Clock& operator=(const Clock &other);
    
    ~Clock();
    
    Clock operator+(const Clock &other) const;
    Clock operator/(const Clock &other) const;
    
    void add_days(int days);
    void add_hours(int hours);
    void add_min(int minutes);
    
    void print_info() const;
    
    void set_day_of_week(int day_of_week1);
    void set_year(int num);
    void set_month(int num);
    void set_day(int num);
    void set_hours(int num);
    void set_minutes(int num);
    void set_tasks(const vector<string> &tasks);
    
    int get_day() const;
    int get_month() const;
    int get_year() const;
    int get_hours() const;
    int get_mins() const;
    string get_day_of_week() const;
    vector<string> get_tasks() const;
}; 
