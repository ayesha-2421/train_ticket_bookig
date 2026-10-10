#include <stdio.h>
#include "login.h"
#include "train.h"
#include "reservation.h"
int main()
{
    int choice;

    printf("\n");
    printf("MENU-1\n");
    printf("1: sign-up (to create new login)\n");
    printf("2: sign-in (to login existing users)\n");
    printf("\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        sign_up();
    }
    else if (choice == 2)
    {
       sign_in();
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}
void menu2()
{
    char choice;

    while (1)
    {
        printf("\n");
        printf("MENU-2\n");
        printf("R/r : Reserve ticket\n");
        printf("C/c : Cancel ticket\n");
        printf("B/b : Booking details\n");
        printf("Q/q : Quit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == 'R' || choice == 'r')
        {
            printf("Reserve ticket.\n");
	    display_trains();
	    reserve_ticket();
        }
        else if (choice == 'C' || choice == 'c')
        {
            printf("Cancel ticket\n");
	    display_trains();
	    cancel_ticket();
        }
        else if (choice == 'B' || choice == 'b')
        {
            printf("Booking details.\n");
	    booking_details();
        }
        else if (choice == 'Q' || choice == 'q')
        {
            printf("Thank you.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }
}
