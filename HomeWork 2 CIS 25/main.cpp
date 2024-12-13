//
//  main.cpp
//  HomeWork 2 CIS 25
//
//  Created by Juwon Hong on 12/11/24.
//

#include <iostream>
#include "DateTime.h"

int main() {
    DateTime dt(2024, 12, 11, 14, 30, 45);
    dt.addDays(1);
    dt.addSeconds(3600);
    std::cout << dt.format("Today is Y-MM-DD, and the time is HH:mm:ss") << std::endl;
    return 0;
}
