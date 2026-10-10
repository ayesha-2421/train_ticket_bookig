
#include <stdio.h>
#include "reservation.h"

void cancel_ticket(void)
{
    int train_number, journey_date, no_of_seats;
    int seat_number, i;
    int file_train_number, file_journey_date, file_seat_number;
    char passenger_name[50];
    int age;
    char gender;
    int found;

    FILE *fp;
    FILE *temp_fp;

    printf("\nCANCEL TICKET\n");

    printf("Enter train number: ");
    scanf("%d", &train_number);

    printf("Enter journey date (DD-MM-YYYY): ");
    scanf("%d", &journey_date);

    printf("Enter number of seats to cancel: ");
    scanf("%d", &no_of_seats);

    if (no_of_seats <= 0)
    {
        printf("Invalid number of seats.\n");
        return;
    }

    for (i = 0; i < no_of_seats; i++)
    {
        printf("Enter seat number to cancel: ");
        scanf("%d", &seat_number);
        fp = fopen("passenger_info", "r");
        if (fp == NULL) 
	{
            printf("No passenger booking information found.\n");
            return;
        }

        temp_fp = fopen("temp_passenger_info", "w");

        if (temp_fp == NULL) 
	{
            printf("Error creating temporary file.\n");
            fclose(fp);
            return;
        }

        found = 0;

        while (fscanf(fp, "%d %d %d %s %d %c",&file_train_number,&file_journey_date,&file_seat_number, passenger_name,&age, &gender) == 6)
       	{

            if (file_train_number == train_number && file_journey_date == journey_date && file_seat_number == seat_number)
	    {
                found = 1;
            } 
	    else 
	    {
                fprintf(temp_fp, "%d %d %d %s %d %c\n",file_train_number, file_journey_date, file_seat_number, passenger_name, age, gender);
            }
        }

        fclose(fp);
        fclose(temp_fp);

	if (found)
       	{
       		 if (remove("passenger_info") != 0) 
		{
            	printf("Error updating passenger information.\n");
            	remove("temp_passenger_info");
            	return;
       		}

        		if (rename("temp_passenger_info", "passenger_info") != 0) 
			{	
            			printf("Error restoring passenger information file.\n");
            			return;
        		}

        printf("Seat %d cancelled successfully.\n", seat_number);
       }
       else
       {
        remove("temp_passenger_info");
        printf("Seat %d booking not found.\n", seat_number);
       }
   }

   printf("\nTicket cancellation completed.\n");

}
