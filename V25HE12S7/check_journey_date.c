
#include <time.h>
#include "reservation.h"

int check_journey_date(int journey_date)
{
    int day = journey_date / 1000000;
    int month = (journey_date / 10000) % 100;
    int year = journey_date % 10000;

    time_t now, journey_time, today_time;
    struct tm today, journey = {0};
    double difference;

    if (day < 1 || day > 31 ||
        month < 1 || month > 12 || year < 1000)
        return 0;

    time(&now);
    today = *localtime(&now);

    today.tm_hour = 0;
    today.tm_min = 0;
    today.tm_sec = 0;
    today.tm_isdst = -1;

    journey.tm_year = year - 1900;
    journey.tm_mon = month - 1;
    journey.tm_mday = day;
    journey.tm_isdst = -1;

    journey_time = mktime(&journey);
    today_time = mktime(&today);

    if (journey_time == (time_t)-1 || today_time == (time_t)-1)
        return 0;

    /* Reject invalid dates normalized by mktime. */
    if (journey.tm_mday != day ||
        journey.tm_mon != month - 1 ||
        journey.tm_year != year - 1900)
        return 0;

    difference = difftime(journey_time, today_time) / 86400.0;

    return difference >= 0 && difference <= 3;
}

