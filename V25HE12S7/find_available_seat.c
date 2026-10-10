
#include <stdio.h>
#include "reservation.h"

int find_available_seat(int train_number,
                        int journey_date,
                        int total_seats)
{
    FILE *fp;
    int file_train_number, file_journey_date, booked_seat;
    char passenger_name[50];
    int age;
    char gender;
    int seat_number, seat_booked;

    for (seat_number = 1; seat_number <= total_seats; seat_number++)
    {
        seat_booked = 0;
        fp = fopen("passenger_info", "r");

        if (fp == NULL)
            return seat_number;

        while (fscanf(fp, "%d %d %d %49s %d %c",&file_train_number, &file_journey_date, &booked_seat, passenger_name,&age, &gender) == 6)
       	{
            if (file_train_number == train_number && file_journey_date == journey_date && booked_seat == seat_number)
	    {
                seat_booked = 1;
                break;
            }
        }

        fclose(fp);

        if (!seat_booked)
            return seat_number;
    }

    return 0;
}

