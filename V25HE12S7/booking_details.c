
#include <stdio.h>
#include "reservation.h"

void booking_details(void)
{
    int train_number, journey_date, no_of_seats;
    int seat_number, i;
    int file_train_number, file_journey_date, file_seat_number;
    char passenger_name[50];
    int age;
    char gender;
    int found;
    FILE *fp;

    printf("\nBOOKING DETAILS\n");
    printf("Enter train number: ");
    scanf("%d", &train_number);

    printf("Enter journey date (DD-MM-YYYY): ");
    scanf("%d", &journey_date);

    printf("Enter number of seats to check: ");
    scanf("%d", &no_of_seats);

    if (no_of_seats <= 0) {
        printf("Invalid number of seats.\n");
        return;
    }

    fp = fopen("passenger_info", "r");
    if (fp == NULL) {
        printf("No passenger booking information found.\n");
        return;
    }

    for (i = 0; i < no_of_seats; i++) {
        printf("Enter seat number: ");
        scanf("%d", &seat_number);

        found = 0;
        rewind(fp);

        while (fscanf(fp, "%d %d %d %s %d %c",&file_train_number, &file_journey_date,&file_seat_number, passenger_name,&age, &gender) == 6) 
	{
            if (file_train_number == train_number && file_journey_date == journey_date && file_seat_number == seat_number) 
	    {
                printf("\nTrain Number : %d\n", file_train_number);
                printf("Journey Date : %d\n", file_journey_date);
                printf("Seat Number  : %d\n", file_seat_number);
                printf("Passenger    : %s\n", passenger_name);
                printf("Age          : %d\n", age);
                printf("Gender       : %c\n", gender);
                found = 1;
                break;
            }
        }

        if (!found)
            printf("waiting_list %d.\n", seat_number);
    }

    fclose(fp);
}

