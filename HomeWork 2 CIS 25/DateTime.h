//
//  DateTime.h
//  HomeWork 2 CIS 25
//
//  Created by Juwon Hong on 12/11/24.
//

// DateTime.h
#ifndef DATETIME_H
#define DATETIME_H

#include <string>
#include <sstream>
#include <iomanip>

class Time {
public:
    int hour, minute, second;

    Time(int h = 0, int m = 0, int s = 0);
    void addSeconds(int sec);
};

class Date {
public:
    int year, month, day;

    Date(int y = 1970, int m = 1, int d = 1);
    bool isLeapYear() const;
    int daysInMonth() const;
    void addDays(int days);
};

class DateTime {
public:
    Date date;
    Time time;

    DateTime(int y = 1970, int m = 1, int d = 1, int h = 0, int min = 0, int sec = 0);
    void addSeconds(int sec);
    void addMinutes(int min);
    void addHours(int hrs);
    void addDays(int days);
    std::string format(const std::string& formatString) const;
};

#endif 
