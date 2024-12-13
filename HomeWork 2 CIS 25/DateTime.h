//
//  DateTime.h
//  HomeWork 2 CIS 25
//
//  Created by Juwon Hong on 12/11/24.
//

// DateTime.h
#ifndef DATETIME_H
#define DATETIME_H

#include "Date.h"

#include <string>
using namespace std;

class DateTime : public Date {
public:
    DateTime(int y = 0, int m = 1, int d = 1, int h = 0, int min = 0, int s = 0);

    int differenceInSeconds(const DateTime& other) const;
    string format(const string& formatString) const;
};

#endif
