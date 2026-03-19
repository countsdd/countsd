#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Clock;

struct Battery {
private:
    int currentCharge;
    int maxCharge;

public:
    
    Battery();
    Battery(int current, int max);
    Battery(const Battery &other);

    
    void setCharge(int charge);
    void setMaxCharge(int max);
    int getCurrentCharge() const;
    int getMaxCharge() const;
    
    void discharge(int amount);  
    void charge(int amount);      
    
    void printInfo() const;
};

class Workshop {
private:
    string address_;
    vector<Clock*> clocksInWork_; 

public:
    
    Workshop();
    Workshop(string address);
    Workshop(const Workshop &other);
    
    ~Workshop();
    
    Workshop& operator=(const Workshop &other);
    
    void setAddress(string address);
    string getAddress() const;
    
    void addClock(Clock* clock);           
    void removeClock(Clock* clock);        
    void printClocks() const;               
    
    void replaceBattery(Clock* clock, int newCurrent, int newMax);
    
    void printInfo() const;
};