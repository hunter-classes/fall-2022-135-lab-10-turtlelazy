#include <iostream>
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

int main()
{
    std::cout << "Minutes since midnight for 13:40 is " << minutesSinceMidnight({13,40}) << "\n";
    std::cout << "Minutes until 13:40 from 10:30 is " << minutesUntil( {10, 30}, {13, 40} ) << "\n";
    Time added = addMinutes({8, 10}, 75);
    std::cout << "75 Minutes added to 8:10 is " << added.h << ":" << added.m << "\n";
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    TimeSlot morning = {movie1, {9, 15}};
    std::cout << getTimeSlot(morning) << "\n";
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot next = scheduleAfter(morning,movie2);
    std::cout << getTimeSlot(next) << "\n";
    Movie movie3 = {"One Piece", ACTION, 116};
    TimeSlot inbetween = {movie3, {12, 15}};
    std::cout << getTimeSlot(inbetween) << "\n";

    std::cout << "The previous two movies overlap: " << timeOverlap(next,inbetween) << "\n";
    return 0;
}