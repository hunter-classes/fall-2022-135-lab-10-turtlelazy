#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

TEST_CASE("TASK A"){
    CHECK(minutesSinceMidnight({10,30}) == 630);
    CHECK(minutesSinceMidnight({7, 0}) == 420);
    CHECK(minutesSinceMidnight({0, 41}) == 41);

    CHECK(minutesUntil({10, 30}, {13, 40}) == 190);
    CHECK(minutesUntil({8, 30}, {13, 40}) == 310);
    CHECK(minutesUntil({0, 0}, {0, 0}) == 0);
    CHECK(minutesUntil({13, 40}, {8, 30}) == -310);
}

TEST_CASE("TASK B"){
    Time test = addMinutes({8, 10}, 75);
    CHECK( (test.h == 9 && test.m == 25 ) );
    test = addMinutes({0, 0}, 121);
    CHECK((test.h == 2 && test.m == 1));
    test = addMinutes({2, 1}, -121);
    CHECK((test.h == 0 && test.m == 0));
}

TEST_CASE("TASK C"){
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot evening = {movie2, {16, 45}};

    std::string test1 = "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]";
    std::string test2 = "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]";
    std::string test3 = "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]";
    CHECK(getTimeSlot(morning) == test1);
    CHECK(getTimeSlot(daytime) == test2);
    CHECK(getTimeSlot(evening) == test3);
}

TEST_CASE("TASK D")
{
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot evening = {movie2, {16, 45}};

    TimeSlot morningNext = scheduleAfter(morning,movie1);
    TimeSlot daytimeNext = scheduleAfter(daytime, movie2);
    TimeSlot eveningNext = scheduleAfter(evening, movie2);

    TimeSlot morningNextTest = {movie1,{11,11}};
    TimeSlot daytimeNextTest = {movie2,{14,29}};
    TimeSlot eveningNextTest = {movie2,{18,59}};

    CHECK(getTimeSlot(morningNext) == getTimeSlot(morningNextTest));
    CHECK(getTimeSlot(daytimeNext) == getTimeSlot(daytimeNextTest));
    CHECK(getTimeSlot(eveningNext) == getTimeSlot(eveningNextTest));
}

TEST_CASE("TASK E"){
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot evening = {movie2, {16, 45}};

    TimeSlot morningOverlapTest = {movie1, {8, 15}};
    TimeSlot daytimeOverlapTest = {movie2, {8, 15}};
    TimeSlot eveningOverlapTest = {movie2, {14, 31}};
    CHECK((timeOverlap(morning,morningOverlapTest)) == true);
    CHECK((timeOverlap(morningOverlapTest, morning) == true));

    CHECK((timeOverlap(evening, eveningOverlapTest) == false));
    CHECK((timeOverlap(eveningOverlapTest, evening) == false));

    CHECK((timeOverlap(daytime, daytimeOverlapTest) == false));
    CHECK((timeOverlap(daytimeOverlapTest, daytime) == false));
}