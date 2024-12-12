//
//  DateTime.cpp
//  HomeWork 2 CIS 25
//
//  Created by Juwon Hong on 12/11/24.
//

// DateTime.cpp
#include "DateTime.h"

Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

void Time::addSeconds(int sec) {
    second += sec;
    minute += second / 60;
    second %= 60;
    hour += minute / 60;
    minute %= 60;
    hour %= 24;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

bool Date::isLeapYear() const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth() const {
    static const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return month == 2 && isLeapYear() ? 29 : daysPerMonth[month - 1];
}

void Date::addDays(int days) {
    while (days > 0) {
        int daysLeftInMonth = daysInMonth() - day;
        if (days <= daysLeftInMonth) {
            day += days;
            return;
        } else {
            days -= (daysLeftInMonth + 1);
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
                   }
               }
           }

           DateTime::DateTime(int y, int m, int d, int h, int min, int sec) : date(y, m, d), time(h, min, sec) {}

           void DateTime::addSeconds(int sec) {
               time.addSeconds(sec);
               if (time.hour == 0 && time.minute == 0 && time.second == 0) {
                   date.addDays(1);
               }
           }

           void DateTime::addMinutes(int min) {
               addSeconds(min * 60);
           }

           void DateTime::addHours(int hrs) {
               addMinutes(hrs * 60);
           }

           void DateTime::addDays(int days) {
               date.addDays(days);
           }

           std::string DateTime::format(const std::string& formatString) const {
               std::ostringstream oss;
               for (size_t i = 0; i < formatString.size(); ++i) {
                   if (formatString[i] == 'Y') {
                       oss << date.year;
                   } else if (formatString[i] == 'M' && formatString[i + 1] == 'M') {
                       oss << std::setw(2) << std::setfill('0') << date.month;
                       ++i;
                   } else if (formatString[i] == 'D' && formatString[i + 1] == 'D') {
                       oss << std::setw(2) << std::setfill('0') << date.day;
                       ++i;
                   } else if (formatString[i] == 'H' && formatString[i + 1] == 'H') {
                       oss << std::setw(2) << std::setfill('0') << time.hour;
                       ++i;
                   } else if (formatString[i] == 'm' && formatString[i + 1] == 'm') {
                       oss << std::setw(2) << std::setfill('0') << time.minute;
                       ++i;
                   } else if (formatString[i] == 's' && formatString[i + 1] == 's') {
                       oss << std::setw(2) << std::setfill('0') << time.second;
                       ++i;
                   } else {
                       oss << formatString[i];
                   }
               }
               return oss.str();
           }
