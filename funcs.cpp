#include <iostream>
#include "funcs.h"
#include "time.h"

int minutesSinceMidnight(Time time){
    return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later){
    return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

Time addMinutes(Time time0, int min){
    int hours = min / 60;
    min = min % 60;
    return {time0.h + hours, time0.m + min};
}