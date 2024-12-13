//
//  DateTime.cpp
//  HomeWork 2 CIS 25
//
//  Created by Juwon Hong on 12/11/24.
//

#include "DateTime.h"
#include <sstream>
#include <iomanip>
#include <cmath>

DateTime::DateTime(int y, int m, int d, int h, int min, int s) : Date(y, m, d, h, min, s) {}

int DateTime::differenceInSeconds(const DateTime& other) const {
    int days1 = year * 365 + day;
    int days2 = other.year * 365 + other.day;

    for (int i = 0; i < month - 1; i++)
        days1 += daysInMonth(year, i + 1);
    for (int i = 0; i < other.month - 1; i++)
        days2 += daysInMonth(other.year, i + 1);

    int diffDays = abs(days1 - days2);
    int diffSeconds = diffDays * 24 * 60 * 60;

    int totalSec1 = hour * 3600 + minute * 60 + second;
    int totalSec2 = other.hour * 3600 + other.minute * 60 + other.second;

    return diffSeconds + abs(totalSec1 - totalSec2);
}

string DateTime::format(const string& formatString) const {
    stringstream ss;
    for (size_t i = 0; i < formatString.size(); i++) {
        if (formatString[i] == 'Y' && i + 3 < formatString.size() &&
            formatString.substr(i, 4) == "YYYY") {
            ss << setw(4) << setfill('0') << year;
            i += 3;
        } else if (formatString[i] == 'M' && i + 1 < formatString.size() &&
                   formatString.substr(i, 2) == "MM") {
            ss << setw(2) << setfill('0') << month;
            i += 1;
        } else if (formatString[i] == 'D' && i + 1 < formatString.size() &&
                           formatString.substr(i, 2) == "DD") {
                    ss << setw(2) << setfill('0') << day;
                    i += 1;
                } else if (formatString[i] == 'H' && i + 1 < formatString.size() &&
                           formatString.substr(i, 2) == "HH") {
                    ss << setw(2) << setfill('0') << hour;
                    i += 1;
                } else if (formatString[i] == 'm' && i + 1 < formatString.size() &&
                           formatString.substr(i, 2) == "mm") {
                    ss << setw(2) << setfill('0') << minute;
                    i += 1;
                } else if (formatString[i] == 'S' && i + 1 < formatString.size() &&
                           formatString.substr(i, 2) == "SS") {
                    ss << setw(2) << setfill('0') << second;
                    i += 1;
                } else {
                    ss << formatString[i];
                }
            }
            return ss.str();
        }
