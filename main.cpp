#include <iostream>
#include "funcs.h"
#include "time.h"
int main()
{
    std::cout << "Minutes since midnight for 13:40 is " << minutesSinceMidnight({13,40}) << "\n";
    std::cout << "Minutes until 13:40 from 10:30 is " << minutesUntil( {10, 30}, {13, 40} ) << "\n";
    Time added = addMinutes({8, 10}, 75);
    std::cout << "75 Minutes added to 8:10 is " << added.h << ":" << added.m << "\n";
    return 0;
}