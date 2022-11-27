#include <iostream>
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include <string>

int minutesSinceMidnight(Time time){
    return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later){
    return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

Time addMinutes(Time time0, int min){
    min = min + minutesSinceMidnight(time0);
    int hours = min / 60;
    min = min % 60;
    return {hours, min};
}

std::string getMovieGenre(Movie mv)
{
    std::string g;
    switch (mv.genre)
    {
    case ACTION:
        g = "ACTION";
        break;
    case COMEDY:
        g = "COMEDY";
        break;
    case DRAMA:
        g = "DRAMA";
        break;
    case ROMANCE:
        g = "ROMANCE";
        break;
    case THRILLER:
        g = "THRILLER";
        break;
    }
    return g;
}

std::string timeToString(Time t){
    std::string output = "";
    output+= std::to_string(t.h) + ":";
    if(t.m < 10){
        output += "0";
    }
    output += std::to_string(t.m);
    return output;
}

std::string getTimeSlot(TimeSlot ts){
    std::string output = "";
    output += ts.movie.title + " ";
    output += getMovieGenre(ts.movie);
    output += " (" + std::to_string(ts.movie.duration) + " min) ";
    output += "[starts at " + timeToString(ts.startTime) + ", ends by " + timeToString(addMinutes(ts.startTime,ts.movie.duration)) + "]";

    return output;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot next = {nextMovie,addMinutes(ts.startTime,ts.movie.duration)};
    return next;
}