//
//  main.cpp
//  HomeWork 2 CIS 25
//
//  Created by Juwon Hong on 12/11/24.
//

// main.cpp
#include "DateTime.h"
#include <iostream>
using namespace std;

int main() {
    DateTime dt1(2024, 12, 13, 14, 30, 0);
    DateTime dt2(2025, 1, 1, 0, 0, 0);

    cout << "Initial DateTime 1: " << dt1.format("YYYY-MM-DD HH:mm:SS") << endl;
    cout << "Initial DateTime 2: " << dt2.format("YYYY-MM-DD HH:mm:SS") << endl;

    cout << "Difference in seconds: " << dt1.differenceInSeconds(dt2) << endl;

    dt1.addDays(30);
    cout << "DateTime 1 after adding 30 days: " << dt1.format("YYYY-MM-DD HH:mm:SS") << endl;

    return 0;
}
