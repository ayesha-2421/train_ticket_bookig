#include <stdio.h>
#include "reservation.h"
#include "structures.h"
#include<time.h>     
      
                                                          
void reserve_ticket()
{
    int train_number;
    int journey_date;
    int no_of_seats;
    int i;
    int seat_number;
    int total_seats;
    int waiting=0;
 
    Passenger passenger;
    FILE *fp;
    FILE *train_fp;
    Train train;

    printf("\n");
    printf(" RESERVE TICKET\n");

    printf("Enter train number: ");
    scanf("%d", &train_number);

    printf("Enter journey date (DDMMYYYY): ");
    scanf("%d", &journey_date);
    if (check_journey_date(journey_date) == 0)
{
    printf("Invalid journey date.\n");
    printf("Reservation is allowed only within 3 days from current date.\n");
    return;
}


    printf("Enter number of seats: ");
    scanf("%d", &no_of_seats);

    /* Find total seats of selected train */
    train_fp = fopen("train_info.txt", "r");

    if (train_fp == NULL)
    {
        printf("Error: Unable to open train_info file.\n");
        return;
    }

    total_seats = 0;

    while (fscanf(train_fp, "%d %s %s %s %d",&train.train_number, train.train_name,train.source,train.destination,&train.no_of_seats) == 5)
    {
        if (train.train_number == train_number)
        {
            total_seats = train.no_of_seats;
            break;
        }
    }

    fclose(train_fp);

    if (total_seats == 0)
    {
        printf("Invalid train number.\n");
        return;
    }
    fp = fopen("passenger_info", "a");

    if (fp == NULL)
    {
        printf("Error: Unable to open passenger_info file.\n");
        return;
    }

    for (i = 0; i < no_of_seats; i++)
    {
        seat_number = find_available_seat(train_number,journey_date,total_seats);

        if (seat_number == 0)
        {
            printf("WAITING_LIST : %d.\n",waiting+1);
            break;
        }

        printf("\nPassenger %d\n", i + 1);

        printf("Enter passenger name: ");
        scanf("%s", passenger.passenger_name);

        printf("Enter age: ");
        scanf("%d", &passenger.age);

        printf("Enter gender (M/F): ");
        scanf(" %c", &passenger.gender);

        passenger.train_number = train_number;
        passenger.journey_date = journey_date;
        passenger.seat_number = seat_number;

        fprintf(fp, "%d %d %d %s %d %c\n", passenger.train_number,passenger.journey_date,passenger.seat_number,passenger.passenger_name,passenger.age,passenger.gender);
fflush(fp);
        printf("CONFIRMED : %d\n", seat_number);
    }

    fclose(fp);

    printf("\nTicket reservation completed.\n");
}
  
      
